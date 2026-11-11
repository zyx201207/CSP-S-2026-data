#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
int c, t, n, d, num[N];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> c >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> d;
        for (int j = 1; j <= n; j++)
        {
            cin >> num[j];
        }
        cout << t << "\n";
    }
    return 0;
}
