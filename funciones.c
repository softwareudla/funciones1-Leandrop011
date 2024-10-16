#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX_PRODUCTOS 10
// funciones

void ingresarProductos(char nombres[][30], float precios[], int *cantidad) {
    if (*cantidad >= MAX_PRODUCTOS) {
        printf("Ya se han ingresado 10 productos. No se pueden ingresar mas.\n");
        return;
    }
    printf("Ingrese el nombre del producto: ");
    getchar();  //  buffer 
    fgets(nombres[*cantidad], 30, stdin);
    // salto de línea 
    nombres[*cantidad][strcspn(nombres[*cantidad], "\n")] = '\0';

    printf("Ingrese el precio del producto: ");
    precios[*cantidad] = obtenerPrecioValido();
    
    (*cantidad)++;
}

float obtenerPrecioValido() {
    float precio;
    int resultado;
    
    do {
        resultado = scanf("%f", &precio);
        if (resultado != 1 || precio < 0) {
            printf("Entrada no valida. Ingrese un precio valido (numero positivo): ");
            while (getchar() != '\n');  // buffer 
        }
    } while (resultado != 1 || precio < 0);

    return precio;
}

float calcularPrecioTotal(float precios[], int cantidad) {
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += precios[i];
    }
    return total;
}

void encontrarMasCaroYBarato(char nombres[][30], float precios[], int cantidad) {
    if (cantidad == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }
    int indiceMasCaro = 0, indiceMasBarato = 0;
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] > precios[indiceMasCaro]) {
            indiceMasCaro = i;
        }
        if (precios[i] < precios[indiceMasBarato]) {
            indiceMasBarato = i;
        }
    }
    printf("El producto mas caro es %s con un precio de %.2f\n", nombres[indiceMasCaro], precios[indiceMasCaro]);
    printf("El producto mas barato es %s con un precio de %.2f\n", nombres[indiceMasBarato], precios[indiceMasBarato]);
}

float calcularPromedio(float precios[], int cantidad) {
    if (cantidad == 0) {
        return 0;
    }
    return calcularPrecioTotal(precios, cantidad) / cantidad;
}

void buscarProducto(char nombres[][30], float precios[], int cantidad, char nombreBuscado[]) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            printf("El producto %s tiene un precio de %.2f\n", nombres[i], precios[i]);
            return;
        }
    }
    printf("\nXX Producto no encontrado XX\n");
}