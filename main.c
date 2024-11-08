#include <stdio.h>
#include "leitores_escritores.h"
#include "barreiras.h"
#include "sinais.h"
#include "deadlock.h"

int main() {
    int choice;

    printf("Escolha um exemplo para executar:\n");
    printf("1. Leitores e Escritores\n");
    printf("2. Barreiras\n");
    printf("3. Sinais\n");
    printf("4. Deadlock\n");
    printf("Escolha: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            execute_leitores_escritores();
        break;
        case 2:
            execute_barreiras();
        break;
        case 3:
            execute_sinais();
        break;
        case 4:
            execute_deadlock();
        break;
        default:
            printf("Opção inválida\n");
        break;
    }

    return 0;
}
