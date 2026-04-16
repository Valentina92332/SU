#include<stdio.h>
#include<stdlib.h>
#include <windows.h> 
void zad1(){
    int n,m;
    printf("N: ");
    scanf("%d", &n);
    printf("M: ");
    scanf("%d", &m);
    int matrix[n][m];
    for(int i=0; i<n; i++)
    {
        for (int j=0;  j<m; j++)
        {
            printf("Въведете [%d][%d] елемент: ", i,j);
            scanf("%d",&matrix[i][j] );
        }
    }
    int row=1, col=1;
    for (int i=0; i<n; i++)
    {
        for(int j=0; j<m-1; j++)
        {
            if(matrix[i][j]>=matrix[i][j+1])
            {
                row=0;
                break;
            }
        }

    }
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n-1; i++)
        {
            if (matrix[i][j]<=matrix[i+1][j])
            {
                col=0;
                break;
            }
        }
    }
    if(row==1 && col==1)
    {
        printf("Всеки ред съдържа числа, подредени в нарастващ ред, а всяка колона съдържа числа подредени в намаляващ ред.\n");
    }
    else
    {
        printf("Условието не е изпълнено.\n");
    }
    
}

void zad2(){
    int n,m;
    printf("N: ");
    scanf("%d", &n);
    printf("M: ");
    scanf("%d", &m);
    int matrix[n][m];
    for(int i=0; i<n; i++)
    {
        for (int j=0;  j<m; j++)
        {
            printf("Въведете [%d][%d] елемент: ", i,j);
            scanf("%d",&matrix[i][j] );
        }
    }
    int maxSum = -10000000; 
    int targetRow = 0, targetCol = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            int currentSum = 0;
            for (int r = i - 1; r <= i + 1; r++)
            {
                for (int c = j - 1; c <= j + 1; c++)
                {
                    if (r >= 0 && r < n && c >= 0 && c < m && !(r == i && c == j))
                    {
                        currentSum += matrix[r][c];
                    }
                }
            }
            if (currentSum > maxSum)
            {
                maxSum = currentSum;
                targetRow = i;
                targetCol = j;
            }
        }
    }

    printf("\nЧислото с най-голям сбор на съседите е: %d\n", matrix[targetRow][targetCol]);
    //printf("Позиция: [%d][%d]\n", targetRow, targetCol);
   // printf("Максимален сбор на съседите: %d\n", maxSum);

}

void zad3(){
    int n,m;
    printf("N: ");
    scanf("%d", &n);
    printf("M: ");
    scanf("%d", &m);
    int matrix[n][m];
    for(int i=0; i<n; i++)
    {
        for (int j=0;  j<m; j++)
        {
            printf("Въведете [%d][%d] елемент: ", i,j);
            scanf("%d",&matrix[i][j] );
        }
    }
    int minVal = matrix[0][0];
    int maxVal = matrix[0][0];
    int minRow = 0;
    int maxRow = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] < minVal)
            {
                minVal = matrix[i][j];
                minRow = i;
            }
            if (matrix[i][j] > maxVal)
            {
                maxVal = matrix[i][j];
                maxRow = i;
            }
        }
    }
    if (minRow != maxRow)
    {
        for (int j = 0; j < m; j++)
        {
            int temp = matrix[minRow][j];
            matrix[minRow][j] = matrix[maxRow][j];
            matrix[maxRow][j] = temp;
        }
    }
    printf("\nМатрицата след размяната на ред %d и ред %d:\n", minRow, maxRow);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void zad4(){
    int n, m;
    printf("Въведете брой хора: ");
    scanf("%d", &n);
    printf("Въведете брой приятелства: ");
    scanf("%d", &m);
    int *friendsCount = (int*)calloc(n + 1, sizeof(int));    
    if (friendsCount == NULL) {
        printf("Грешка при заделяне на памет!\n");
        return;
    }
    printf("Въведете %d двойки приятелства:\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        if (u >= 1 && u <= n && v >= 1 && v <= n) {
            friendsCount[u]++;
            friendsCount[v]++;
        }
    }
    int search;
    printf("Въведете номер: ");
    scanf("%d", &search);
    if (search >= 1 && search <= n)
    {
        printf("Брой приятели: %d \n", friendsCount[search]);
    }
    else
    {
        printf("Невалиден номер!\n");
    }
    free(friendsCount);
}


void zad5(){
    int arr[1000];
    int size = 0;
    int command, x;
    printf("1: add(x), 2: delete(x), 3: smallest(x), 0: exit\n");
    while (1)
    {
        printf("Избор на команда: ");
        scanf("%d", &command);
        if (command == 0) 
        {
            break;
        }
        if (command == 1)
        {
            if (size < 1000)
            {
                printf("Число за добавяне: ");
                scanf("%d", &x);
                arr[size] = x;
                size++;
            }
            else
            {
                printf("Масивът е пълен!\n");
            }
        } 
        else if (command == 2)
        {
            printf("Число за изтриване: ");
            scanf("%d", &x);
            int newSize = 0;
            for (int i = 0; i < size; i++)
            {
                if (arr[i] != x)
                {
                    arr[newSize] = arr[i];
                    newSize++;
                }
            }
            size = newSize;
            printf("Елементите са изтрити.\n");
        } 
        else if (command == 3)
        { 
            printf("Кое по ред най-малко число (X): ");
            scanf("%d", &x);
            
            if (x > 0 && x <= size)
            {
                int tempArr[1000];
                for(int i = 0; i < size; i++) tempArr[i] = arr[i];

                for (int i = 0; i < size - 1; i++) {
                    for (int j = 0; j < size - i - 1; j++) {
                        if (tempArr[j] > tempArr[j + 1]) {
                            int temp = tempArr[j];
                            tempArr[j] = tempArr[j + 1];
                            tempArr[j + 1] = temp;
                        }
                    }
                }
                printf("%d-тото най-малко число е: %d\n", x, tempArr[x - 1]);
            }
            else
            {
                printf("Грешка: В масива има само %d елемента.\n", size);
            }
        }
    }
}


void zad6(){
    int n;
    printf("Веведете брой елементи: ");
    scanf("%d", &n);
    int *matrix=(int*)malloc(n*sizeof(int));
    printf("Въведете %d елемента: ", n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", (matrix+i));       
    }
    int prime_count = 0;
    for (int i = 0; i < n; i++)
    {
        int num = *(matrix + i);
        if (num < 2) 
        {
            continue;
        }
        int is_prime = 1;
        for (int j = 2; j * j <= num; j++)
        {
            if (num % j == 0)
            {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) 
        {
            prime_count++;
        }
    }
    int *primes = (int*)malloc(prime_count * sizeof(int));
    int *others = (int*)malloc((n - prime_count) * sizeof(int));
    int p_idx = 0;
    int o_idx = 0; 

    for (int i = 0; i < n; i++)
    {
        int num = *(matrix + i);
        int is_prime = 1;
        if (num < 2) is_prime = 0;
        else {
            for (int j = 2; j * j <= num; j++)
            {
                if (num % j == 0)
                {
                    is_prime = 0;
                    break;
                }
            }
        }

        if (is_prime)
        {
            *(primes + p_idx) = num;
            p_idx++;
        }
        else
        {
            *(others + o_idx) = num;
            o_idx++;
        }
    }

    printf("Масив без прости числа: ");
    for (int i = 0; i < o_idx; i++)
    {
        printf("%d ", *(others + i));
    }

    printf("\nМасив с прости числа: ");
    for (int i = 0; i < p_idx; i++)
    {
        printf("%d ", *(primes + i));
    }
    printf("\n");
    free(matrix);
    free(primes);
    free(others);

}
void zad7(){
    int n,m;
    printf("N: ");
    scanf("%d", &n);
    printf("M: ");
    scanf("%d", &m);
    int matrix[n][m];
    for(int i=0; i<n; i++)
    {
        for (int j=0;  j<m; j++)
        {
            printf("Въведете [%d][%d] елемент: ", i,j);
            scanf("%d",&matrix[i][j] );
        }
    }
     if (n < 3 || m < 3)
    {
        printf("Матрицата е твърде малка за подматрица 3х3.\n");
        return;
    }

    int maxSum = -10000000;
    int startRow = 0, startCol = 0;

    for (int i = 0; i <= n - 3; i++)
    {
        for (int j = 0; j <= m - 3; j++)
        {
            int currentSum = 0;
            for (int r = i; r < i + 3; r++)
            {
                for (int c = j; c < j + 3; c++)
                {
                    currentSum += matrix[r][c];
                }
            }
            if (currentSum > maxSum)
            {
                maxSum = currentSum;
                startRow = i;
                startCol = j;
            }
        }
    }
    printf("\nПодматрицата 3х3 с максимална сума (%d) е:\n", maxSum);
    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void zad8(){
    int size = 10;
    int *arr = (int*)malloc(size * sizeof(int));
    printf("Въведете първоначалните 10 числа:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int number, position;
    while (1) {
        printf("Въведете число за вмъкване (или 0 за край): ");
        scanf("%d", &number);
        if (number == 0)
        {
            break;
        } 
        printf("Въведете позиция (индекс): ");
        scanf("%d", &position);

        if (position < 0 || position > size)
        {
            printf("Невалидна позиция!\n");
            continue;
        }
        size++;
        arr = (int*)realloc(arr, size * sizeof(int));
        for (int i = size - 1; i > position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position] = number;
    }
    printf("\nКраен резултат: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
}

int main(){
    SetConsoleOutputCP(65001); 
    SetConsoleCP(65001);
    int choice;
    while(1){
        printf("Изберете задача: ");
        scanf("%d", &choice);
        if (choice==0)
        {
            break;
        }
        switch(choice)
        {
            case 1: zad1(); break;
            case 2: zad2(); break;
            case 3: zad3(); break;
            case 4: zad4(); break;
            case 5: zad5(); break;
            case 6: zad6(); break;
            case 7: zad7(); break;
            case 8: zad8(); break;
            default: printf("Невалиден избор.");
        }
    }
    return 0;
}