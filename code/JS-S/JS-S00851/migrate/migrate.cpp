#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int w[N];
long long ans = 0;
int c, t, n, d;
int l1 = 0, l2 = 0, r1 = 0, r2 = 0;

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        l1 = 0, l2 = 0, r1 = 0, r2 = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> w[i];
        for (int i = 4; i <= n; i++)
        {
            if (w[i - 1] - w[i - 3] <= d && w[i] - w[i - 2] <= d)
            {
                l1 = i - 3;
                ans += (l1 - r2) * (r1 - l2);
                swap(l1, l2);
                swap(r1, r2);
                swap(l2, r2);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
