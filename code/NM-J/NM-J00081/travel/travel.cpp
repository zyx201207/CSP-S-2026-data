#include <bits/stdc++.h>
using namespace std;

string Rcx, Xcx;
string Rzw, Xzw;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> Rcx >> Rzw >> Xcx >> Xzw;

    if (Rcx == Xcx)
    {
        cout << "1";
    }
    else
    {
        cout << "0000";
        return 0;
    }


    if (Rzw[0] == Xzw[0] && Rzw[1] == Xzw[1])
    {
        cout << "1";
    }
    else
    {
        cout << "000";
        return 0;
    }

    if (((Rzw[2] == 'D' || Rzw[2] == 'F') && (Xzw[2] == 'D' || Xzw[2] == 'F')) || ((Rzw[2] == 'A' || Rzw[2] == 'B' || Rzw[2] == 'C') && (Xzw[2] == 'A' || Xzw[2] == 'B' || Xzw[2] == 'C')))
    {
        cout << "1";
    }
    else
    {
        cout << "00";
        return 0;
    }
    int c = int(Rzw[2] - Xzw[2]);
    c = abs(c);
    if (c <= 1)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }

    return 0;
}

