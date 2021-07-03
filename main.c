#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM 1000

typedef enum {Janeiro = 1, Fevereiro, Marco, Abril, Maio, Junho, Julho, Agosto, Setembro, Outubro, Novembro, Dezembro}Meses;

typedef struct{
    char cidade[50];
    char bairro[50];
    char rua[50];
    int numero;
    char complemento[50];
}Endereco;

typedef struct{
    int dia;
    Meses mes;
    int ano;
}Data_nascimento;

typedef struct{
    char nome[50];
    char cpf[50];
    int idade;
    Endereco end;
    Data_nascimento date;
}Cliente;

void imprimir(Cliente c[], int indice){

    printf("DADOS DO CLIENTE \n\n");
    printf("NOME..................................................: ");
    puts(c[indice].nome);
    printf("CPF...................................................: ");
    puts(c[indice].cpf);
    printf("IDADE.................................................: %d\n", c[indice].idade);
    printf("DATA DE NASCIMENTO....................................: %d - %d - %d\n\n", c[indice].date.dia, c[indice].date.mes, c[indice].date.ano);
    printf("CIDADE................................................: ");
    puts(c[indice].end.cidade);
    printf("BAIRRO................................................: ");
    puts(c[indice].end.bairro);
    printf("RUA...................................................: ");
    puts(c[indice].end.rua);
    printf("NÚMERO................................................: %d\n", c[indice].end.numero);
    printf("COMPLEMENTO...........................................: ");
    puts(c[indice].end.complemento);
    printf("\n\n");
}

void cadastro(Cliente c[], int local){

    int verifica = 1;

    printf("-------------------------------------------------- BANCO CEFET MONEY --------------------------------------------------\n\n");
    printf("CADASTRO DO CLIENTE %d \n\n", local+1);
    printf("INFORME O NOME: ");
    gets(c[local].nome);

    while(verifica){
        printf("INFORME O CPF: ");
        gets(c[local].cpf);
        if(strlen(c[local].cpf) > 11 || strlen(c[local].cpf) < 11){
            printf("CPF INVÁLIDO - NECESSÁRIO 11 CARACTERES\n");
        }else{
            if(local == 0){
                verifica = 0;
            }else{
                for(int contador = 0; contador < local; contador++){
                    if(!strcmp(c[local].cpf, c[contador].cpf)){
                        printf("CPF JÁ EXISTENTE! \n");
                        verifica = 1;
                        contador = local;
                    }else{
                        verifica = 0;
                    }
                }
            }

        }
    }

    verifica = 1;

    while(verifica){
        printf("INFORME A IDADE: ");
        scanf("%d", &c[local].idade);
        if(c[local].idade < 0){
            printf("IDADE FORA DO LIMITE PERMITIDO\n");
        }else{
            verifica = 0;
        }
    }

    fflush(stdin);

    printf("ENDEREÇO \n");
    printf("CIDADE: ");
    gets(c[local].end.cidade);
    printf("BAIRRO: ");
    gets(c[local].end.bairro);
    printf("RUA: ");
    gets(c[local].end.rua);
    printf("NÚMERO: ");
    scanf("%d", &c[local].end.numero);

    fflush(stdin);

    printf("COMPLEMENTO: ");
    gets(c[local].end.complemento);

    printf("DATA DE NASCIMENTO \n");

    verifica = 1;

    while(verifica){
        printf("DIA: ");
        scanf("%d", &c[local].date.dia);
        if(c[local].date.dia >= 1 && c[local].date.dia <= 31){
            verifica = 0;
        }else{
            printf("DIA INVÁLIDO (1 <--> 31)\n");
        }
    }

    verifica = 1;

    while(verifica){
        printf("MÊS: ");
        scanf("%d", &c[local].date.mes);
        if(c[local].date.mes >= Janeiro && c[local].date.mes <= Dezembro){
            verifica = 0;
        }else{
            printf("MÊS INVÁLIDO (1 <--> 12)\n");
        }
    }

    verifica = 1;


    while(verifica){
        printf("ANO: ");
        scanf("%d", &c[local].date.ano);
        if(c[local].date.ano > 0){
            verifica = 0;
        }else{
            printf("ANO INVÁLIDO (MENOR OU IGUAL A ZERO)\n");
        }
    }

}

void buscar_nome(Cliente c[], char buscar[]){

    int teste = 0;

    for(int contador_busca = 0; contador_busca < 1000; contador_busca++){
        if(!strncmp(buscar, c[contador_busca].nome, strlen(buscar))){

            teste++;
            imprimir(c, contador_busca);
        }
    }

    if(!teste){
        printf("NENHUM RESULTADO ENCONTRADO\n\n");
    }
}

void buscar_cpf(Cliente c[], char buscar[]){

    int teste = 0;

    for(int contador_busca = 0; contador_busca < 1000; contador_busca++){
        if(!strcmp(buscar, c[contador_busca].cpf)){

            teste++;
            imprimir(c, contador_busca);
        }
    }

    if(!teste){
        printf("NENHUM RESULTADO ENCONTRADO\n\n");
    }
}

void buscar_cidade(Cliente c[], char buscar[]){

    int teste = 0;
    for(int contador_busca = 0; contador_busca < 1000; contador_busca++){
        if(!strcmp(buscar, c[contador_busca].end.cidade)){

            teste++;
            imprimir(c, contador_busca);
        }
    }

    if(!teste){
        printf("NENHUM RESULTADO ENCONTRADO\n\n");
    }
}

void busca(Cliente c[]){

    int opcao_buscar, verifica = 1;
    char buscar[50];

    printf("-------------------------------------------------- BANCO CEFET MONEY --------------------------------------------------\n\n");
    printf("BUSCAR CLIENTES\n\n");
    printf("PESQUISAR POR:\n");
    printf("1 - NOME\n");
    printf("2 - CPF\n");
    printf("3 - CIDADE\n");
    printf("4 - MENU ANTERIOR\n\n");
    printf("-> ");
    scanf(" %d", &opcao_buscar);

    fflush(stdin);
    system("cls");

    switch(opcao_buscar){
        case 1:
            printf("-------------------------------------------------- BANCO CEFET MONEY --------------------------------------------------\n\n");
            printf("INFORME O NOME: ");
            gets(buscar);

            system("cls");
            printf("-------------------------------------------------- BANCO CEFET MONEY --------------------------------------------------\n\n");

            buscar_nome(c, buscar);

            system("pause");
            break;
        case 2:
            printf("-------------------------------------------------- BANCO CEFET MONEY --------------------------------------------------\n\n");

            while(verifica){
                printf("INFORME O CPF: ");
                gets(buscar);
                if(strlen(buscar) > 11 || strlen(buscar) < 11){
                    printf("CPF INVÁLIDO - NECESSÁRIO 11 CARACTERES\n");
                }else{
                    verifica = 0;
                }
            }

            verifica = 1;

            system("cls");
            printf("-------------------------------------------------- BANCO CEFET MONEY --------------------------------------------------\n\n");

            buscar_cpf(c, buscar);

            system("pause");
            break;
        case 3:
            printf("-------------------------------------------------- BANCO CEFET MONEY --------------------------------------------------\n\n");
            printf("INFORME A CIDADE: ");
            gets(buscar);

            system("cls");
            printf("-------------------------------------------------- BANCO CEFET MONEY --------------------------------------------------\n\n");


            buscar_cidade(c, buscar);

            system("pause");
            break;
        case 4:
            return 0;
            break;
        default:
            printf("-------------------------------------------------- BANCO CEFET MONEY --------------------------------------------------\n\n");
            printf("OPÇÃO INVÁLIDA !!\n\n");
            system("pause");
            break;
    }
}

void alterar(Cliente c[]){

    int indice_alterar, opcao, verifica = 1;
    char alterar[50];

    printf("-------------------------------------------------- BANCO CEFET MONEY --------------------------------------------------\n\n");
    printf("ALTERAR DADOS DO CLIENTE\n");

    while(verifica){
        printf("INFORME O CPF DO CLIENTE:\n");
        printf("-> ");
        gets(alterar);
        if(strlen(alterar) > 11 || strlen(alterar) < 11){
            printf("CPF INVÁLIDO - NECESSÁRIO 11 CARACTERES\n");
        }else{
            verifica = 0;
        }
    }

    verifica = 1;

    int teste = 0;

    for(int contador_alterar = 0; contador_alterar < 1000; contador_alterar++){
        if(!strcmp(alterar, c[contador_alterar].cpf)){

            teste = 1;
            indice_alterar = contador_alterar;
        }
    }

    if(!teste){
        printf("\nNENHUM RESULTADO ENCONTRADO\n\n");
    }else{
        printf("O QUE DESEJA ALTERAR ?\n");
        printf("1 - IDADE\n");
        printf("2 - ENDEREÇO\n");
        printf("-> ");
        scanf(" %d", &opcao);
        fflush(stdin);

        switch(opcao){
            case 1:
                printf("IDADE ATUAL: %d\n", c[indice_alterar].idade);
                printf("INFORME A NOVA IDADE: ");
                scanf("%d", &c[indice_alterar].idade);
                break;
            case 2:
                printf("ENDERÇO ATUAL:\n");
                printf("CIDADE................................................: ");
                puts(c[indice_alterar].end.cidade);
                printf("BAIRRO................................................: ");
                puts(c[indice_alterar].end.bairro);
                printf("RUA...................................................: ");
                puts(c[indice_alterar].end.rua);
                printf("NÚMERO................................................: %d\n", c[indice_alterar].end.numero);
                printf("COMPLEMENTO...........................................: ");
                puts(c[indice_alterar].end.complemento);

                printf("\nINFORME O NOVO ENDERÇO: \n");
                printf("ENDEREÇO \n");
                printf("CIDADE: ");
                gets(c[indice_alterar].end.cidade);
                printf("BAIRRO: ");
                gets(c[indice_alterar].end.bairro);
                printf("RUA: ");
                gets(c[indice_alterar].end.rua);
                printf("NÚMERO: ");
                scanf("%d", &c[indice_alterar].end.numero);
                fflush(stdin);
                printf("COMPLEMENTO: ");
                gets(c[indice_alterar].end.complemento);
                break;
            default:
                printf("-------------------------------------------------- BANCO CEFET MONEY --------------------------------------------------\n\n");
                printf("OPÇÃO INVÁLIDA !!\n\n");
                system("pause");
                break;
        }
    }

    system("pause");
}

void exclui(Cliente c[]){

    int indice_excluir, opcao, exclusao, verifica = 1;
    char excluir[50];

    printf("-------------------------------------------------- BANCO CEFET MONEY --------------------------------------------------\n\n");
    printf("EXCLUIR DADOS DO CLIENTE\n");

    while(verifica){
        printf("INFORME O CPF DO CLIENTE:\n");
        printf("-> ");
        gets(excluir);
        if(strlen(excluir) > 11 || strlen(excluir) < 11){
            printf("CPF INVÁLIDO - NECESSÁRIO 11 CARACTERES\n");
        }else{
            verifica = 0;
        }
    }

    verifica = 1;

    int teste = 0;

    for(int contador_excluir = 0; contador_excluir < 1000; contador_excluir++){
        if(!strcmp(excluir, c[contador_excluir].cpf)){

            teste = 1;
            indice_excluir = contador_excluir;
        }
    }

    if(!teste){
        printf("\nNENHUM RESULTADO ENCONTRADO\n\n");
    }else{
        printf("\n\n");
        imprimir(c, indice_excluir);
        printf("\n\nCONFIRMAR EXCLUSÃO ?\n\n");
        printf("1 - SIM\n");
        printf("2 - NAO\n\n");
        printf("->");
        scanf("%d", &exclusao);

        Cliente *end1, *end2;

        switch(exclusao){
            case 1:
                for(int contador_excluir = indice_excluir; c[contador_excluir].cpf[0] != '0'; contador_excluir++){
                        end1 = &c[contador_excluir];
                        end2 = &c[contador_excluir+1];

                        *end1 = *end2;
                }
                break;
            case 2:
                break;
            default:
                printf("-------------------------------------------------- BANCO CEFET MONEY --------------------------------------------------\n\n");
                printf("OPÇÃO INVÁLIDA !!\n\n");
                system("pause");
                break;
        }
    }

    system("pause");
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int opcao,  loop = 1, contador_cadastro = 0;
    Cliente c[TAM];

    for(int contador = 0; contador < 1000; contador++){
        c[contador].cpf[0] = '0';
    }

    while(loop){
        printf("-------------------------------------------------- BANCO CEFET MONEY --------------------------------------------------\n\n");
        printf("BEM VINDO AO SISTEMA, O QUE DESEJA FAZER ?\n\n");
        printf("1 - CADASTRAR NOVO CLIENTE\n");
        printf("2 - BUSCAR INFORMAÇÕES DOS CLIENTES\n");
        printf("3 - ALTERAR DADO DO CLIENTE\n");
        printf("4 - EXCLUIR CLIENTE\n");
        printf("5 - ENCERRAR SISTEMA\n\n->");
        scanf(" %d", &opcao);

        system("cls");
        fflush(stdin);

        switch(opcao){
            case 1:
                cadastro(c, contador_cadastro);
                contador_cadastro++;
                break;
            case 2:
                busca(c);
                break;
            case 3:
                alterar(c);
                break;
            case 4:
                exclui(c);
                contador_cadastro--;
                break;
            case 5:
                loop = 0;
                break;
            default:
                printf("-------------------------------------------------- BANCO CEFET MONEY --------------------------------------------------\n\n");
                printf("OPÇÃO INVÁLIDA !!\n\n");
                system("pause");
                break;
        }

        system("cls");
    }



    return 0;
}
