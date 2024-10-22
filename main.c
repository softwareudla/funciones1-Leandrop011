#include <stdio.h>
#include "funciones.h"
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTOS 10

int main() {
    char nombres[MAX_PRODUCTOS][30];
    float precios[MAX_PRODUCTOS];
    int cantidad = 0, opcion;
    char nombreBuscado[30];

    do {
        printf("---------------------------------------------\n");
        printf("Sistema de Inventario\n");
        printf("1. Ingresar productos\n");
        printf("2. Calcular precio total del inventario\n");
        printf("3. Encontrar el producto mas caro y mas barato\n");
        printf("4. Calcular el precio promedio\n");
        printf("5. Buscar producto por nombre\n");
        printf("6. Salir Del Programa\n");
        printf("7. BORRAR TODO EL HISTORIAL\n");
        printf("Ingrese una opcion:  ");
        scanf("%d", &opcion);
        printf("----------------------------------------------\n");

        switch (opcion) {
            case 1:
                cantidad = ingresarProductos(nombres, precios, cantidad);
                break;
            case 2:
                printf("El precio total del inventario es: %.2f\n", calcularPrecioTotal(precios, cantidad));
                break;
            case 3:
                encontrarMasCaroYBarato(nombres, precios, cantidad);
                break;
            case 4:
                printf("El precio promedio es: %.2f\n", calcularPromedio(precios, cantidad));
                break;
            case 5:
                printf("Ingrese el nombre del producto a buscar: ");
                scanf("%s", nombreBuscado);
                buscarProducto(nombres, precios, cantidad, nombreBuscado);
                break;
            case 6:
                printf("Saliendo del sistema...\n");
                break;
            case 7:
                cantidad = 0;  // Reinicia la cantidad de productos
                system("cls"); // Limpia la consola
                printf("Se ha borrado todo el historial.\n");
                break;
            default:
                printf("Opción no válida.\n");
        }

    } while (opcion != 6);

    return 0;
}