#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum[500005];
long long maxx;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n;
    unsigned long long m;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (long long i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    bool vis;
    for (long long len = 1; len <= n; len++)
    {
        vis = 0;
        for (long long l = 1; l <= n - len + 1; l++)
        {
            long long lms = (sum[l + len - 1] - sum[l]) / len;
            long long ans = 0;
            for (long long i = l; i <= l + len - 1; i++)
            {
                ans += abs(a[i] - lms);
            }
            if (ans <= m)
            {
                maxx = max(maxx, len);
                vis = 1;
            }
        }
        if (vis)
            continue;
    }
    cout << maxx;
}
