/*!
    @file   main.cpp

    @author Renat
    @date   22/08/2024
    @brief  solver

*/


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
/*!
*    @brief ��������� � ������������� ���������
*    @param a  ������ ���������� ���������
*    @param b  ������ ���������� ���������
*    @param c  ������ ������ ���������
*/
struct uravnenie
{
    double a;
    double b;
    double c;
};

/*!  @brief                ��������� � ������� ��� ������
*    @param a              ������ ���� ���������
*    @param b              ������ ���������� ���������
*    @param c              ������ ��������� ���������
*    @param x1Expected     ��������� ������ ������
*    @param x2Expected     ��������� ������ ������
*    @param nRootsExpeted  ��������� ���������� ������
*/
struct testiki
{
    int nTest;
    double a;
    double b;
    double c;
    double x1Expected;
    double x2Expected;
    int nRootsExpected;
};


int SolveSquare(struct uravnenie tom, double* x_1, double* x_2);

int RunTests(struct testiki tests);

int sravneniedvuh(double a, double b);

int checktest(const testiki* test);

/*!
*    @brief �������� �������, ��������� �������� �� ������� ������� ���������, �������� ������ � ������ �� ������������
*    @return �����
*/
int main()
{
     struct testiki Tests1 = {1, 1,4,-5,-5,1,2};
     struct testiki Tests2 = {2,2,0,0,0,0,1};
     struct testiki Tests3 = {3,0,0,0,0,0,-1};
     struct testiki Tests4 = {4,0,2,0,0,0,1};
     struct testiki Tests5 = {5,1,-5,6,2,3,2};
     struct testiki Tests6 = {6,3,1,2,0,0,0};
     struct testiki Tests7 = {7,-1,1,0,1,0,2};
     struct testiki Tests8 = {8,0,0,1,0,0,-1};
     struct testiki tests[8] = {Tests1, Tests2, Tests3, Tests4, Tests5, Tests6, Tests7, Tests8};

     int nachalo = 0, pravilnost = 0;

     printf("��� ������� ��������� ������� 1 \n��� ���������� ������ ������� 2\n");

     scanf("%d", &nachalo);

     if (nachalo == 1)
     {
        printf("������� �����������\n");

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
        pravilnost = checktest(&tests[0]);
        if (pravilnost == OKEY)
        {
            printf("��� ����� �������� �����");
        }
        return 1;
    }
}

/*!
*    @brief ���������� ���������� ������ � ������ ���������
*    @param uravnenie �������� � ������������� ���������
*    @param x_1 ������ ������
*    @param x_2 ������ ������
*/
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

/*!
*    @brief ���������� 2 ��������������� �����
*    @param a ������ �����
*    @param b ������ �����
*/
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

/*!
*    @brief ������� ����������� �����
*    @param Tests1 ������ ����
*    @param Tests2 ������ ����
*    @param Tests3 ������ ����
*    @param Tests4 ��������� ����
*    @param Tests5 ����� ����
*    @param Tests6 ������ ����
*    @param Tests7 ������� ����
*    @param Tests8 ������� ����
*/
int checktest( const testiki* tests)
{
    int n = 0;

    for(int i = 0; i < 8; i++)
    {
        n = RunTests(tests[i]);
    }
    return n;
}

/*!
*    @brief ������� ����������� �����
*    @param nTest   ����� �����
*    @param �       ������ ���������� ���������
*    @param x_2     ������ ������
*/
int RunTests(struct testiki test)
{
    //printf("[%lg]\n", test.a);
    struct uravnenie tomt;
    tomt.a = test.a;
    tomt.b = test.b;
    tomt.c = test.c;

    double x1t = 0, x2t = 0;

    int nRootsT = SolveSquare(tomt, &x1t, &x2t);

    if (sravneniedvuh(nRootsT, test.nRootsExpected) == 0 || sravneniedvuh(x1t, test.x1Expected) == 0 || sravneniedvuh(x2t, test.x2Expected) == 0)
    {
        printf("ERROR TEST %d, a = %lg, b = %lg, c = %lg, x1= %lg, x2 =%lg\n"
               "Expected x1 = %lg, x2 = %lg\n",
                test.nTest, test.a, test.b, test.c, x1t, x2t, test.x1Expected, test.x2Expected);
        return WRONG;
    }
    else
    {
        return OKEY;
    }
}




























