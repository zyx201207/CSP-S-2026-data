#include <bits/stdc++.h>
using namespace std;

int a, b;
char cc[4], dd[4];
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> a;
    scanf("%s", cc + 1);
    cin >> b;
    scanf("%s", dd + 1);

    if (a == b) cout << 1;
    else cout << 0;
    if (a == b && cc[1] == dd[1] && cc[2] == dd[2]) cout << 1;
    else cout << 0;

    if (a == b && cc[1] == dd[1] && cc[2] == dd[2])
    {
        if ('A' <= cc[3] && cc[3] <= 'C' && 'A' <= dd[3] && dd[3] <= 'C')
        {
            cout << 1;
            if (abs(cc[3] - dd[3]) == 1) cout << 1;
            else cout << 0;
        }
        else if ('D' <= cc[3] && cc[3] <= 'F' && 'D' <= dd[3] && dd[3] <= 'F')
        {
            cout << 1;
            if (abs(cc[3] - dd[3]) == 1) cout << 1;
            else cout << 0;
        }
        else cout << 0 << 0;
    }
    else cout << 0 << 0;
    return 0;
}
