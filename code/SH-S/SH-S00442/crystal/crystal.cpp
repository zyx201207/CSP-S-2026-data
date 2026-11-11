#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e5 + 9;
int n, ans = 1;
LL a[N], m;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    int l = 1;
    LL sum = 0;
    for (int i = 2; i <= n; i++)
    {
        sum += (a[i] - a[i - 1]) * (i - l);
        while (sum > m)
        {
            sum -= a[i] - a[l];
            l++;
        }
        ans = max(ans, i - l + 1);
    }
    printf("%d", ans);
}
