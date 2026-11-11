#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int a1 = a[1] + a[0] * 10;
    int c1 = c[1] + c[0] * 10;
    bool flag = false;
    if (a1 == c1)
    {
        cout << 1;
        flag = true;
    }
    else
        cout << 0;
    int b1 = b[1] + a[0] * 10;
    int d1 = d[1] + d[0] * 10;
    bool fg = false;
    if (b1 == d1 && flag == true)
    {
		fg = true;
        cout << 1;
    }
    else
        cout << 0;
    char i = b[2];
    char j = d[2];
    bool f = false;
    if (b1 == d1 && fg == true && (i <= 'C' && j <= 'C') || (i >= 'D' && j >= 'D'))
    {
        cout << 1;
        f = true;
    }
    else
        cout << 0;
    if (f == true && abs(i - j) == 1)
        cout << 1;
    else
        cout << 0;
    return 0;
}
