#include <stdio.h>

int main() {
    // Programa sem violacoes
    int x = 0;
    int y = 10;
    int z = 0;

    z = x + y;

    if (z == 0) {
        printf("z = zero\n");
    } else {
        printf("z != zero\n");
    }

    return 0;
}