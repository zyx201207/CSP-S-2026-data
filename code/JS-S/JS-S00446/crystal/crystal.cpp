#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n, m, a[N], f[N], c[N];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (long long i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (long long i = 1; i <= n; ++i)
    {
        c[i] = c[i - 1] + (i - 1) * (a[i] - a[i - 1]);
    }
    for (long long i = 1; i <= n; ++i)
    {
        for (long long j = n; j >= i; --j)
        {
            f[j] = max(f[j], f[j - 1]);
            if (c[j] - c[i - 1] <= m)
            {
                f[j] = max(f[j], j - i + 1);
            }
        }
        for (long long j = 1; j <= n; ++j)
        {
            c[j] = c[j] - a[j] + a[j - 1];
        }
    }
    cout << f[n] << endl;
    return 0;
}
