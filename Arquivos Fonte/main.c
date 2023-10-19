#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#define tamanho 200 //declarando valores para variável:

//DECLARANDO VARIAVEIS:

//função cadastro
typedef struct cadastro CADASTRO;
struct cadastro {
char nome_paciente[tamanho][30];
char email[tamanho][30];
char cpf[tamanho][12]; //int --> número.
char telefone[tamanho][16];
char data_nascimento[tamanho][10];
char data_diagnostico[tamanho][10]; //char --> caractere.
char endereco[tamanho][50];
char cidade[20];
char comorbidade[30];
};
int opc_comorbidade;

//função login
typedef  struct log LOGIN;
struct log {
char nome_usuario[12];
char senha_usuario[12];
};
char login[12] = "admin";
char senha[12] = "admin";


int main(void){
    //para permitir usar letras com acentos e caractere especial
    setlocale (LC_ALL, "Portuguese");
    //inicia função (na ordem que está apresentada)
    funcao_apresentacao();
    funcao_login();
    funcao_menu();
    //funcao_cadastro();
    //funcao_listar ();
}

void funcao_apresentacao(){
 printf ("\n    ***************************************************");
 printf ("\n   **          -SISTEMA DE CADASTRO DE PACIENTES-     **");
 printf ("\n   **     Sistema desenvolvido por: Gabriela Rebeca   **\n");
 printf ("    ***************************************************\n");
}

void funcao_login(){
LOGIN log;

    //Descrição Tela
    printf ("\n       *******************");
    printf ("\n       **     LOGIN     **");
    printf ("\n       *******************\n");

    fflush(stdin);
    printf("\n    Digite Seu Usuário: ");
    scanf("%s", &log.nome_usuario);

    fflush(stdin);
    printf("\n    Digite Sua Senha: ");
    scanf("%s", &log.senha_usuario);


    if (strcmp(login, log.nome_usuario)==0 && strcmp(senha, log.senha_usuario)==0){
        printf("\n\n   BEM VINDO USUÁRIO!");
        printf ("\n   Digite enter para ir até o menu principal -> ");
        getch();
        return 1;
    }else {
        printf("\n   USUÁRIO INVÁLIDO!");
        printf ("\n   Digite enter para fazer o login novamente -> ");
        getch();
        system ("cls");
        funcao_apresentacao();
        funcao_login();
    }
}

void funcao_menu(){
system ("cls");

int op;

do{
    system ("cls");
    funcao_apresentacao();
    printf ("\n       *******************");
    printf ("\n       **      MENU     **");
    printf ("\n       *******************\n\n");

    printf ("   1- Cadastrar Novo Paciente \n");
    printf ("   2- Pesquisar Pacientes \n");
    printf ("   3- Listar Pacientes \n");
    printf ("   4- Excluir Cadastro \n");
    printf ("   5- Sair do Sistema");
    printf ("\n\n   Escolha uma opção: ");
    scanf ("%d", &op);

    switch (op){
        case 1:
            funcao_cadastro();
        break;

        case 2:
            funcao_pesquisar();
        break;

        case 3:
            funcao_listar();
        break;

        case 4:
            funcao_excluir();
        break;

        case 5:
            system ("cls");
            printf ("\n       ******************************************");
            printf ("\n       **     VOCÊ SELECIONOU A OPÇÃO SAIR     **");
            printf ("\n       ******************************************\n\n");
            printf ("\n          OBRIGADA POR ACESSAR NOSSO SISTEMA :) \n\n");
            printf ("\n             clique novamente para sair \n");

            getch();
        break;

        default:
            printf ("\n Opção inválida!\n\n Por favor, digite um número válido:\n\n");
            getch();
        break;
        }
    } while (op != 5);
}

void funcao_cadastro(){
setlocale (LC_ALL, "Portuguese");
system ("cls");

    FILE* arv_covid;
    CADASTRO cad;

    arv_covid = fopen ("cadastro_covid.txt","ab");

    if (arv_covid == NULL) {
        printf("ERRO AO ABRIR ARQUIVO!!");
        printf("\n CRIE O ARQUIVO NA PASTA DE DESTINO.\n");
    }
    else {
        do {
        printf ("\n       *************************");
        printf ("\n       **    NOVO CADASTRO    **");
        printf ("\n       *************************\n\n");

            fflush (stdin);
            printf ("\n   Digite o Nome do Paciente: ");
            gets (cad.nome_paciente);

            fflush (stdin);
            printf ("\n   Digite o E-mail: ");
            gets (cad.email);

            fflush (stdin);
            printf ("\n   Digite o CPF: ");
            gets (cad.cpf);

            fflush (stdin);
            printf ("\n   Digite o Telefone: ");
            gets (cad.telefone);

            fflush (stdin);
            printf ("\n   Digite a Data de Nascimento: ");
            gets (cad.data_nascimento);

            fflush (stdin);
            printf ("\n   Digite a Data de Diagnóstico: ");
            gets (cad.data_diagnostico);

            fflush (stdin);
            printf ("\n   Digite o Endereço Completo (Bairro/ Rua/ Número): ");
            gets (cad.endereco);

            fflush (stdin);
            printf ("\n   Digite a Cidade do Paciente: ");
            gets (cad.cidade);

            fflush (stdin);

            //bool cad.comorbidade = true;
            printf ("\n   O Paciente possui alguma Comorbidade (1. Sim / 2. Não) ");
            scanf("%i", &opc_comorbidade);

            if(opc_comorbidade == 1){
                printf("\n   Informe a Comorbidade: ");
                scanf("%s", &cad.comorbidade);
            }
            else{
                printf("\n   O paciente não possui comorbidade.\n");
                //cad.comorbidade = false;
            }
            printf ("\n   PARABÉNS, OS DADOS FORAM GRAVADOS COM SUCESSO!! \n");

            fwrite(&cad, sizeof (CADASTRO), 1, arv_covid);
            printf ("\n   Deseja Continuar (1. Sim | 2. Não)? ");
        } while (getche () == '1');
        fclose (arv_covid);
    }
}

void funcao_listar (){
system ("cls");

    printf ("\n       *******************************************");
    printf ("\n       **    TODOS OS PACIENTES CADASTRADOS:    **");
    printf ("\n       *******************************************\n\n");

    FILE* arv_covid;
    CADASTRO cad;

    arv_covid = fopen ("cadastro_covid.txt","rb");

    if (arv_covid == NULL) {
        printf("Problemas na abertura do arquivo! \n");
    }
    else {
        while(fread(&cad, sizeof (CADASTRO), 1, arv_covid)==1){
            fflush (stdin);
            printf ("\n  Nome do Paciente: %s \n", cad.nome_paciente);
            fflush (stdin);
            printf ("  E-mail: %s\n", cad.email);
            fflush (stdin);
            printf ("  CPF: %s\n", cad.cpf);
            fflush (stdin);
            printf ("  Telefone: %s\n", cad.telefone);
            fflush (stdin);
            printf ("  Data de Nascimento: %s\n", cad.data_nascimento);
            fflush (stdin);
            printf ("  Data de Diagnóstico: %s\n", cad.data_diagnostico);
            fflush (stdin);
            printf ("  Endereço: (Bairro/ Rua/ Número) %s\n", cad.endereco);
            fflush (stdin);
            printf ("  Cidade: %s\n", cad.cidade);
            fflush (stdin);
            printf ("  Comorbidade: %s\n", cad.comorbidade);
            printf ("_________________________________\n\n");
            getch ();
            }
        }
        fclose(arv_covid);
    }

void funcao_pesquisar(){

    FILE* arv_covid;
    CADASTRO cad;
    char CPF [30];

    do {
    system ("cls");

    printf ("\n       *******************************");
    printf ("\n       **    PESQUISAR POR CPF:    **");
    printf ("\n       ******************************\n\n");

    arv_covid = fopen ("cadastro_covid.txt","rb");
    if (arv_covid == NULL) {
        printf("   Problemas na abertura do arquivo! \n");
    }
    else {
        fflush (stdin);
        printf("\n   Digite o CPF: ");
        gets (CPF);

        while (fread(&cad, sizeof(CADASTRO), 1, arv_covid)==1){
            if (strcmp (CPF, cad.cpf)==0){
                printf ("\n  Nome do Paciente: %s \n", cad.nome_paciente);
                printf ("  E-mail: %s\n", cad.email);
                printf ("  CPF: %s\n", cad.cpf);
                printf ("  Telefone: %s\n", cad.telefone);
                printf ("  Data de Nascimento: %s\n", cad.data_nascimento);
                printf ("  Data de Diagnóstico: %s\n", cad.data_diagnostico);
                printf ("  Endereço: (Bairro/ Rua/ Número) %s\n", cad.endereco);
                printf ("  Cidade: %s\n", cad.cidade);
                printf ("  Comorbidade: %s\n", cad.comorbidade);
            }
        }
    }
    fwrite(&cad, sizeof (CADASTRO), 1, arv_covid);

    printf ("\n   Deseja Continuar (1. Sim | 2. Não)? ");
    } while (getche () == '1');
    fclose (arv_covid);
    getch();
}

void funcao_excluir (){

    FILE* arv_covid;
    FILE* arv_covid_temp;

    CADASTRO cad;
    char CPF [30];

    do {
    system ("cls");

    printf ("\n       *******************************");
    printf ("\n       **      EXCLUIR CADASTRO     **");
    printf ("\n       ******************************\n\n");

    arv_covid = fopen ("cadastro_covid.txt","rb");
    arv_covid_temp = fopen ("cadastro_temporario.txt","ab");

    if (arv_covid == NULL || arv_covid_temp == NULL) {
        printf("   Problemas na abertura do arquivo! \n");
    }
    else {
        fflush (stdin);
        printf("\n   Digite o CPF: ");
        gets (CPF);

        while (fread(&cad, sizeof(CADASTRO), 1, arv_covid)==1){
            if (strcmp (CPF, cad.cpf)!=0){
                fwrite (&cad, sizeof(CADASTRO), 1, arv_covid_temp);
            }
        }
    }
    fclose (arv_covid);
    fclose (arv_covid_temp);
    remove ("cadastro_covid.txt");
    rename ("cadastro_temporario.txt", "cadastro_covid.txt");
    printf ("\n   Cadastro excluido com sucesso!");
    getch();
    write(&cad, sizeof (CADASTRO), 1, arv_covid);
    printf ("\n\n   Deseja Continuar (1. Sim | 2. Não)? ");

    } while (getche () == '1');
    getch();
}
