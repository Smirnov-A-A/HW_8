/* Считать массив из файла, передать в функцию для сортировки по убыванию,
отсортированный массив сохранить в файл
*/

#include <stdio.h>
#include <stdlib.h>

//1. Функция чтения из файла в массив
//аргументы: имя файла из которого производится чтение, указатель на массив, количество элементов массива
int file_read(const char *filename, int *arr, int n) {
    
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("File opening failed");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
}
    
//2. Функция сортировки массива
//аргументы: указатель на массив, количество элементов массива
void array_sort(int *arr, int n) {

    for (int i = 0; i < n - 1; ++i) {
        int max = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[max]) max = j;
        }
        int temp = arr[max];
        arr[max] = arr[i];
        arr[i] = temp;
    }
} 

//3. Функция записи в файл
//аргументы: имя файла для записи, указатель на массив, количество элементов массива
int file_wr(const char *filename, int *arr, int n) {

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("File opening failed");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);
}


int main() {

    int n = 0;
    int a = 0;
    const char *filename1 = "in_array.txt";
    const char *filename2 = "out_array.txt";    

    //определение количества элементов массива, записанных в файл
    FILE *fp = fopen(filename1, "r");
    if (fp == NULL) {
        perror("File opening failed");
        return 1;
    }
       while (fscanf(fp, "%d", &a) != EOF) {
        ++n;
    }
    fclose(fp);
    
    //выделение памяти для массива из n элементов
    int *pArr = (int*)calloc(n, sizeof(int));
    printf("Количество элементов в массиве n = %d\n", n);   

    //вызов функции чтения из файла
    file_read(filename1, pArr, n);
    printf("Проверка работы функции чтения массива из файла:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", pArr[i]);
    }
    printf("\n");
    
    //вызов функции сортировки
    array_sort(pArr, n);
    printf("Проверка работы функции сортировки:\n");  
    array_sort(pArr, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", pArr[i]);
    }
    printf("\n");

    //вызов функции записи в файл
    file_wr(filename2, pArr, n);

    //освобождение выделенной памяти
    free(pArr);
    pArr = NULL;

    return 0;
}
