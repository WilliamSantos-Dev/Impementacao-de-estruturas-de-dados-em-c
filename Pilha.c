// William Batista, Laboratorio 3.
// implemente uma pilha utilizando ponteiros. Não esqueça de implementar as operações básicas.
//- Push - Inserção
//- Pop - Remoção

#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int info;
    struct pilha* prox; 
}Pilha;

Pilha* iniciarPilha(){
    return NULL;
}

Pilha* push(Pilha* inicio, int info){
    Pilha* pilhaaux = (Pilha*)malloc(sizeof(Pilha));
    if( inicio == NULL){
        pilhaaux->info = info;
        pilhaaux->prox = NULL;
        return pilhaaux;
    }else{
        pilhaaux->info = info;
        pilhaaux->prox =inicio;
        return pilhaaux;
    }
}

Pilha* pop(Pilha* inicio){
    if(inicio==NULL){
        return NULL;
    }else{
        if(inicio->prox == NULL){
            printf("\nInformação removida: %d\n", inicio->info);
            free(inicio);
            return NULL;
        }else{
            printf("\nInformação removida: %d\n", inicio->info);
            Pilha* aux = (Pilha*)malloc(sizeof(Pilha));
            aux = inicio->prox;
            free(inicio);
            return aux;
        }
    }
}

void verPilha(Pilha* inicio){
    printf("\n----------- Pilha ---------\n");
    if(inicio == NULL){
        printf("\nPIlha vazia!\n\n");
    }else{
        while(inicio != NULL){
        printf("Info: %d\n", inicio->info);
        inicio = inicio->prox;
        }
    }
    printf("----------------------------\n");

}

int main() {
    Pilha* inicio = (Pilha*)malloc(sizeof(Pilha));
    inicio = iniciarPilha();
    int opc, info;
    do{ 
        if(opc!=3) system("clear");
        
        printf("\n\nEscolha uma opcao: \n 1- Push (Inserir)\n 2- Pop (Remover)\n 3- Ver Pilha \n 4- Sair\n");
        scanf("%d", &opc);
        switch(opc){
            case 1:
                printf("Informe um valor.\n");
                scanf("%d", &info);
                inicio = push(inicio, info);
                break;
            case 2:
                inicio = pop(inicio);
                break;
            case 3:
                verPilha(inicio);
                break;
            case 4:
                break;
                
            default:
            printf("Opcao Invalida!\n");
        }
        
        
    }while(opc!= 4);
    return 0;
}