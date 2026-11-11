#include<bits/stdc++.h>
using namespace std;
int c, t;
int x[2000005];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> c >> t;
    for (int i = 1; i <= t; i++)
    {
        int n, d;
        cin >> x[i];
        if ((x[1] - x[2]) == (x[2] - x[3]) == (x[3] - x[4]))
        {
            if (d < 2 * n) cout << 0 << endl;
            else
            {
                int a = d / (x[2] - x[1]);
                cout << ((n - 1) / 3) / a << endl;
            }
        }
    }
    return 0;
}
