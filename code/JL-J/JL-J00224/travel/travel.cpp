#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a1, a2, a3, b1, b2, b3;
    cin >> a1 >> a2 >> b1 >> b2;
    if (a1 == b1)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    a3 = a2[0] + a2[1];
    b3 = b2[0] + b2[1];
    if (a3 == b3)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    int a4 = a2[2];
    int b4 = b2[2];
    if (a4 == 'A' || a4 == 'B' || a4 == 'C')
    {
        if (b4 == 'A' || b4 == 'B' || b4 == 'C')
        {
            cout << 1;
        }
    }
    else if (a4 == 'D' || a4 == 'E')
    {
        if (b4 == 'D' || b4 == 'E')
        {
            cout << 11;
            return 0;
        }
    }
    else
    {
        cout << 0;
    }
    char a5 = a2[2];
    char b5 = b2[2];
    if (a5 + 1 == b5 || b5 - 1 == a5)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
