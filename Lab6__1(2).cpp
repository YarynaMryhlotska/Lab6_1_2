#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* a, const int b, const int Low, const int High, int i)
{
        a[i] = Low + rand() % (High - Low + 1);
        if (i < b - 1)
            Create(a, b, Low, High, i + 1);
}

void Print(int* a, const int b, int i)
{
    cout << setw(4) << a[i];
    if (i < b - 1)
        Print(a, b, i + 1);
    else
        cout << endl;
}

int Number(int* a, const int b, int i, int number)
{
    if ((a[i] > 0 && (a[i] % 5) ==! 0) || (a[i] < 0))
        number++;
    if (i < b - 1)
        Number(a, b, i + 1, number);
    else
        return number;
}


void Zero(int* a, const int b, int i)
{
    if (i == b)
    {
        return;
    }
    if ((a[i] > 0 && (a[i] % 5) ==! 0) || (a[i] < 0))
    {
        a[i] = 0;
    }
    Zero(a, b, i + 1);
}

int Sum(int* a, const int b, int i)
{
    if (i < b)
    {
        if ((a[i] > 0 && (a[i] % 5) ==! 0) || (a[i] < 0))
            return a[i] + Sum(a, b, i + 1);
        else
            return Sum(a, b, i + 1);
    }
    else
        return 0;
}
  

int main()
{
    srand((unsigned)time(NULL));
    const int b = 22;
    int a[b];

    int low = -40;
    int High = 50;


    Create(a, b, low, High,0);
    Print(a, b, 0);

    cout << "Sum = " << Sum(a, b, 0) << endl;
    cout << "Number = " << Number(a, b, 0, 0) << endl;

    Zero(a, b, 0);
    Print(a, b, 0);
    return 0;
}