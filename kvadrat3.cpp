#include <stdio.h>
#include <math.h>
#include <TXLib.h>

enum Eroot
{
    INF_ROOTS  = -1,
    ONE_ROOTS  =  1,
    ZERO_ROOTS =  0,
    TWO_ROOTS  =  2,
    WRONG      =  1,
    OKEY       =  0
};

struct uravnenie
{
    double a;
    double b;
    double c;
};

//////////////////////////////////////////////////////////////////////////
///\brief  This metod solves square cnatches
///\param uravnenie contains coefficients
///\param x_1 The first root
///\param x_2 The second root
///\
///
///
//////////////////////////////////////////////////////////////////////////
int SolveSquare(struct uravnenie, double* x_1, double* x_2);

int RunTests(int nTest, double a, double b, double c,double x1Expected, double x2Expected, int nRootsExpected);

int sravnenie(double a);

int sravneniedvuh(double a, double b);

void checktest();

int main()
{
     int nachalo = 0;
     printf("Для решения уравнения нажмите 1 \nДля проведения тестов нажмите 2\n");
     scanf("%d", &nachalo);
     if (nachalo == 1)
     {
        printf("Введите коэфициенты\n");

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
    if (nachalo ==2)
    {
        checktest();
        printf("Ok");
        return 1;
    }
}

int SolveSquare(uravnenie tom, double* x_1, double* x_2)
{
    double d = 0, smena = 0;
    if (sravneniedvuh(tom.a, 0) == 1)
    {
        if (sravneniedvuh(tom.b, 0) == 1)
        {
            return -1;
        }
        else
        {
            *x_1=  -tom.c / tom.b;
            return 1;
        }
    }
    else
    {
        if (sravneniedvuh(tom.b, 0) == 1)
        {
            if (sravneniedvuh(tom.c, 0) == 1)
            {
                *x_1 = 0;
                return 1;
            }
            else
            {
                if (-tom.c/tom.a > 0)
                {
                    *x_1 = -sqrt(-tom.c/tom.a);
                    *x_2 = sqrt(-tom.c/tom.a);
                    return 2;
                }
                else
                {
                return 0;
                }
            }
        }

        else
        {
            d = tom.b * tom.b - 4 * tom.a * tom.c;
                if (d < 0)
                {
                    return 0;
                }
                if (sravneniedvuh(d, 0) == 1)
                {
                    *x_1 = -tom.b / (2 * tom.a);
                    return 1;
                }
                if ( d > 0)
                {
                    *x_1 = (-tom.b - sqrt(d))/ (2 * tom.a);
                    *x_2 = (-tom.b + sqrt(d))/ (2 * tom.a);
                    return 2;
                }
        }
    }
return 0;
}


int sravneniedvuh(double a, double b)
{
    const double smal = 0.000000001;
    if (fabsl( a - b) < smal)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



int RunTests(int nTest, double a, double b, double c, double x1Expected, double x2Expected, int nRootsExpected)
{
    struct uravnenie tomt;
    tomt.a = a, tomt.b = b, tomt.c = c;

    double x1t = 0, x2t = 0;

    int nRootst = SolveSquare(tomt, &x1t, &x2t);

    if (sravneniedvuh(nRootst, nRootsExpected) == 0 || sravneniedvuh(x1t, x1Expected) == 0 || sravneniedvuh(x2t, x2Expected) == 0)
    {
        printf("ERROR TEST %d, a = %g, b = %g, c = %g, x1= %lg, x2 =%lg\n"
               "Expected x1 = %lg, x2 = %lg\n",nTest, a, b, c, x1t, x2t, x1Expected, x2Expected);
        return WRONG;
    }
    else
    {
        return OKEY;
    }
}

void checktest()
{
    RunTests(1,1,4,-5,-5,1,2);
    RunTests(2,2,0,0,0,0,1);
    RunTests(3,0,0,0,0,0,-1);
    RunTests(4,0,2,0,0,0,1);
    RunTests(5,1,-5,6,2,3,2);
    RunTests(6,3,1,2,0,0,0);
    RunTests(7,-1,1,0,1,0,2);
    RunTests(8,0,0,1,0,0,-1);
}



























