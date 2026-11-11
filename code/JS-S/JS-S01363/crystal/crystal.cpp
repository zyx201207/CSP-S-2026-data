#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxlen = 5e5 + 5;
int n;
ll m;
ll a[maxlen];
ll d[maxlen];
int ans = -1;
ll lrsum(int kl, int kr)
{
    if (kl > kr) return 0;
    return d[kr] - d[kl - 1];
}
bool FindAns(int kl, int kr)
{
    if (kl == kr) return true;
    ll lrm = 0;
    lrm = a[kr] * (kr - kl + 1) - lrsum(kl, kr);
    return lrm <= m;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1;i <= n; ++i)
        scanf("%lld", a + i);
    sort(a + 1, a + 1 + n);
    for (int i = 1;i <= n; ++i)
        d[i] = d[i - 1] + a[i];//For sum of[l,r]
    int l = 1, r = 1;
    bool flag;
    while (r <= n && l <= n)
    {
        flag = FindAns(l, r);
        if (flag)
            ans = max(r - l + 1, ans), ++r;
        else
            ++l;
    }
    printf("%d", ans);
    return 0;
}
//csps-new.zip down.zip modified 2026.10.31 10:16
/*
the key announciation was delayed as usual

problem crystal

all test passed at 15:08
*/
