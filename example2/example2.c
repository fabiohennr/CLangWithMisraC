#include <stdio.h>
#include <stdint.h>

int main(void) {
    int8_t a; // Violacao: Variavel nao inicializada (MISRA C:2012 Rule 9.1)
    int16_t b = 20;
    int32_t c = a + b; // Violacao: Uso de variavel nao inicializada (MISRA C:2012 Rule 9.1) e conversao implicita (MISRA C:2012 Rule 10.8)

    if (c = 10) { // Violacao: Atribuicao em vez de comparacao (MISRA C:2012 Rule 14.4)
        printf("c = 10\n");
    }

    for (int i = 0; i < 10; ++i); // Violacao: Loop vazio (MISRA C:2012 Rule 16.3)

    int8_t arr[5];
    arr[10] = 5; // Violacao: Acesso fora dos limites do array (MISRA C:2012 Rule 18.1)

    int8_t *ptr = NULL;
    *ptr = 10; // Violacao: Desreferencia de ponteiro nulo (MISRA C:2012 Rule 11.8)

    int16_t d = 100000; // Violacao: Valor fora do intervalo do tipo (MISRA C:2012 Rule 10.1)

    return 0;
}