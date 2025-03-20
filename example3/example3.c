#include <stdio.h>
#include <stdint.h>

int main(void) {
    int8_t a = 0; // Correcao: Inicializacao da variavel (MISRA C:2012 Rule 9.1)
    int16_t b = 20;
    int32_t c = (int32_t)a + (int32_t)b; // Correcao: Conversao explicita (MISRA C:2012 Rule 10.8)

    if (c == 10) { // Correcao: Comparacao em vez de atribuicao (MISRA C:2012 Rule 14.4)
        printf("c = 10\n");
    }

    for (int i = 0; i < 10; ++i) { // Correcao: Adicao de um corpo ao loop (MISRA C:2012 Rule 16.3)
        (void)i; // Uso da variavel para evitar aviso de nao utilizada
    }

    int8_t arr[5];
    // arr[10] = 5; // Correcao: Removido acesso fora dos limites do array (MISRA C:2012 Rule 18.1)

    int8_t *ptr = NULL;
    // *ptr = 10; // Correcao: Removida desreferencia de ponteiro nulo (MISRA C:2012 Rule 11.8)

    int16_t d = 32767; // Correcao: Valor dentro do intervalo do tipo (MISRA C:2012 Rule 10.1)

    return 0;
}