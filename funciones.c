#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX_PRODUCTOS 10

// funciones
int ingresarProductos(char nombres[][30], float precios[], int cantidad) {
    if (cantidad >= MAX_PRODUCTOS) {
        printf("Ya se han ingresado 10 productos. No se pueden ingresar más.\n");
        return cantidad;  // Retorna la misma cantidad si ya se ha alcanzado el límite
    }

    printf("Ingrese el nombre del producto: ");
    getchar();  // Eliminar salto de línea previo si lo hay
    fgets(nombres[cantidad], 30, stdin);
    // Remover el salto de línea al final del nombre
    nombres[cantidad][strcspn(nombres[cantidad], "\n")] = '\0';

    printf("Ingrese el precio del producto: ");
    precios[cantidad] = obtenerPrecioValido();  // Llamada a la función para validar precio

    return cantidad + 1;  // Incrementa cantidad y la retorna
}

float obtenerPrecioValido() {
    float precio;
    int resultado;

    do {
        resultado = scanf("%f", &precio);
        if (resultado != 1 || precio < 0) {
            printf("Entrada no válida. Ingrese un precio válido (número positivo): ");
            while (getchar() != '\n');  // Limpiar el buffer de entrada
        }
    } while (resultado != 1 || precio < 0);

    return precio;  // Devuelve el precio válido
}

float calcularPrecioTotal(float precios[], int cantidad) {
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += precios[i];  // Suma todos los precios
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
            indiceMasCaro = i;  // Actualiza el índice del producto más caro
        }
        if (precios[i] < precios[indiceMasBarato]) {
            indiceMasBarato = i;  // Actualiza el índice del producto más barato
        }
    }

    printf("El producto más caro es %s con un precio de %.2f\n", nombres[indiceMasCaro], precios[indiceMasCaro]);
    printf("El producto más barato es %s con un precio de %.2f\n", nombres[indiceMasBarato], precios[indiceMasBarato]);
}

float calcularPromedio(float precios[], int cantidad) {
    if (cantidad == 0) {
        return 0;  // Si no hay productos, el promedio es 0
    }
    return calcularPrecioTotal(precios, cantidad) / cantidad;  // Retorna el promedio
}

void buscarProducto(char nombres[][30], float precios[], int cantidad, char nombreBuscado[]) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            printf("El producto %s tiene un precio de %.2f\n", nombres[i], precios[i]);
            return;
        }
    }

    printf("\n XX Producto no encontrado XX\n");  // Si no se encuentra, imprime un mensaje
}