#include <algorithm>
#include <cstdio>
int n;
long long m;
long long a[500010];
long long sum[500010];
bool check(int pos, int l)
{
    return a[pos] * l - (sum[pos - 1] - sum[pos - l - 1]) <= m;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d %lld", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    std::sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) sum[i] = a[i] + sum[i - 1];
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int l = 0, r = i - 1;
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(check(i, mid)) l = mid;
            else r = mid - 1;
        }
        ans = std::max(ans, l);
    }
    printf("%d", ans + 1);
    return 0;
}
// Finish at 14:54
