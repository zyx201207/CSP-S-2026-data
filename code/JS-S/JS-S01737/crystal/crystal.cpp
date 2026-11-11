#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 7;

int n;
long long m;
long long a[MAXN], S[MAXN];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%d %lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        S[i] = S[i - 1] + a[i];
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        int l = 1, r = i;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (mid * a[i] - S[i] + S[i - mid] <= m)
                l = mid;
            else
                r = mid - 1;
        }
        ans = max(ans, l);
    }
    printf("%d\n", ans);
    return 0;
}