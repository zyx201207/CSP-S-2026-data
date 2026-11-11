#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a, a1, b, b1;
    cin >> a >> a1 >> b >> b1;
    char x = a1[2], y = b1[2];
    if (a == b) cout << 1;
    else
    {
        cout << "0000" << endl;
        return 0;
    }
    if (a1[0] == b1[0] && a1[1] == b1[1]) cout << 1;
    else
    {
        cout << "000" << endl;
        return 0;
    }
    if ((x == 'A' && y == 'B') || (x == 'A' && y == 'C') || (x == 'B' && y == 'A') || (x == 'B' && y == 'C') || (x == 'C' && y == 'A') || (x == 'C' && y == 'B') || (x == 'D' && y == 'F') || (x == 'F' && y == 'D')) cout << 1;
    else
    {
        cout << "00" << endl;
        return 0;
    }
    if ((x == 'A' && y == 'B') || (x == 'B' && y == 'A') || (x == 'B' && y == 'C') || (x == 'C' && y == 'B') || (x == 'D' && y == 'F') || (x == 'F' && y == 'D')) cout << 1;
    else cout << "0";
    return 0;
}
