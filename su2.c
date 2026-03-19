#include <stdio.h>
#include<stdlib.h>
#include <math.h>

int getMax(int a, int b)
{
    if (a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
    
}

int getMin(int a, int b)
{
    if (a<b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

void zad1()
{
    int n,max,min;
    printf("ВЪведете числа (0 за край): \n");
    scanf("%d", &n);
    if (n!=0)
    {
        max=min=n;
        while(scanf("%d", &n)&&n!=0)
        {            
            getMax(max,n);
            getMax(min,n);
        }
        printf("Най-голямо: %d\n", max);
        printf("Най-малко: %d\n", min);
    }    
}

void zad2()
{
    int h,min;
    printf("Въведете часов и минути: ");
    scanf("%d %d",&h, &min );
    min+=15;
    if(min>=60)
    {
        min-=60;
        h+=1;
    }
    if(h>23)
    {
        h=0;
    }
    printf("%d:%02d\n", h, min);

}
void zad3()
{
    int a,b,c;
    printf("Въведете три числа: ");
    scanf("%d %d %d", &a, &b, &c);
    if(a==b && b==c)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
}

void zad4()
{
    int points;
    printf("Въведете брой точки: ");
    scanf("%d", &points);
    float bonus=0;
    if(points<=100)
    {
        bonus=5;
    }
    else if(points>100 && points<1000)
    {
        bonus=0.2*points;
    }
    else if(points>1000)
    {
        bonus=0.1*points;
    }
    if (points%2==0)
    {
        bonus+=1;
    }
    if(points%10==5)
    {
        bonus+=2;
    }
    printf("%.1f бонус точки\n", bonus);
    printf("%.1f общо точки\n", points+bonus);

}

void zad5()
{
    int t1, t2, t3;
    printf("Въведете трите времена в ссекунди(между 1 и 50): ");
    scanf("%d %d %d", &t1, &t2, &t3);
    int total=t1+t2+t3;
    int min=total/60;
    int sec=total%60;
    printf("%d:%02d\n", min, sec);
}

void zad6()
{
    float x, y, x1, y1, x2, y2;
    printf("Въведете x1: ");
    scanf("%f", &x1);
    printf("Въведете y1: ");
    scanf("%f", &y1);
    printf("Въведете x2(по- голямо от x1): ");
    scanf("%f", &x2);
    printf("Въведете y2по- голямо от y2: ");
    scanf("%f", &y2);
    printf("Въведете x: ");
    scanf("%f", &x);
    printf("Въведете y: ");
    scanf("%f", &y);
    if(x1 < x2 && y1 < y2)
    {
        if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
        {
            printf("Inside\n");
        }
        else
        {
        printf("Outside\n");
        }
    }
    else
    {
        printf("Невалидни координати!\n");
    }
}

void zad7()
{
    int n;
    char time;
    printf("Въведете километри и период(D/N): ");
    scanf("%d %c", &n, &time);
    double priceTaxi=0.70;
    if(time =='D')
    {
        priceTaxi+=n*0.79;
    }
    else 
    {
        priceTaxi+=n*0.90;
    }
    double cheapest=priceTaxi;
    if (n>20)
    {
        double priceBus=n*0.09;  
        if(cheapest>priceBus)
        {
            cheapest=priceBus;
        }    
    }
    if(n>=100)
    {
        double priceTrain=n*0.06;
        if(cheapest>priceTrain)
        {
            cheapest=priceTrain;
        } 
    }
    printf("Цената на най- евтиния транспорт е %.2f\n", cheapest);
}

void zad8()
{
    int V, P1, P2;
    double H;
    printf("ВЪведете обем, дебит на двете тръби и часове: ");
    scanf("%d %d %d %lf", &V, &P1, &P2, &H);

    double waterFromP1 = P1 * H;
    double waterFromP2 = P2 * H;
    double totalWater = waterFromP1 + waterFromP2;

    if (totalWater <= V)
    {
        int percentFull = (totalWater / V) * 100;
        int p1Percent = (waterFromP1 / totalWater) * 100;
        int p2Percent = (waterFromP2 / totalWater) * 100;
        printf("Басейнът е %d%% пълен. Тръба 1: %d%%. Тръба 2: %d%%.\n", percentFull, p1Percent, p2Percent);
    }
    else
    {
        printf("За %.1f часа басейнът ще се напълни с  %.1f литра.\n", H, totalWater - V);
    }
}

void zad9()
{
        int X, Z, workers;
    double Y;
    printf("Въведете кв.м, грозде за кв.м, нужно вино, брой работници: ");
    scanf("%d %lf %d %d", &X, &Y, &Z, &workers);

    double totalGrapes = X * Y;
    double wineProduced = (0.40 * totalGrapes) / 2.5;

    if (wineProduced >= Z)
    {
        double remainder = wineProduced - Z;
        printf("Общо вино: %.0f литра.\n", floor(wineProduced));
        printf("%.0f оставащи литра -> %.0f литър за работник.\n", 
                ceil(remainder), ceil(remainder / workers));
    }
    else
    {
        printf("Нужни са още %.0f литра вино.\n", 
                floor(Z - wineProduced));
    }
}

void zad10()
{
    int n;
    printf("Колко числа ще въведете: ");
    scanf("%d", &n);
    double p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0;

    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        if (num < 200)
        {
            p1++;
        }
        else if (num <= 399)
        {
            p2++;
        }
        else if (num <= 599)
        {
            p3++;
        }
        else if (num <= 799)
        {
            p4++;
        }
        else
        {
            p5++;
        }
    }
    printf("Процент под 200: %.2f%%\n", (p1 / n) * 100);
    printf("Процент от 200 до 399: %.2f%%\n", (p2 / n) * 100);
    printf("Процент от 400 до 599: %.2f%%\n", (p3 / n) * 100);
    printf("Процент от 600 до 799: %.2f%%\n", (p4 / n) * 100);
    printf("Процент от 800 нагоре: %.2f%%\n", (p5 / n) * 100);
}

void zad11()
{
    int n;
    printf("Въведете число: ");
    scanf("%d", &n);

    int colWidth = n / 2;          
    int midWidth = 2 * n - 2 * colWidth - 4; 
    printf("/");
    for (int i = 0; i < colWidth; i++) printf("^");
    printf("\\");
    
    if (midWidth > 0) {
        for (int i = 0; i < midWidth; i++) printf("_");
    }
    
    printf("/");
    for (int i = 0; i < colWidth; i++) printf("^");
    printf("\\\n");
    for (int i = 0; i < n - 2; i++) {
        printf("|");
        if (i == n - 3 && midWidth > 0) {
            for (int j = 0; j < colWidth + 1; j++) printf(" ");
            for (int j = 0; j < midWidth; j++) printf("_");
            for (int j = 0; j < colWidth + 1; j++) printf(" ");
        } else {
            for (int j = 0; j < 2 * n - 2; j++) printf(" ");
        }
        
        printf("|\n");
    }

    printf("\\");
    for (int i = 0; i < colWidth; i++) printf("_");
    printf("/");
    
    if (midWidth > 0) {
        for (int i = 0; i < midWidth; i++) printf(" ");
    }
    
    printf("\\");
    for (int i = 0; i < colWidth; i++) printf("_");
    printf("/\n");
}

void zad12()
{
    int n;
    printf("Въведете число: ");
    scanf("%d", &n);
    int wingSize = n - 2;
    for (int i = 0; i < wingSize; i++) {
        char symbol = (i % 2 == 0) ? '*' : '-';
        for (int j = 0; j < wingSize; j++) printf("%c", symbol);
        printf("\\ /");
        for (int j = 0; j < wingSize; j++) printf("%c", symbol);
        printf("\n");
    }
    for (int i = 0; i < wingSize + 1; i++)
    {
        printf(" ");
        printf("@\n");
    }

    for (int i = 0; i < wingSize; i++)
    {
        char symbol = (i % 2 == 0) ? '*' : '-';
        for (int j = 0; j < wingSize; j++) printf("%c", symbol);
        printf("/ \\");
        for (int j = 0; j < wingSize; j++) printf("%c", symbol);
        printf("\n");
    }
}


int main()
{
    int choice;
    while(1)
    {
        printf("Изберете задача: ");
        scanf("%d", &choice);
        if (choice==0)
        {
            break;
        }
        switch (choice)
        {
            case 1:
                zad1();
                break;
            case 2:
                zad2();
                break;
            case 3:
                zad3();
                break;
            case 4:
                zad4();
                break;
            case 5:
                zad5();
                break;
            case 6:
                zad6();
                break;
            case 7:
                zad7();
                break;
            case 8:
                zad8();
                break;
            case 9:
                zad9();
                break;
            case 10:
                zad10();
                break;
            case 11:
                zad11();
                break;
            case 12:
                zad12();
                break;
            default:
                printf("Моля въведете валидна задача!");
                break;
        }
    }    
    return 0;
}