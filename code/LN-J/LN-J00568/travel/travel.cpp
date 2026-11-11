#include <iostream>
#include <cstdio>
using namespace std;
using Int = long long;
Int a, b;
string c, d;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> c >> b >> d;
    if (a != b)
    {
        cout << "0000";
        return 0;
    }
    if (c[0] != d[0] || c[1] != d[1])
    {
        cout << "1000";
        return 0;
    }
    if (c[2] == 'A')
    {
        if (d[2] == 'B')
            cout << "1111";
        else if (d[2] == 'C')
            cout << "1110";
        else if (d[2] == 'D' || d[2] == 'F')
            cout << "1100";
    }
    else if (c[2] == 'B')
    {
        if (d[2] == 'A' || d[2] == 'C')
            cout << "1111";
        else
            cout << "1100";
    }
    else if (c[2] == 'C')
    {
        if (d[2] == 'A')
            cout << "1110";
        else if (d[2] == 'B')
            cout << "1111";
        else if (d[2] == 'D' || d[2] == 'F')
            cout << "1100";
    }
    else if (c[2] == 'D')
    {
        if (d[2] == 'F')
            cout << "1111";
        else
            cout << "1100";
    }
    else if (c[2] == 'F')
    {
        if (d[2] == 'D')
            cout << "1111";
        else
            cout << "1100";
    }
    return 0;
}
