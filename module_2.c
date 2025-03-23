// Leer desde el teclado números enteros y cargar un vector con aquellos números pares.
// El fin de carga finaliza cuando se lee un cero o se hayan cargado 100 números en el arreglo
// Una vez finalizada la carga, si el vector tiene elementos mostrarlo; si no mostrar una leyenda
// indicando que no hay elementos y finalizar el programa.
// si hay datos se pide informar:
// a) Ingresar un numero por teclado, si el numero existe insertar antes de cada
// aparición de ese numero su opuesto. Si el numero ingresado no existe se pide Insertar
// el doble del numero ingresado en la posición siguiente a todos los valores pares negativos. Mostrar el vector.
// b) Ordenar el vector de mayor a menor y mostrar el vector.
// Se pide desarrollar la solución con al menos 5 funciones creadas por el programador.
// Entregar el archivo .c, o copiar el código

#include <stdio.h>

int load_vec(int vec[])
{
    int numb, i = 0;
    printf("Enter a number: ");
    scanf("%d", &numb);
    while (numb != 0 && i < 100)
    {
        if (numb % 2 == 0)
        {
            vec[i] = numb;
            i++;
        }
        printf("Enter a number: ");
        scanf("%d", &numb);
    }
    return i;
}

void show_vec(int vec[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int find_and_insert(int vec[], int dim)
{
    int numb, i = 0, j, found = 0;
    printf("Enter a number: ");
    scanf("%d", &numb);
    while (i < dim)
    {
        if (vec[i] == numb)
        {
            found = 1;
            for (int j = dim; j > i; j--)
            {
                vec[j] = vec[j - 1];
            }

            vec[i] = -vec[i];
            dim++;
            i = i + 2;
        }
        else
        {
            i++;
        }
    }

    if (found == 0)
    {
        for (int i = 0; i < dim; i++)
        {
            if (vec[i] < 0)
            {
                for (int j = dim; j > i; j--)
                {
                    vec[j] = vec[j - 1];
                }
                vec[i + 1] = 2 * numb;
                dim++;
                i++;
            }
        }
    }
    return dim;
}

void change_numbers(int vec[], int pos1, int pos2)
{
    int aux;
    aux = vec[pos2];
    vec[pos2] = vec[pos1];
    vec[pos1] = aux;
}

void order_vec(int vec[], int dim)
{
    int i, j;
    for (i = 0; i < dim - 1; i++)
        for (j = i + 1; j < dim; j++)
            if (vec[j] > vec[i])
            {
                change_numbers(vec, i, j);
            }
}

int main()
{
    int vec[100], dim, new_dim;

    dim = load_vec(vec);
    if (dim > 0)
    {
        printf("count: %d\n", dim);
        show_vec(vec, dim);
        new_dim = find_and_insert(vec, dim);
        printf("count new dim: %d\n", new_dim);
        show_vec(vec, new_dim);
        order_vec(vec, new_dim);
        show_vec(vec, new_dim);
        return 0;
    }
    else
    {
        printf("No elements\n");
        return 0;
    }

    return 0;
}
