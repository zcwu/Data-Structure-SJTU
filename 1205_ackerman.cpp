#include <iostream>

using namespace std;

int A(int a, int b)
{
    if (a == 0) return b + 1;

    if (a != 0 && b == 0) A(a - 1, 1);

    if (a != 0 && b != 0) A(a - 1, A(a, b - 1));
}

int main()
{
    int m, n;

    cin >> m >> n;

    cout << A(m, n) << endl;

    return 0;
}
