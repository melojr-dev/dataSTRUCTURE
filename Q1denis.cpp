#include <iostream>
#include <string>
#include <limits>

// Estrutura para representar um contato
struct Contato {
    std::string nome;
    int telefone;
    std::string email;
    Contato* proximo;

    Contato(std::string nome, int telefone, std::string email)
        : nome(nome), telefone(telefone), email(email), proximo(nullptr) {}
};

// Classe para gerenciar a lista de contatos
class ListaEncadeadaContatos {
private:
    Contato* cabeca;

    // Função auxiliar para validar entrada de telefone
    int validarTelefone() {
        int telefone;
        while (true) {
            std::cout << "Digite o telefone: ";
            if (std::cin >> telefone) {
                return telefone;
            }
            std::cout << "Entrada inválida. Por favor, digite um número válido." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

public:
    ListaEncadeadaContatos() : cabeca(nullptr) {}

    ~ListaEncadeadaContatos() {
        Contato* atual = cabeca;
        while (atual != nullptr) {
            Contato* temp = atual;
            atual = atual->proximo;
            delete temp;
        }
    }

    // Função para incluir um novo contato
    void incluirContato() {
        std::cout << "Digite o nome: ";
        std::string nome;
        std::cin >> nome;
        
        int telefone = validarTelefone();

        std::cout << "Digite o email: ";
        std::string email;
        std::cin >> email;

        Contato* novoContato = new Contato(nome, telefone, email);
        if (!cabeca) {
            cabeca = novoContato;
        } else {
            Contato* atual = cabeca;
            while (atual->proximo != nullptr) {
                atual = atual->proximo;
            }
            atual->proximo = novoContato;
        }
    }

    // Função para remover um contato pelo telefone
    void removerContato(int telefone) {
        if (!cabeca) {
            std::cout << "Lista vazia" << std::endl;
            return;
        }
        if (cabeca->telefone == telefone) {
            Contato* temp = cabeca;
            cabeca = cabeca->proximo;
            delete temp;
            return;
        }
        Contato* atual = cabeca;
        while (atual->proximo != nullptr) {
            if (atual->proximo->telefone == telefone) {
                Contato* temp = atual->proximo;
                atual->proximo = atual->proximo->proximo;
                delete temp;
                return;
            }
            atual = atual->proximo;
        }
        std::cout << "Contato não encontrado" << std::endl;
    }

    // Função para listar todos os contatos
    void listarContatos() {
        Contato* atual = cabeca;
        while (atual != nullptr) {
            std::cout << "Nome: " << atual->nome << std::endl;
            std::cout << "Telefone: " << atual->telefone << std::endl;
            std::cout << "Email: " << atual->email << std::endl << std::endl;
            atual = atual->proximo;
        }
    }

    // Função para pesquisar um contato pelo telefone
    void pesquisarContatoPorTelefone(int telefone) {
        Contato* atual = cabeca;
        while (atual != nullptr) {
            if (atual->telefone == telefone) {
                std::cout << "Nome: " << atual->nome << std::endl;
                std::cout << "Telefone: " << atual->telefone << std::endl;
                std::cout << "Email: " << atual->email << std::endl << std::endl;
                return;
            }
            atual = atual->proximo;
        }
        std::cout << "Contato não encontrado" << std::endl;
    }

    // Função para verificar se existem valores repetidos
    void verificarValoresRepetidos() {
        Contato* atual = cabeca;
        while (atual != nullptr) {
            Contato* proximo = atual->proximo;
            while (proximo != nullptr) {
                if (atual->telefone == proximo->telefone) {
                    std::cout << "Valor repetido encontrado: " << atual->telefone << std::endl;
                    return;
                }
                proximo = proximo->proximo;
            }
            atual = atual->proximo;
        }
        std::cout << "Não há valores repetidos" << std::endl;
    }
};

int main() {
    ListaEncadeadaContatos lista;

    int opcao;
    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Incluir um Contato" << std::endl;
        std::cout << "2. Remover um Contato pelo telefone" << std::endl;
        std::cout << "3. Listar todos os Contatos" << std::endl;
        std::cout << "4. Pesquisar um Contato pelo telefone" << std::endl;
        std::cout << "5. Verificar se existem valores repetidos" << std::endl;
        std::cout << "6. Sair do Programa" << std::endl;
        std::cout << "Digite a opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                lista.incluirContato();
                break;
            }
            case 2: {
                int telefone;
                std::cout << "Digite o telefone do contato a ser removido: ";
                std::cin >> telefone;
                lista.removerContato(telefone);
                break;
            }
            case 3: {
                lista.listarContatos();
                break;
            }
            case 4: {
                int telefone;
                std::cout << "Digite o telefone do contato a ser pesquisado: ";
                std::cin >> telefone;
                lista.pesquisarContatoPorTelefone(telefone);
                break;
            }
            case 5: {
                lista.verificarValoresRepetidos();
                break;
            }
            case 6: {
                break;
            }
            default: {
                std::cout << "Opção inválida" << std::endl;
                break;
            }
        }
    } while (opcao != 6);

    return 0;
}