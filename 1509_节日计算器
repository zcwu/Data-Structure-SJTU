#include <iostream>

using namespace std;

bool judge(int m);
int firstDayOfYear(int m);
int firstDayOfMonth(int m, int n);

int main()
{
    int a, b, c, y1, y2;

    cin >> a >> b >> c >> y1 >> y2;

    int mon1[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int mon2[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int y = y1; y <= y2; ++y){
        int p = firstDayOfMonth(y, a);
        int sum = 0;

        if (c < p) sum = 8 - p + c;
        else sum = c - p + 1;

        for (int i = 1; i < b; ++i) sum += 7;

        if (judge(y)) {
            if (sum > mon1[a - 1]) cout << "none" << endl;
            else if (a < 10) {
                if (sum < 10) cout << y << '/' << 0 << a << '/' << '0' << sum << endl;
                else cout << y << '/' << 0 << a << '/' << sum << endl;
            }
                else {
                    if (sum < 10) cout << y << '/' << a << '/' << '0' << sum << endl;
                    else cout << y << '/' << a << '/' << sum << endl;
                }
        }
        else {
            if (sum > mon2[a - 1]) cout << "none" << endl;
            /*else if (a < 10) cout << y << '/' << 0 << a << '/' << sum << endl;
                else cout << y << '/' << a << '/' << sum << endl;*/
            else if (a < 10) {
                if (sum < 10) cout << y << '/' << 0 << a << '/' << '0' << sum << endl;
                else cout << y << '/' << 0 << a << '/' << sum << endl;
            }
                else {
                    if (sum < 10) cout << y << '/' << a << '/' << '0' << sum << endl;
                    else cout << y << '/' << a << '/' << sum << endl;
                }
        }
    }
    return 0;
}

bool judge(int m)
{
    if (m % 400 == 0) return true;

    if (m % 4 == 0 && m % 100 != 0) return true;

    return false;
}

int firstDayOfYear(int m)
{
    int sum = 0;

    for (int y = 1850; y < m; ++y){
        if (judge(y)) sum += 366;
        else sum += 365;
        //cout << y << endl;
    }
    int x = sum % 7;

    if (x + 2 <= 7) return (x + 2);
    else return (x - 5);

}

int firstDayOfMonth(int m, int n)
{
    bool flag = judge(m);
    int a = firstDayOfYear(m), b, sum = 0;
    int mon1[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int mon2[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (flag) {
        for (int i = 0; i < n - 1; ++i) sum += mon1[i];
    }
    else {
        for (int i = 0; i < n - 1; ++i) sum += mon2[i];
    }

    b = sum % 7;
    if (b + a <= 7) return (a + b);
    else return (a + b - 7);
}
