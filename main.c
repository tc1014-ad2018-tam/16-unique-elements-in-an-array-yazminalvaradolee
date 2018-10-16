/*
 * APLICACION PARA QUE EL USUARIO PUEDA PONER LA CANTIDAD DE NUMEROS QUE QUIERA
 * Y SI SE REPITEN LE SUELTA UNA VARIABLE
 *
 * Autora: Yasmin Alvarado Lee
 * correo: yazminalvlee@gmail.com
 * fecha:16 de oct del 2018
 */

#include <stdio.h>
#include <stdlib.h>

int CompFunct(const void *a, const void *b) {
    return ( *(int*)a - *(int*)b );
}
//VARIABLES
int main() {
    int e;
    int n;
    int count;
    int cant;

    printf("Cuantos numeros quieres utilizar?\n");
    scanf("%i", &n);

    //Aqui ponemos los numeros que vamos a utilizar
    int arr[n];

    //Aqui ponemos los valores que el usuario ponga
    for (int a = 0; a < n; a++) {
        printf("Escribe un numero y dale enter dependiendo de cuantos elegiste arriba:\n", a + 1);
        scanf("%i", &e);
        arr[a] = e;
    }

    //OPERACIONES
    //AQUI IDENTIFICAREMOS EL QUE PUSO EL USUARIO Y LOS ORDENAREMOS DEPENDIENDO COMO ESTUVIERAN ACOMODADOS
    qsort(arr, n, sizeof(int), CompFunct);
    printf("Los numeros unicos de esta tabla son:\n");

    //OPERACION PARA SACAR LOS NUMEROS UNICOS
    for (int a = 0; a < n; a += count+1) {
        count = 0;
        //AQUI ES LA OPERACION DEPENDIENDO LOS NUMEROS QUE PUSO EL USUARIO
        do {
            if (arr[a] == arr[a+count+1]) {
                count++;
                cant = 1;
            } else {
                cant = 0;
            }
        } while (cant == 1);

        //Si el numero no se repitio significa que es unico
        if (count == 0) {
            printf("%i\n", arr[a]);
        }
    }
    return 0;
}