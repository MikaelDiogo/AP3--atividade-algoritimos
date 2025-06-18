// Mikael Diogo Ferreira 2º Semestre de Análise e Desenvolvimento de Sistemas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 50


typedef struct
{
    int codigo;
    char nome[100];
    char email[100];
    int idade;
    
} Cliente;

Cliente clientes[MAX_CLIENTES];
int totalClientes = 0;

int main()
{
    int opcao;

    do
    {
        exibirMenu();
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao)
        {
        case 1:
            adicionarCliente();
            break;
        case 2:
            listarClientes();
            break;
        case 3:
            printf("Saindo do sistema...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
        printf("\nPressione Enter para continuar...");
        getchar();

    } while (opcao != 3);

    return 0;
}

void exibirMenu()
{
    system("clear || cls"); 
    printf("==================================\n");
    printf("      SISTEMA DE CADASTRO\n");
    printf("==================================\n");
    printf("1 - Adicionar Cliente\n");
    printf("2 - Listar Clientes\n");
    printf("3 - Sair\n");
    printf("==================================\n");
    printf("Escolha uma opcao: ");
}

void adicionarCliente()
{
    // Implementar a lógica de adição aqui...
    if (totalClientes >= MAX_CLIENTES){
        printf("A lista de clientes já foi preenchida.");
        }
    else {
        Cliente newC;
        
        printf("Digite o codigo de cadastro: ");
        scanf("%d", &newC.codigo);
        getchar();

        printf("Insira o nome do cliente a ser cadastrado: ");
        fgets(newC.nome, sizeof(newC.nome), stdin);
        newC.nome[strcspn(newC.nome, "\n")] = '\0';

        printf("Insira o email para cadastrar: ");
        fgets(newC.email, sizeof(newC.nome), stdin);
        newC.email[strcspn(newC.email, "\n")] = '\0';

        printf("Insira a idade a ser cadastrada: ");
        scanf("%d", &newC.idade);
        getchar();

        clientes[totalClientes] = newC;
        totalClientes++;
    }
}

void listarClientes()
{

    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado! Adicione primeiro para listar.");
    }
    else {
        printf("Lista dos Clientes: \n");
        for (int i = 0; i < totalClientes; i ++) {
            printf ("===================  Cliente %d ===================\n", i + 1);
            printf ("Codigo: %d\n", clientes[i].codigo);
            printf ("Nome: %s\n", clientes[i].nome);
            printf ("Email: %s\n", clientes[i].email);
            printf ("Idade: %d\n", clientes[i].idade);
        }
    }
}
