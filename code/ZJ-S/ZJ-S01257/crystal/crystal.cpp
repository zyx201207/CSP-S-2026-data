#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int MN = 5e5;

int n;
ll m;
int nn;
ll a[MN + 10];
ll sa[MN + 10];
ll aa[MN + 10];
ll d[MN + 10];
int c[MN + 10];
ll cs[MN + 10];
ll ds[MN + 10];
ll ans;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", a + i);
        sa[i] = a[i];
    }
    if (n == 1)
    {
        printf("1\n");
        return 0;
    }
    sort(sa + 1, sa + n + 1);
    nn = unique(sa + 1, sa + n + 1) - sa - 1;
    for (int i = 1; i < nn; ++i)
    {
        d[i] = sa[i + 1] - sa[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        a[i] = lower_bound(sa + 1, sa + nn + 1, a[i]) - sa;
        ++c[a[i]];
    }
    for (int i = 1; i <= nn; ++i)
    {
        cs[i] = cs[i - 1] + c[i];
    }
    for (int i = 1; i < nn; ++i)
    {
        ds[i] = ds[i - 1] + d[i];
    }
    ans = max((ll)c[1], c[2] + min(m / d[1], (ll)c[1]));
    int j;
    ll s, ans_;
    if (m / d[1] < c[1])
    {
        j = 2;
        s = 0;
        ans_ = 0;
    }
    else
    {
        j = 1;
        s = d[1] * c[1];
        ans_ = c[1];
    }
    for (int i = 3; i <= nn; ++i)
    {
        s += d[i - 1] * (cs[i - 1] - cs[j - 1]);
        ans_ += c[i - 1];
        while (j < i && s > m)
        {
            s -= c[j] * (ds[i - 1] - ds[j - 1]);
            ans_ -= c[j];
            ++j;
        }
        ll x = ans_ + c[i] + min((m - s) / (ds[i - 1] - ds[j - 2]), (ll)c[j - 1]);
        ans = max(ans, x);
        // printf("%d %lld %lld %lld\n", j, s, ans_, x);
    }
    printf("%lld\n", ans);

    return 0;
}
