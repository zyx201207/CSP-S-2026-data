#include <bits/stdc++.h>
#define cyn cin
using namespace std;

const int N = 2100000;

long long a[N];
int dpl[N], dpr[N];
long long ls[N], rs[N];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cyn.tie(0);
    cout.tie(0);
    int c, t;
    cyn >> c >> t;
    while (t--)
    {
        int n;
        long long d, ans = 0;
        cyn >> n >> d;
        for (int i = 1; i <= n; i++)
            cyn >> a[i];
        a[n + 1] = LLONG_MAX;
        int l = 1, r = n;
        for (int i = 1; i <= n; i++)
        {
            while (a[l] + d < a[i])
                l++;
            if (l == i || a[i + 1] - a[i - 1] <= d)
            {
                dpl[i] = 1;
                continue;
            }
            if (l == i - 1)
                dpl[i] = dpl[l] + 1;
            else
                dpl[i] = i - l + 1;
        }
        for (int i = n; i; i--)
        {
            while (a[i] + d < a[r])
                r--;
            if (r == i || a[i + 1] - a[i - 1] <= d)
            {
                dpr[i] = 1;
                continue;
            }
            if (r == i + 1)
                dpr[i] = dpr[r] + 1;
            else
                dpr[i] = r - i + 1;
        }
        for (int i = 1; i <= n; i++)
            ls[i] = ls[i - 1] + dpl[i];
        for (int i = n; i; i--)
            rs[i] = rs[i + 1] + dpr[i];
        int cl1, cr1, cl2, cr2;
        for (int i = 2; i < n - 1; i++)
            if (a[i] + d > a[i + 1])
            {
                cl1 = lower_bound(a + 1, a + 2 + n, a[i + 1] - d) - a;
                cr1 = lower_bound(a + 1, a + 2 + n, a[i + 2] - d) - a;
                cr1--;
                cl2 = upper_bound(a + 1, a + 2 + n, a[i - 1] + d) - a;
                cr2 = upper_bound(a + 1, a + 2 + n, a[i] + d) - a;
                cr2--;
                if (cl1 <= cr1 && cr1 < i && i + 1 < cl2 && cl2 <= cr2 && cr2 <= n)
                    ans += (ls[cr1] - ls[cl1 - 1]) * (rs[cl2] - rs[cr2 + 1]);
            }
        cout << ans << "\n";
    }
    return 0;
}