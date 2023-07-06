#include <stdio.h>
#include <stdlib.h>
#include "sllist.h"

#define TRUE 1
#define FALSE 0

int main(){
    SLList *l;
    Time *time;
    int opc = 0, gols, listCreate = FALSE;
    float mediaGols = 0.0f;
    char nome[30];

    printf("\n1 - Criar lista\n2 - Inserir elemento\n3 - Remover um elemento\n4 - Consultar um elemento\n5 - Listar\n6 - Esvaziar colecao\n0 - Sair\nOpcao: ");
    scanf("%d", &opc);

    while(opc != 0){
        if(opc == 1){
            l = sllCreate();
            if(l != NULL){
                printf("\nLista criada com sucesso!\n");
                listCreate = TRUE;  //Atribuindo valor TRUE para identificar a criação da lista e fazer o controle de acesso das outras funções
            }else{
                printf("\nErro ao criar a lista. Tente novamente\n");
            }
        }
        else if(opc == 2){
            if(listCreate){ //Se Lista existe faça
                time = (Time *)malloc(sizeof(Time));
                if(time != NULL){
                    printf("\n[Nome do time, Gols, Media de gols]: ");
                    scanf("%s%d%f", &time->nome, &time->gols, &time->mediaGols);
                    sllInsertFirst(l, (void *)time);
                    printf("\n\tDados adicionados!\n");
                }

            }else{
                printf("\n\tCrie uma lista primeiro!\n");//Caso contrário
            }

        }
        else if(opc == 3){
            if(listCreate){
                int opcRemove = 0;
                printf("\n\tRemover por:\n1 - Nome\n2 - Gols\n3 - Media de Gols\nOpcao: ");
                scanf("%d", &opcRemove);
                switch(opcRemove){ //Opção de identificação do elemento para remoção
                    case 1: //Remover pelo campo char
                        printf("\nNome do time: ");
                        setbuf(stdin, NULL);
                        fgets(nome, 30, stdin);
                        time = sllRemove(l, (void *)nome, QueryTimeNome);
                        if(time != NULL){ //Se o elemento foi identificado faça
                            printf("\n\tDados removidos:\n");
                            printf("\nNome: %s\nGols: %d\nMedia Gols: %.2f\n", time->nome, time->gols,time->mediaGols);
                        }
                        else
                            printf("\n\tDados nao encontrados\n"); //Caso contrário
                        break;
                    case 2: //Remover pelo campo int
                        printf("\nQuantidade de Gols: ");
                        scanf("%d", &gols);
                        time = (Time *)sllRemove(l, (void *)gols, QueryTimeGols);
                        if(time != NULL){ //Se o elemento foi identificado faça
                            printf("\n\tDados removidos:\n");
                            printf("\nNome: %s\nGols: %d\nMedia Gols: %.2f\n", time->nome, time->gols,time->mediaGols);
                        }
                        else
                            printf("\n\tDados nao encontrados\n"); //Caso contrário
                        break;
                    case 3: //Remover pelo campo float
                        printf("\nMedia de gols: ");
                        scanf("%f", &mediaGols);
                        time = (Time *)sllRemove(l, (void *)&mediaGols, QueryTimeMediaGols);
                        if(time != NULL){//Se o elemento foi identificado faça
                            printf("\n\tDados removidos:\n");
                            printf("\nNome: %s\nGols: %d\nMedia Gols: %.2f\n", time->nome, time->gols,time->mediaGols);
                        }
                        else
                            printf("\n\tDados nao encontrados\n");//Caso contrário
                        break;
                    default:
                        printf("\nOpcao invalida!\n");
                }
            }else{
                printf("\n\tOpcao invalida!\n");
            }
        }
        else if(opc == 4){
            if(listCreate){
                int opcBusca = 0;
                printf("\n\tBuscar por:\n1 - Nome\n2 - Gols\n3 - Media de Gols\nOpcao: ");
                scanf("%d", &opcBusca);
                switch(opcBusca){ //Opção de identificação do elemento para busca
                    case 1:
                        printf("\nNome do time: "); //Buscar pelo campo char
                        setbuf(stdin, NULL);
                        fgets(nome, 30, stdin);
                        time = sllQuery(l, (void *)&nome, QueryTimeNome);
                        if(time != NULL) //Se o elemento foi identificado faça
                            printf("\nNome: %s\nGols: %d\nMedia Gols: %.2f\n", time->nome, time->gols,time->mediaGols);
                        else
                            printf("\n\tDados nao encontrados\n"); //Caso contrário
                        break;
                    case 2:
                        printf("\nQuantidade de Gols: "); //Buscar pelo campo int
                        scanf("%d", &gols);
                        time = (Time *)sllQuery(l, (void *)gols, QueryTimeGols);
                        if(time != NULL) //Se o elemento foi identificado faça
                            printf("\nNome: %s\nGols: %d\nMedia Gols: %.2f\n", time->nome, time->gols,time->mediaGols);
                        else
                            printf("\n\tDados nao encontrados\n"); //Caso contrário
                        break;
                    case 3:
                        printf("\nMedia de gols: "); //Buscar pelo campo float
                        scanf("%f", &mediaGols);
                        time = (Time *)sllQuery(l, (void *)&mediaGols, QueryTimeMediaGols);
                        if(time != NULL) //Se o elemento foi identificado faça
                            printf("\nNome: %s\nGols: %d\nMedia Gols: %.2f\n", time->nome, time->gols,time->mediaGols);
                        else
                            printf("\n\tDados nao encontrados\n"); //Caso contrário
                        break;
                    default:
                        printf("\nOpcao invalida!\n");
                }
            }else{
                printf("\n\tOpcao invalida!\n");
            }
        }
        else if(opc == 5){ //Listando os elementos
            if(listCreate){
                printf("\n\tElementos da Lista:\n");
                int i = 1; //variável de controle para função buscar o próximo elemento
                time = sllGetFirst(l);
                while(time != NULL){//Enquanto tiver elemento na lista faça
                    printf("\nNome: %s\nGols: %d\nMedia Gols: %.2f\n", time->nome, time->gols,time->mediaGols);
                    time = sllGetNext(l, i);
                    i++;
                }
            }else{
                printf("\n\tOpcao invalida!\n");
            }
        }
        else if(opc == 6){//Removendo todos os elementos
            if(listCreate){
                int i = 0;
                time = sllGetFirst(l);
                while(time != NULL){
                    time = (Time *)sllRemoveFirst(l);
                    time = sllGetNext(l, i);
                    i++;
                }
                printf("\n\tElementos removidos com sucesso!\n");
            }else{
                printf("\n\tOpcao invalida!\n");
            }
        }

        printf("\n1 - Criar lista\n2 - Inserir elemento\n3 - Remover um elemento\n4 - Consultar um elemento\n5 - Listar\n6 - Esvaziar colecao\n0 - Sair\nOpcao: ");
        printf("\n");
        scanf("%d", &opc);
    }

    return 0;
}
