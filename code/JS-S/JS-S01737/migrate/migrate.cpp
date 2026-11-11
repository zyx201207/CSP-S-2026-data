#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 7;

int n;
long long d, x[MAXN];

int step[MAXN];
int cnt[MAXN], cnt_sum[MAXN];

inline void solve()
{
    scanf("%d %lld", &n, &d);
    for (int i = 1; i <= n; i++)
        scanf("%lld", x + i);
    long long ans = 0;
    for (int k = 1; k <= n; k++)
    {
        int cur_step = 1, last_step_l = k, last_step_r = k;
        cnt_sum[k - 1] = 0;
        cnt_sum[k] = 1;
        for (int i = k + 1; i <= n; i++)
        {
            if (x[i] > x[last_step_r] + d)
            {
                if (x[i] - x[i - 1] > d)
                    goto kel;
                cur_step++;
                last_step_l = last_step_r + 1;
                last_step_r = i - 1;
            }
            step[i] = cur_step;
            while (x[i] - x[last_step_l] > d)
                last_step_l++;
            cnt[i] = cnt_sum[last_step_r] - cnt_sum[last_step_l - 1];
            cnt_sum[i] = cnt_sum[i - 1] + cnt[i];
            if (cnt[i] == 2)
                ans++;
        }
    kel:;
    }
    printf("%lld\n", ans);
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    scanf("%d %d", &c, &t);
    while (t--)
        solve();
    return 0;
}