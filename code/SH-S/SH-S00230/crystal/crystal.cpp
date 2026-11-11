#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 8;
typedef long long LL;
LL n, m, a[MAXN], b[MAXN], ans;
LL cnt = 0, ret = 0;

LL lsolve(LL l, LL r, LL t)
{
    if(l >= r)
        return ret;

    LL mid = (l + r) >> 1;
    cnt = 0;
    for(int i = 1; i < mid; i++)
    {
        LL tmp = a[mid] - a[i];
        if(tmp <= t)
            t -= tmp, b[i] += tmp;
    }

    for(int i = 1; i <= n; i++)
        if(b[i] == a[mid])
            cnt++;

    ret = max(ret, cnt);
    lsolve(l, mid, m);
}

LL rsolve(LL l, LL r, LL t)
{
    if(l >= r)
        return ret;

    LL mid = (l + r) >> 1;
    cnt = 0;
    for(int i = 1; i < mid; i++)
    {
        LL tmp = a[mid] - a[i];
        if(tmp <= t)
            t -= tmp, b[i] += tmp;
    }

    for(int i = 1; i <= n; i++)
        if(b[i] == a[mid])
            cnt++;

    ret = max(ret, cnt);
    lsolve(mid, r, m);
}

bool bovy(LL b[])
{
    LL d[MAXN];
    for(int i = 1; i <= n; i++)
        d[i] = b[i] - b[i - 1];
    LL k = d[1];
    for(int i = 2; i <= n; i++)
        if(k != d[i])
            return false;
    return true;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n; i++)
        b[i] = a[i];

    if(bovy(b))
    {
        LL d = b[2] - b[1];
        if(d == 1)
        {
            LL k = 1, sum = 0;
            while(sum + k <= m)
            {
                sum += k, k++;
            }
            return cout << k, 0;
        }
        else
        {
            return cout << (m / d), 0;
        }
    }

    ans = max(lsolve(1, n, m), rsolve(1, n, m));
    cout << ans;
    return 0;
}
