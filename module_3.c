// Instrucciones:
// Recuerde validar los datos cuando sea necesario.
// Modularice su código de forma adecuada.

// Problema:
// Cargue una matriz de 50x50 con valores enteros ingresados desde el teclado.
// Una vez cargada la matriz, muestre su contenido y también su transpuesta.
// Calcule el valor máximo entre los elementos de la diagonal principal y la diagonal secundaria.
// Si el máximo es un número par: Genere un arreglo con todos los múltiplos de dicho número que estén presentes en la matriz.
// Si el máximo es un número impar: Genere un arreglo con todos los divisores del máximo.
// Si el máximo es cero: Genere un arreglo con todos los valores positivos pares de la matriz y duplique cada uno de ellos. Muestre el arreglo generado, invierta su contenido y vuelva a mostrar el arreglo.

// Restricciones:
// No es necesario realizar la transposición en memoria de la matriz. Solo se pide mostrar su contenido de forma traspuesta al imprimirla, sin modificar la matriz original.
// No utilice arreglos adicionales para invertir, eliminar o insertar elementos. Todas las operaciones solicitadas deben realizarse directamente sobre los datos ya existentes o generados, sin la creación de arreglos temporales o auxiliares.
// Al obtener el valor máximo de las diagonales (principal y secundaria), asegúrese de no recorrer elementos innecesarios de la matriz. Limite su análisis solo a los elementos que forman parte de las diagonales.

#include <stdio.h>

void cargar(int matriz[][50], int dim){
    int i, j, num;
    for(i=0;i < dim;i++){
        for(j=0;j<dim;j++){
            printf("Ingrese un valor parra la posicion [%d][%d]: ", i, j);
            scanf("%d",&num);  
            matriz[i][j] = num;  
        }
    }
}

void mostrar(int matriz[][50], int dim){
    int i,j;
    printf("mostrar matriz\n");
    for(i=0; i<dim; i++){
        printf("\n");
        for(j=0; j<dim; j++){
            printf("%d \t", matriz[i][j]);
        }
    }
}

void mostrar_traspuesta(int matriz[][50], int dim){
    int i,j;
    printf("\n\nMostrar matriz traspuesta\n");
    for(i=0; i<dim; i++){
        printf("\n");
        for(j=0; j<dim; j++){
            printf("%d \t", matriz[j][i]);
        }
    }
}

int maximo_diagonales(int matriz[][50], int dim) {
    int i, max;

    max = matriz[0][0];

    for (i = 0; i < dim; i++) {
        if (matriz[i][i] > max) {
            max = matriz[i][i];
        }

        if (matriz[i][dim - 1 - i] > max) {
            max = matriz[i][dim - 1 - i];
        }
    }

    return max;
}

int multiplos(int max_diagonales, int matriz[][50], int dim, int vec[]){
    int i,j, contador = 0;
    for(i=0; i<dim; i++){
        for(j=0; j<dim; j++){
            if(max_diagonales != 0 && matriz[i][j] % max_diagonales == 0){
                vec[contador] = matriz[i][j];
                contador++;
            }
        }
    }
    return contador;
}

int divisores(int max_diagonales, int matriz[][50], int dim, int vec[]){
    int i,j, contador = 0;
    for(i=0; i<dim; i++){
        for(j=0; j<dim; j++){
            if(matriz[i][j] != 0 && max_diagonales % matriz[i][j] == 0){
                vec[contador] = matriz[i][j];
                contador++;
            }
        }
    }
    return contador;
}

int positivos_pares(int matriz[][50], int dim, int vec[]){
    int i,j, contador = 0;
    for(i=0; i<dim; i++){
        for(j=0; j<dim; j++){
            if(matriz[i][j] > 0 && matriz[i][j] % 2 == 0){
                printf("%d ", matriz[i][j]);
                vec[contador] = matriz[i][j];
                contador++;
            }
        }
    }
    return contador;
}

void mostrar_vec(int vec[], int dim){
    for (int i = 0; i < dim; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int main()
{
    int matriz[50][50], dim, max_diagonal_principal, max_diagonal_secundaria, max_diagonales, vec[50], dim_vec;
    printf("Ingrese cantidad de filas o culumnas: ");
    scanf("%d", &dim);
    while (dim < 0 || dim > 50){
        printf("Error, ingrese un valor entre 0 y 50: ");
        scanf("%d", &dim);
    }
    cargar(matriz, dim);
    mostrar(matriz, dim);
    mostrar_traspuesta(matriz, dim);
    max_diagonales = maximo_diagonales(matriz, dim);
    printf("\n\nEl maximo de las diagonales es: %d", max_diagonales);
    if (max_diagonales == 0) {
        dim_vec = positivos_pares(matriz, dim, vec);
        printf("\n\n Los positivos pares de %d son:", max_diagonales);
        mostrar_vec(vec, dim_vec);
    } else if (max_diagonales % 2 == 0){
        dim_vec = multiplos(max_diagonales, matriz, dim, vec);
        printf("\n\n Los multiplos de %d son:", max_diagonales);
        mostrar_vec(vec, dim_vec);
    } else { 
        dim_vec = divisores(max_diagonales, matriz, dim, vec);
        printf("\n\n Los divisores de %d son:", max_diagonales);
        mostrar_vec(vec, dim_vec);
    }
    return 0;
}