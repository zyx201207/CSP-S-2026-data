#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2e6 + 10, INF = 1e9;
int f[N], c[N];
int cf1[N], cf2[N];
LL a[N];
int cnt1[N], cnt2[N];
int n;
LL d;

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int cidx, test;
    cin >> cidx >> test;
    if(cidx == 11 || cidx == 12)
    {
        while(test --)
        {
            scanf("%d%lld", &n, &d);
            for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
            if(n == 1)
            {
                puts("0");
                continue;
            }
            LL dx = a[2] - a[1];
            int len = d / dx;
            if(len <= 1)
            {
                puts("0");
                continue;
            }
            int g = len * 2 - 1;
            printf("%d\n", max(0, n - g));
        }
        return 0;
    }
    if(cidx == 13 || cidx == 14)
    {
        while(test --)
        {
            scanf("%d%lld", &n , &d);
            for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]), cnt1[i] = cnt2[i] = 0;
            int r = 0;
            LL ans = 0;
            for(int i = 1; i <= n; i ++)
            {
                while(r < n && a[r + 1] - a[i] <= d) r ++;
                if(r - i >= 2) cnt2[r] ++;
            }
            int l = n + 1;
            for(int i = n; i >= 1; i --)
            {
                while(l > 1 && a[i] - a[l - 1] <= d) l --;
                if(i - l >= 2) cnt1[l] ++;
            }
            for(int i = 1; i <= n - 1; i ++)
                ans += (LL)cnt1[i] * cnt2[i + 1];
            printf("%lld\n", ans);
        }
        return 0;
    }
    while(test --)
    {
        scanf("%d%lld", &n, &d);
        for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
        LL ans = 0;
        for(int i = 1; i <= n; i ++)
        {
            for(int j = i; j <= n; j ++) f[j] = INF, c[j] = 0, cf2[j] = 0;
            for(int j = 0; j <= n; j ++) cf1[j] = 0;
            f[i] = 0, c[i] = 1;
            cf1[0] = 1, cf2[i] = 1;
            int l = i;
            for(int j = i + 1; j <= n; j ++)
            {
                while(l < j && a[j] - a[l] > d) l ++;
                if(l == j) break;
                // printf("> %d %d\n", l, cf[f[l]]);
                f[j] = f[l] + 1;
                c[j] = cf1[f[l]] - cf2[l] + c[l];
                cf1[f[j]] += c[j];
                if(f[j] != f[j - 1]) cf2[j] = c[j];
                else cf2[j] = cf2[j - 1] + c[j];
                if(c[j] == 2) ans ++;
            }
            // for(int j = i; j <= n; j ++) printf("%d%c", f[j], " \n"[j == n]);
            // for(int j = i; j <= n; j ++) printf("%d%c", c[j], " \n"[j == n]);
            // for(int j = i; j <= n; j ++) printf("%d%c", idf[j], " \n"[j == n]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
// (g++ -std=c++14 -O2 -fsanitize=address,leak,undefined -Wall -Wextra -Wshadow -Wconversion migrate.cpp -o migrate && ./migrate && diff migrate.out migrate1.ans)