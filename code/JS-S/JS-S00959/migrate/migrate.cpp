#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 7;
int c, t, n, d, a[N], gl[N], gr[N], ans, fl[N], fr[N];
bool flag[N];

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> d;
        ans = 0;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        for (int i = 1, j = 1; i <= n; ++i)
        {
            while (j < n && a[j + 1] - a[i] <= d)
                ++j;
            gl[i] = j;
        }
        for (int i = n, j = n; i >= 1; --i)
        {
            while (j > 1 && a[i] - a[j - 1] <= d)
                --j;
            gr[i] = j;
        }
        for (int i = 1; i <= n; ++i)
        {
            fl[i] = 1;
            if (gr[i] > 1 && gl[gr[i - 1]] >= gr[i])
                for (int j = gr[i - 1]; j <= gr[i] - 1; ++j)
                    fl[i] += fl[j];
        }
        for (int i = n; i >= 1; --i)
        {
            fr[i] = 1;
            if (gl[i] < n && gr[gl[i - 1]] <= gl[i])
                for (int j = gl[i + 1]; j >= max(gr[i] + 1, gr[gl[i + 1]]); --j)
                    fr[i] += fr[j];
        }
        for (int i = 1; i <= n; ++i)
            if (gl[i] - i >= 2)
                for (int j = max(gl[i], gl[gl[i] - 2]) + 1; j <= gl[gl[i] - 1]; ++j)
                    ans += fl[i] * fr[j];
        cout << ans << endl;
    }

}
