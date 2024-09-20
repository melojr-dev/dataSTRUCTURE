class Processo:
    def __init__(self, id, name, priority, wait):
        self.id = id
        self.name = name
        self.priority = priority
        self.wait = wait
        self.next = None

class FilaDeProcessos:
    def __init__(self):
        self.head = None
        self.tail = None

    def incluir_processo(self, id, name, priority, wait):
        novo_processo = Processo(id, name, priority, wait)
        if not self.head:
            self.head = novo_processo
            self.tail = novo_processo
        else:
            self.tail.next = novo_processo
            self.tail = novo_processo
        self.incrementar_tempo_espera()

    def matar_processo_maior_espera(self):
        if not self.head:
            print("A fila está vazia.")
            return

        atual = self.head
        maior_espera = atual
        anterior = None
        anterior_maior = None

        while atual:
            if atual.wait > maior_espera.wait:
                maior_espera = atual
                anterior_maior = anterior
            anterior = atual
            atual = atual.next

        if maior_espera == self.head:
            self.head = maior_espera.next
        elif anterior_maior:
            anterior_maior.next = maior_espera.next
        else:
            self.tail = anterior_maior

        print(f"Processo {maior_espera.name} com maior tempo de espera foi removido.")

    def executar_processo(self):
        if not self.head:
            print("A fila está vazia.")
            return

        processo_executado = self.head
        self.head = self.head.next
        if not self.head:
            self.tail = None
        print(f"Processo {processo_executado.name} foi executado e removido da fila.")

    def incrementar_tempo_espera(self):
        atual = self.head
        while atual:
            atual.wait += 1
            atual = atual.next

    def imprimir_processos(self):
        if not self.head:
            print("A fila está vazia.")
            return

        atual = self.head
        while atual:
            print(f"ID: {atual.id}, Nome: {atual.name}, Prioridade: {atual.priority}, Espera: {atual.wait}")
            atual = atual.next

    def executar_processo_prioridade_alta(self):
        if not self.head:
            print("A fila está vazia.")
            return

        atual = self.head
        maior_prioridade = atual
        anterior = None
        anterior_maior = None

        while atual:
            if atual.priority > maior_prioridade.priority:
                maior_prioridade = atual
                anterior_maior = anterior
            anterior = atual
            atual = atual.next

        if maior_prioridade == self.head:
            self.head = maior_prioridade.next
        elif anterior_maior:
            anterior_maior.next = maior_prioridade.next
        else:
            self.tail = anterior_maior

        print(f"Processo de alta prioridade {maior_prioridade.name} foi executado e removido da fila.")

def menu():
    fila = FilaDeProcessos()

    while True:
        print("\nMenu:")
        print("1. Incluir novo processo")
        print("2. Matar processo com maior tempo de espera")
        print("3. Executar próximo processo")
        print("4. Executar processo de maior prioridade")
        print("5. Imprimir processos")
        print("6. Mostrar níveis de prioridade")
        print("7. Sair")
        
        escolha = input("Escolha uma opção: ")

        if escolha == '1':
            id = int(input("Digite o ID do processo: "))
            name = input("Digite o nome do processo: ")
            priority = int(input("Digite a prioridade do processo (1-5): "))
            wait = int(input("Digite o tempo de espera do processo: "))
            fila.incluir_processo(id, name, priority, wait)
        elif escolha == '2':
            fila.matar_processo_maior_espera()
        elif escolha == '3':
            fila.executar_processo()
        elif escolha == '4':
            fila.executar_processo_prioridade_alta()
        elif escolha == '5':
            fila.imprimir_processos()
        elif escolha == '6':
            print("Níveis de prioridade:")
            print("1. Baixa")
            print("2. Média")
            print("3. Alta")
            print("4. Muito Alta")
            print("5. Crítica")
        elif escolha == '7':
            break
        else:
            print("Opção inválida. Tente novamente.")

# Executa o menu
menu()