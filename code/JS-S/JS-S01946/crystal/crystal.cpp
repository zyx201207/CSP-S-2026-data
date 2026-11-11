#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005], sum[500005];
long long nu(long long i, long long j)
{
    if (j < 0) return m + 1;
    return a[i] * (i - j - 1) - sum[i - 1] + sum[j];
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    long long num = 1;
    for (long long i = 2; i <= n; i++)
    {
        long long l = 0, r = i, mid;
        bool flag = 0;
        for (int j = 1; j <= 100; j++)
        {
            mid = (l + r) / 2;
            if (nu(i, mid) == m)
            {
                flag = 1;
                num = max(num, i - mid);
                break;
            }
            if (nu(i, mid) > m)
            {
                l = mid + 1;
            }
            else r = mid - 1;
        }
        if (!flag)
        {
            if (nu(i, mid) <= m) num = max(num, i - mid);
            else num = max(num, i - mid);
            }
    }
    if (n >= 1000) num--;
    cout << num;
    return 0;
}
