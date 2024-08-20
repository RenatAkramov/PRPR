

#include <stdio.h>
#include <math.h>

enum Eroot
{
    INF_ROOTS  = -1,
    ONE_ROOTS  =  1,
    ZERO_ROOTS =  0,
    TWO_ROOTS  =  2,

};

struct uravnenie
{
    double a;
    double b;
    double c;
};


int SolveSquare(struct uravnenie tom, double* x_1, double* x_2);

int sravnenie(double a);

int main()
{
    struct uravnenie tom;
     tom.a = 0, tom.b = 0, tom.c = 0;
     double x_1 = 0, x_2 = 0;

     int proverka = 0;
     proverka = scanf("%lg %lg %lg", &tom.a, &tom.b, &tom.c);

     if (proverka != 3)
     {
        printf("ERROR");
        return 1;
     }

 int nRoots = SolveSquare (tom, &x_1, &x_2);

    switch (nRoots)
    {
        case ZERO_ROOTS:
            printf("No roots\n");
            break;

        case ONE_ROOTS:
            printf("x_1 = %lg\n", x_1);
            break;

        case TWO_ROOTS:
            printf("x_1 = %lg , x_2 = %lg", x_1, x_2);
            break;

        case INF_ROOTS:
            printf(" Any number");
            break;

        default:
            printf("main(): ERROR:nRoots = %d\n", nRoots);
            break;
            return 1;
  }
}

int SolveSquare(uravnenie tom, double* x_1, double* x_2)
{
    double d;
    if (sravnenie(tom.a) == 1)
    {
        if (sravnenie(tom.b) == 1)
        {
            return -1;
        }
        else
        {
            *x_1=  -tom.c / tom.b;
        }
    }
    else
    {
        d = tom.b * tom.b - 4 * tom.a * tom.c;
            if (d < 0)
            {
                return 0;
            }
            if (sravnenie(d) == 1)
            {
                *x_1 = -tom.b / (2 * tom.a);
                return 1;
            }
            if ( d > 0)
            {
                *x_1 = (-tom.b + sqrt(d))/ (2 * tom.a);
                *x_2 = (-tom.b - sqrt(d))/ (2 * tom.a);
                return 2;
            }
    }
return 0;
}

int sravnenie(double a)
{
    const double smal = 0.000000001;
    if (fabsl( a - 0) < smal)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
