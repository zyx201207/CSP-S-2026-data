#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10;
int n, ans = 1; ll m;
ll a[N], pre[N];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", a + i);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        pre[i] = pre[i - 1] + a[i];
    bool ftr = 1;
    for (int i = 2; i <= n; ++i)
        if (a[i] - a[i - 1] != a[2] - a[1])
            { ftr = 0; break; }
    if (ftr)
    {
        int D = a[2] - a[1];
        int l = 0, r = n + 5;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            ll s = ll(mid) * (mid + 1) * D;
            if (s <= 2 * m)
                l = mid + 1;
            else
                r = mid - 1;
        }
        printf("%d\n", min(r, (int)(n - 1)) + 1);
        return 0;
    }
    if (n <= 5000)
    {
        for (int l = 1; l <= n; ++l)
        {
            for (int r = l + 1; r <= n; ++r)
            {
                ll s = (ll)a[r] * (r - l + 1) - pre[r] + pre[l - 1];
                if (s <= m)
                    ans = max(ans, r - l + 1);
            }
        }
        printf("%d\n", ans);
        return 0;
    }
    for (int tgt = -100; tgt <= 100; ++tgt)
    {
        int mx = upper_bound(a + 1, a + n + 1, tgt) - a - 1;
        if (a[mx] != tgt)
            continue;
        int l = 1, r = mx;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            ll s = (ll)a[mx] * (mx - mid + 1) - pre[mx] + pre[mid - 1];
            if (s <= m)
                r = mid - 1;
            else
                l = mid + 1;
        }
        ans = max(ans, mx - l + 1);
    }
    printf("%d\n", ans);
    return 0;
}

// 14:58 +30pts from #13~18(feature A & B)
// 14:58~15:09 wo chang chang zhui yi guo qu
// 15:40 +45pts from #1~9(n <= 5000)
// 16:00 +15pts from #10~12(-100 <= a[i] <= 100)
// T1 : (maybe?)90pts within 1.5h, with hands shaking(I'm nervous)
// I'm too weak to reach 1=.