#include <iostream>
#include <cstdlib> //biblioteca para limpar o terminal
#include <windows.h> //biblioteca para adicionar o sleep para poder verificar melhor as informações
using namespace std;

// declarando a variavel publicamente pois será utilizada em mais de uma função
float faturamento = 0;

// informações dos produtos
struct Produtos {
  string nome;
  float preco;
  int estoque;
};

Produtos produtos[7];

// exibição para o usuário
void listaprodutos(Produtos produtos[], int tamanho) {
  cout << "Produtos disponíveis:" << endl;
  for (int i = 0; i < tamanho; i++) {
  cout << i  << " - " << produtos[i].nome << " - R$" << produtos[i].preco << endl;
  }
  cout << "Ou digite 9 para sair. " << endl;
}

// modo usuário
void modoUsuario() {
int escolhaU = 0;

//criar um laço paraa repetir o menu do usuario até ele usar a flag 9
while (escolhaU != 9){

//limpar o terminal para não ficarem muitas informações para não confundir o usuario
  system("cls");

// exibição da lista de produtos para o usuário
  listaprodutos(produtos, 7);

  float pagamento;
  
// inputs do usuário
  cout << "Digite o código do produto que deseja comprar:" << endl;
  cin >> escolhaU;

// verificar se o cliente escolheu por sair do programa
  if (escolhaU == 9) {
    cout << "Ate logo!";
    return;
  }

// verificar se o usuário informou um código válido
  if (escolhaU < 0 && escolhaU > 6) {
    cout << "Informe um código válido!" << endl;\
    break;
  }

// verificar se o produto está disponível no estoque
  if (produtos[escolhaU].estoque == 0) {
    cout << "Produto indisponível :(" << endl;
  }

// pagamento do cliente
  cout << "Insira o valor (notas e moedas):" << endl;
  cin >> pagamento;

// verificação do valor
  float troco = 0;
  if (pagamento < produtos[escolhaU].preco) {
    cout << "Valor insuficiente para esse produto. Por favor, insira o valor "
            "correto."
         << endl;
  } else if (pagamento >= produtos[escolhaU].preco) {
// calculo do troco
    troco = pagamento - produtos[escolhaU].preco;
  }

// Exibir para o usuário a retirada do produto e do troco
  cout << "Retire o produto: " << produtos[escolhaU].nome << endl;
  cout << "Troco: R$" << troco << endl;

// decremento do produto no estoque
  produtos[escolhaU].estoque--;

// calcular o faturamento para o modo administrador
  faturamento += pagamento - troco;
  Sleep(5000);
    }
}

// funções para o modo administrador
void admAddProdutos(Produtos produtos[], int numero, int quantidade) { // para atualizar o estoque
  produtos[numero].estoque += quantidade;
  cout << "Produto reposto com sucesso!" << endl;
}

void admListaInventario(Produtos produtos[]) { // para listar e exibir inventário
  cout << "Inventário:" << endl;
  for (int i = 0; i < 7; i++) {
    cout << produtos[i].nome << ": " << produtos[i].estoque << endl;
  }
}

void admListaFaturamento(float faturamento) { // para calcular o faturamento e exibir o potencial de lucro
  float faturamentoPotencial;
  faturamentoPotencial = (20 * 3.50) + (20 * 2.50) + (10 * 2) + (20 * 7) + (20 * 5) + (20 * 5.50) + (25 * 4.50);
  cout << "Faturamento: R$" << faturamento << endl;
  cout << "Faturamento potencial: R$" << faturamentoPotencial - faturamento;
}

// modo administrador
void modoAdministrador() {
  int escolha;
  int senha; // a senha é 125636
  cout << "Olá! Por favor, informe a senha para continuar: " << endl;
  cin >> senha;

  //laço que permite que o administrador possa escolher as opções ate digitar 0, que é a flag para sair
  do {
    if (senha != 125636) {
      cout << "Senha incorreta!" << endl;
      break;
    } else { // depois de confirmar com senha que é administrador, poderá seguir em frente e selecionar a ação que desejar
      system("cls");
      cout << "Bem vindo! Selecione a opção que deseja prosseguir: " << endl;
      cout << "1 - Repor produtos " << endl;
      cout << "2 - Exibir inventário " << endl;
      cout << "3 - Listar faturamento " << endl;
      cout << "0 - Sair do Modo Administrador " << endl;
      cin >> escolha;

      switch (escolha) {
      case 1: {
        system("cls");
        int opcaoP, qtdP;
        cout << "Informe o número que representa o produto(0, 1, 2, 3, 4, 5, 6): " << endl;
        cin >> opcaoP;
        cout << "Informe a quantidade de " << produtos[opcaoP].nome << " que deseja repor: " << endl;
        cin >> qtdP;
       // chama a função que faz a reposição de produtos
        admAddProdutos(produtos, opcaoP, qtdP);
        Sleep(5000);
        break;
      }
      case 2: {
       // chama a funçao que exibe o inventário
        system("cls");
        admListaInventario(produtos);
        Sleep(5000);
        break;
      }
      case 3: {
       // chama a função que lista o faturamento
        system("cls");
        admListaFaturamento(faturamento);
        Sleep(5000);
        break;
      }
      case 0: {
       // encerra o modo administrador e volta para o inicio da escolha de maquina
        system("cls");
        cout << "Até logo! " << endl;
        Sleep(5000);
        break;
      }
      }
    }
  } while (escolha != 0);
}

int main() {
// inicio da maquina e exibição dos modos
  int opcao;

  produtos[0] = {"Refrigerante", 3.50, 20};
  produtos[1] = {"Suco", 2.50, 20};
  produtos[2] = {"Chá", 2.00, 10};
  produtos[3] = {"Lanche Natural", 7.00, 20};
  produtos[4] = {"Salgadinho Frito", 5.00, 20};
  produtos[5] = {"Salgadinho Assado", 5.50, 20};
  produtos[6] = {"Chocolate", 4.50, 25};
  
//laço para que a maquina apresente as opções e uma flag para sair do programa
  do {
    cout << "Olá! Selecione uma opção: " << endl;
    cout << "1 - Modo Administrador " << endl;
    cout << "2 - Modo Usuário " << endl;
    cout << "0 - Sair " << endl;
    cin >> opcao;

    switch (opcao) {
        case 1: {
          modoAdministrador();
        break;
        }
        case 2: {
          modoUsuario();
        break;
        }
        case 0: {
          cout << "Até logo!" << endl;
        break;
        }
      }
    } while (opcao != 0);
}
