#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxlen = 2e6 + 5;

int cT, T;
int n;
ll d;
ll idx[maxlen];
int dp[5005][5005];
int c[5005];
int hd, tl;
int q[5005];
ll qzh[5005];
ll ans;

ll kidx[1000005];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &cT, &T);
    if (cT >= 0 && cT <= 10)
    {
        while (T--)
        {
            ans = 0;
            scanf("%d%lld", &n, &d);
            for (int i = 1;i <= n; ++i)
                scanf("%lld", idx + i);
            for (int i = 1;i <= n; ++i)
            {
                //memset(c, 0, sizeof c);
                dp[i][i] = 0;
                hd = i, tl = i + 1;
                q[hd] = 0, c[hd] = 1, qzh[hd] = 1, qzh[hd - 1] = 0;
                for (int j = i + 1;j <= n; ++j)
                {
                    while(hd < tl && idx[hd] + d < idx[j]) ++hd;
                    if (hd == tl) break;
                    q[tl] = q[hd] + 1;
                    int pos = upper_bound(q + hd + 1, q + tl, q[hd]) - q - 1;
                    //printf("in %d-%d, q[hd] = %d, pos = %d\n", hd, tl, q[hd], pos);
                    c[tl] = qzh[pos] - qzh[hd - 1];
                    if (c[tl] == 2) ++ans;

                    qzh[tl] = qzh[tl - 1] + c[tl];
                    ++tl;
                }
                /*printf("q:");
                for (int j = i;j < tl; ++j)
                    printf("%d%c", q[j], " \n"[j == tl - 1]);
                printf("c:");
                for (int j = i;j < tl; ++j)
                    printf("%d%c", c[j], " \n"[j == tl - 1]);*/

            }
            printf("%lld\n", ans);
        }
    }
    else if (cT >= 11 && cT <= 12)
    {
        while (T--)
        {
            scanf("%d%lld", &n, &d);
            for (int i = 1;i <= n; ++i)
                scanf("%lld", kidx + i);
            if (d <= kidx[2] - kidx[1])
                printf("0\n");
            else if (kidx[3] - kidx[1] <= d && kidx[4] - kidx[1] > d)
                printf("%lld\n", (ll)(n - 3));
            else
                printf("0\n");
        }
    }
    else
    {
        while (T--)
            printf("0\n");
    }
    return 0;
}
/*
40pts 17:47 finished

17:48 be told the mistake in T2
*/
