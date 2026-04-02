#include <stdio.h>
#include <stdlib.h>

void zad1() {
    int n;
    printf("Въведете брой елементи (N): ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    printf("Въведете %d сортирани числа: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }

    int *p = arr;           
    int *best_start = arr; 
    int max_len = 1;    
    
    int *current_start = arr;
    int current_len = 1;

    for (p = arr + 1; p < arr + n; p++)
    {
        if (*p == *(p - 1))
        {
            current_len++;
        }
        else
        {
            if (current_len > max_len) {
                max_len = current_len;
                best_start = current_start;
            }
            current_start = p;
            current_len = 1;
        }
    }

    if (current_len > max_len) {
        max_len = current_len;
        best_start = current_start;
    }

    int start_index = (int)(best_start - arr);

    printf("\nНай-дълга площадка:\n");
    printf("Начален индекс: %d\n", start_index);
    printf("Дължина: %d\n", max_len);
    printf("Стойност на елементите: %d\n", *best_start);

    free(arr);

}

void zad2() {
    int n;
    printf("Въведете брой елементи (N): ");
    if (scanf("%d", &n) != 1 || n < 2)
    {
        printf("Невалиден вход или твърде малко елементи.\n");

    }
    double *arr = (double*)malloc(n * sizeof(double));

    printf("Въведете %d елемента: ", n);
    for (int i=0; i<n; i++)
    {
        scanf("%lf", (arr+i));
    }

    int is_zigzag = 1;    

    for (int i=0; i<n-1; i++)
    {
        if (i % 2 == 0) {
            if (!(arr[i] < arr[i+1]))
            {
                is_zigzag = 0;
                break;
            }
        }
        else
        {
            if (!(arr[i] > arr[i+1]))
            {
                is_zigzag = 0;
                break;
            }
        }
    }

    if (is_zigzag)
    {
        printf("Условията са изпълнени.");
    } else
    {
        printf("Условията не са изпълнени.");
    }

    free(arr);
}

void zad3() {
    int n;
    printf("Въведете n: ");
    scanf("%d", &n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Въведете %d числа: ", n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", (arr+i));
    }
    printf("Обърнатият масив е: ");
    for (int j=n-1; j>=0; j--)
    {
        
        printf("%d ", arr[j]);
    }
    free(arr);
}

void zad4() {
    int n,k;
    printf("Въведете n: ");
    scanf("%d", &n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Въведете %d числа: ", n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", (arr+i));
    }
    printf("Въведете k: ");
    scanf("%d", &k);
    k = k % n;
    if (k < 0) k = n + k;

    if (k > 0) {
        int *start, *end, temp;

        start = arr;
        end = arr + n - 1;
        while (start < end) {
            temp = *start; *start = *end; *end = temp;
            start++; end--;
        }

        start = arr;
        end = arr + k - 1;
        while (start < end) {
            temp = *start; *start = *end; *end = temp;
            start++; end--;
        }

        start = arr + k;
        end = arr + n - 1;
        while (start < end) {
            temp = *start; *start = *end; *end = temp;
            start++; end--;
        }
    }

    printf("Резултат след превъртане: ");
    for (int *p = arr; p < arr + n; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    free(arr);
}

void zad5() {
    int n, k;
    printf("Въведете брой елементи (N): ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));

    printf("Въведете %d елемента: ", n);
    for (int *p = arr; p < arr + n; p++) {
        scanf("%d", p);
    }

    printf("Въведете K (кой по ред най-голям елемент търсим): ");
    if (scanf("%d", &k) != 1 || k > n || k <= 0) {
        printf("Невалидно K!\n");
        free(arr);
    }

    for (int *i = arr; i < arr + n - 1; i++) {
        for (int *j = i + 1; j < arr + n; j++) {
            if (*j > *i) { 
                int temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
    printf("\n%d-тият по големина елемент е: %d\n", k, *(arr + k - 1));

    free(arr);
}

void zad6() {
     int n;
    printf("Въведете брой елементи (N): ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));

    printf("Въведете %d числа: ", n);
    for (int *p = arr; p < arr + n; p++) {
        scanf("%d", p);
    }

    int *best_start = arr; 
    int max_len = 1;       

    int *curr_start = arr; 
    int curr_len = 1;

    for (int *p = arr + 1; p < arr + n; p++) {
        if (*p > *(p - 1)) {
            curr_len++;
        } else {
            if (curr_len > max_len) {
                max_len = curr_len;
                best_start = curr_start;
            }
            curr_start = p;
            curr_len = 1;
        }
    }


    if (curr_len > max_len) {
        max_len = curr_len;
        best_start = curr_start;
    }

    printf("\nНай-дълга нарастваща подредица:\n");
    for (int *p = best_start; p < best_start + max_len; p++) {
        printf("%d ", *p);
    }
    printf("\nДължина: %d\n", max_len);

    free(arr);
}

void zad7() {
    int n,search;
    int sum=0;
    printf("Въведете n: ");
    scanf("%d", &n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Въведете %d числа: ", n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", (arr+i));
    }
    printf("Въведете търсената сума: ");
    scanf("%d", &search);
    int start = 0; 
    int current_sum = 0;
    int found = 0;

    for (int end = 0; end < n; end++)
    {
        current_sum += arr[end];

        while (current_sum > search && start < end)
        {
            current_sum -= arr[start];
            start++;
        }
        if (current_sum == search)
        {
            printf("Намерена последователност: ");
            for (int i = start; i <= end; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Няма последователност с такава сума.\n");
    }

    free(arr);
}

void zad8() {
    int arr[20];
    int n; 
    printf("Колко числа искате да въведете първоначално (макс 20)? ");
    scanf("%d", &n);
    if (n > 20) n = 20;
    printf("Въведете %d числа:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Елемент [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int val, pos;
    while (n < 20)
    {
        printf("Въведете число (0 за край): ");
        scanf("%d", &val);
        if (val == 0) break; 
    
        printf("Въведете позиция: ");
        scanf("%d", &pos);

        if (pos < 0 || pos > n) {
            printf("Невалидна позиция!\n");
            continue;
        }
        for (int i = n; i > pos; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[pos] = val;
        n++; 
        if (n == 20)
        {
            printf("Масивът е запълнен!\n");
        }
    }

    printf("\nКраен резултат: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void zad9() {
    int n;
    printf("Въведете n: ");
    scanf("%d", &n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Въведете %d числа: ",n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", (arr+i));
    }
    int best_start_idx = 0; 
    int max_len = 1;        
    int curr_start_idx = 0; 
    int curr_len = 1; 

    for (int i = 1; i < n; i++)
    {

        if (arr[i] == arr[i - 1])
        {
            curr_len++;
        } 
        else
        {
            if (curr_len > max_len)
            {
                max_len = curr_len;
                best_start_idx = curr_start_idx;
            }
            curr_start_idx = i;
            curr_len = 1;
        }

        if (curr_len > max_len) {
        max_len = curr_len;
        best_start_idx = curr_start_idx;
        }
    }

    printf("Изход: ");
    for (int i = 0; i < max_len; i++) {
        printf("%d ", arr[best_start_idx + i]);
    }
    printf("\n");

    free(arr);    
}


int main()
{
    int choice;

    while(1) {
        printf("\nВъведете задача: ");      
        scanf("%d", &choice);

        if (choice == 0) break;

        switch (choice) {
            case 1: zad1(); break;
            case 2: zad2(); break;
            case 3: zad3(); break;
            case 4: zad4(); break;
            case 5: zad5(); break;
            case 6: zad6(); break;
            case 7: zad7(); break;
            case 8: zad8(); break;
            case 9: zad9(); break;
            default: printf("Невалиден избор! Опитайте пак.\n");
        }
    }
    return 0;
}