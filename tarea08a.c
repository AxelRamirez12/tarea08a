#include <stdio.h>
#include <stdlib.h>
int main() {
 float *pesos, temp;
 int i, j, nest;
 system("clear");
 // Solicitar al usuario la cantidad de estudiantes
 printf("¿Cuantos estudiantes son?: ");
 if (scanf("%d", &nest) != 1 || nest <= 0) {
 // Manejar el caso de entrada invalida
 printf("Entrada invalida. Debe ingresar un número entero positivo.\n");
 return 1; // Salir del programa con código de error
 }
 // Reservar memoria dinamica para almacenar los pesos de los estudiantes
 pesos = (float *)malloc(nest * sizeof(float));
 if (pesos == NULL) {
 printf("Insuficiente Espacio de Memoria\n");
 return 1; // Salir del programa con código de error
 }
 // Ingresar los pesos de los estudiantes
 for (i = 0; i < nest; i++) {
 printf("Peso del Estudiante [%d]: ", i + 1);
 if (scanf("%f", (pesos + i)) != 1) {
 // Manejar el caso de entrada invalida
 printf("Entrada invalida. Debe ingresar un numero real.\n");
 free(pesos); // Liberar la memoria asignada dinamicamente
 return 1; // Salir del programa con codigo de error
 }
 }
 printf("\n****ARRAY ORIGINAL****\n");
 for (i = 0; i < nest; i++)
 printf("Peso[%d]: %.1f \n", i + 1, *(pesos + i));
 // Ordenar los pesos en orden ascendente utilizando el algoritmo de burbuja
 for (i = 0; i < nest; i++)
 for (j = 0; j < (nest - 1); j++)
 if (pesos[j] > pesos[j + 1]) {
 temp = pesos[j];
 pesos[j] = pesos[j + 1];
 pesos[j + 1] = temp;
 }
 printf("\n****ARRAY ORDENADO EN FORMATO ASCENDENTE****\n");
 for (i = 0; i < nest; i++)
 printf("Peso[%d]: %.1f \n", i + 1, *(pesos + i));
 // Liberar la memoria asignada dinamicamente
 free(pesos);
 return 0;
}