#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    string s , d , f , g;
    cin >> s >> d >> f >> g;
    if (s == f)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    if (d[1] == g[1])
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    if (f[2] == 'A' or f[2] == 'B' or f[2] == 'C' and g[2] != f[2] or g[2] != 'D' or g[2] != 'F')
    {
        if (f[2] == 'D' or f[2] == 'F' and g[2] != f[2] or g[2] != 'A' or g[2] != 'B' or g[2] != 'C')
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }

    return 0;
}
