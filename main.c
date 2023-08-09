#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LENGHT 1000

void open_File(FILE **ptr_file, char **text);
void number_Convert(double array[], char *text, int *lenght);
void number_Sorting(double array[], int array_size);

void open_File(FILE **ptr_file, char **text)
{
    *ptr_file = fopen("input.txt", "r");
    if(*ptr_file == NULL)
    {
        printf("Error, while opening the file!\n");
        exit (-1);
    }
    else
    {
        printf("The file is opened with succes!\n");
    }

    *text = (char *)malloc(sizeof(char) *MAX_LENGHT);

    while(fgets(*text, MAX_LENGHT, *ptr_file))
    {
        printf("%s ", *text);
    }

    fclose(*ptr_file); 
}

void number_Convert(double array[], char *text, int *array_size)
{
    int index = 0;
    char *token = strtok(text, " "); 

    while(token != NULL)
    {
        array[index++] = atof(token);
        token = strtok(NULL, " ");
    }

    *array_size = index;
}

void number_Sorting(double array[], int array_size)
{
    for(int i = 0; i < array_size - 1; i++)
    {
        for(int j = 0; j < array_size - 1; j++)
        {
            if(array[j] > array[j + 1])
            {
                double tempo;
                tempo = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tempo;
            }
        }
    }
}

int main()
{
    FILE *file_ptr;
    char *text;
    double array[MAX_LENGHT];

    open_File(&file_ptr, &text);

    int array_size = 0;

    number_Convert(array, text, &array_size);

    number_Sorting(array, array_size);

    printf("\nThe sorted numbers are:\n");

    for(int i = 0; i < array_size; i++)
    {
        printf("%lg ", array[i]);
    }

    free(text);

    return 0;
}