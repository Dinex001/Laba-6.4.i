#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>

using namespace std;

void Create(double* a, const int size, const double Low, const double High);
void Print(double* a, const int size);
double MaxAbs(double* a, const int size);
int IndexOfPositive(double* a, const int size, const int from);
double SumRange(double* a, const int first, const int last);
double SumBetweenFirstTwoPositives(double* a, const int size);
void MoveZerosToEnd(double* a, const int size);

int main()
{
    srand((unsigned)time(NULL));    // ініціалізація генератора випадкових чисел

    int n;
    cout << "n = ";
    cin >> n;

    double* a = new double[n];      // створили динамічний масив

    double Low = -3;
    double High = 3;

    Create(a, n, Low, High);
    Print(a, n);

    cout << "MaxAbs = " << fixed << setprecision(1) << MaxAbs(a, n) << endl;
    cout << "SumBetweenFirstTwoPositives = " << SumBetweenFirstTwoPositives(a, n) << endl;

    MoveZerosToEnd(a, n);
    Print(a, n);

    delete[] a;                     // знищили динамічний масив

    return 0;
}

// формування масиву випадковими числами з [Low; High] з кроком 0.5
void Create(double* a, const int size, const double Low, const double High)
{
    int count = (int)((High - Low) * 2) + 1;    // кількість можливих значень
    for (int i = 0; i < size; i++)
        a[i] = Low + (rand() % count) / 2.0;
}

// виведення масиву в рядок
void Print(double* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(6) << fixed << setprecision(1) << a[i];
    cout << endl;
}

// максимальний за модулем елемент масиву
double MaxAbs(double* a, const int size)
{
    double max = a[0];
    for (int i = 1; i < size; i++)
        if (fabs(a[i]) > fabs(max))
            max = a[i];
    return max;
}

// індекс першого додатного елемента, починаючи з номера from; -1, якщо такого немає
int IndexOfPositive(double* a, const int size, const int from)
{
    for (int i = from; i < size; i++)
        if (a[i] > 0)
            return i;
    return -1;
}

// сума елементів масиву з номерами від first до last
double SumRange(double* a, const int first, const int last)
{
    double s = 0;
    for (int i = first; i <= last; i++)
        s += a[i];
    return s;
}

// сума елементів, розташованих між першим і другим додатними елементами
double SumBetweenFirstTwoPositives(double* a, const int size)
{
    int first = IndexOfPositive(a, size, 0);
    if (first == -1)
        return 0;
    int second = IndexOfPositive(a, size, first + 1);
    if (second == -1)
        return 0;
    return SumRange(a, first + 1, second - 1);
}

// переставляє елементи, що дорівнюють нулю, в кінець масиву зі збереженням порядку інших
void MoveZerosToEnd(double* a, const int size)
{
    int j = 0;                      // позиція для наступного ненульового елемента
    for (int i = 0; i < size; i++)
        if (a[i] != 0)
        {
            a[j] = a[i];
            j++;
        }
    for (int i = j; i < size; i++)
        a[i] = 0;
}