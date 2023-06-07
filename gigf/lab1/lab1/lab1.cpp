//Задание 1
//Даны целые числа a1, a2. a3. Получить целочисленную матрицу B размерности 3x3, для которой b[i][j]=a[i]-3a[j]

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int a[3];
    const int n = 3;
    int B[n][n];
    cout << "Введите а1" << endl;
    cin >> a[0];
    cout << "Введите а2" << endl;
    cin >> a[1];
    cout << "Введите а3" << endl;
    cin >> a[2];
    // Вычисление матрицы B;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            B[i][j] = a[i] - 3 * a[j];;

    // Вывод матрицы B;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << B[i][j] << "\t";
        cout << endl;
    }
    system("pause");
    return 0;
}