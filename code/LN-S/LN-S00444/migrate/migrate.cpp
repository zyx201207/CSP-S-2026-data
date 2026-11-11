#include <iostream>
#include <cstdio>
using namespace std;
using Int = long long;
const Int N = 2e6 + 12;
Int c, t, n, d, x[N];
bool flag = true;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> d;
        for (Int i = 1; i <= n; i++)
            cin >> x[i];
        for (Int i = 3; i <= n; i++)
            if (x[i] - x[i - 1] != x[i - 1] - x[i - 2])
                flag = false;
        if (flag)
        {
            if (d < 2 * x[2] - 2 * x[1])
            {
                cout << "0\n";
                continue;
            }
            cout << (x[n] - x[1]) / d + 1;
            continue;
        }
        cout << "0\n";
    }
    return 0;
}
