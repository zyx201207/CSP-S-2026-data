#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, cnt;
long long a[500005];
long long check(long long s, long long x, long long b[])
{
    cnt = 0;
    for (int i = s; i >= 1 && x >= 0; --i)
    {
        if (b[s] - b[i] <= x)
        {
            ++cnt;
            x -= (b[s] - b[i]);
            b[i] = b[s];
        }
        else{
            break;
        }
    }
    return cnt;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n,&m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    if (n <= 5000)
    {
        for (int i = 1; i <= n; ++i)
        {

            ans = max(ans, check(i, m, a));
        }
        printf("%lld", ans);
        return 0;
    }
    else{
        long long p = a[n] - a[n - 1];
        ans += 1;
        if (p <= m)
        {

            ++ans;
            m -= p;
        }
        if (p <= m)
        {
            ++ans;
            m -= p;
        }
        for (int i = 2; i <= n && m >= 0 && ans < n; ++i)
        {

            if (p * i <= m){
                ++ans;
                m -= p * i;
            }
        }
        printf("%lld", ans);
        return 0;
    }
}
