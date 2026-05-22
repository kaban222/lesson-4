#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    double Sa = 0.0;
    for (int n = 1; n <= 23; n++)
    {
        Sa += pow(2.0, -n) * cos(M_PI * n / 4.0);
    }

    cout << "a) Сумма ряда = " << Sa << endl;


    // ---------------- b ----------------

    double maxVal = -1e100;
    int maxIndex = 1;

    for (int i = 1; i <= 25; i++)
    {
        double ui = 5 * sqrt(i) * exp(-0.03 * i);
        if (ui > maxVal)
        {
            maxVal = ui;
            maxIndex = i;
        }
    }

    cout << "b) Максимальный элемент = " << maxVal
         << ", номер = " << maxIndex << endl;


    // ---------------- c ----------------

    const double x = 2.0;
    const double eps = 1e-6;

    int i = 1;

    double term = -1.0 / (2.0 * 2.0);
    double Sc = term;

    while (fabs(term) > eps)
    {

        term *= -x * (i + 1.0) /
                ((i + 2.0) * (2.0 * i + 2.0) * (2.0 * i + 1.0));

        Sc += term;
        i++;
    }

    cout << "c) Сумма ряда = " << Sc << endl;


    // ---------------- d ----------------

    double A_prev = 0.1;
    double A_curr = 1.0;
    double A_next;

    int n = 1;

    do
    {
        n++;
        A_next = (double)(n - 1) / n * A_curr
               + 1.0 / (n - 1) * A_prev;

        A_prev = A_curr;
        A_curr = A_next;

    } while (A_curr <= 1.0);

    cout << "d) Первый номер n, при котором A_n > 1: " << n << endl;

    return 0;
}
