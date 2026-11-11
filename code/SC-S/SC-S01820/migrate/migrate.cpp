#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 2e6 + 9;

int tid, n, L[N], R[N];

LL a[N], d, ans;

namespace BF
{
    int f[N], g[N], S[N], rig[N];
    void main()
    {
        for (int s = 1;s <= n;++ s)
        {
            for (int i = 1;i <= n;++ i)
                f[i] = 1e9, S[i] = 0, g[i] = 0;
            f[s] = 0, S[s] = g[s] = 1, rig[0] = s;
            for (int i = s + 1;i <= n;++ i)
            {
                int l = max(L[i], s);
                if (f[l] >= 1e9)
                    break;
                int r = rig[f[l]];
                f[i] = f[l] + 1;
                g[i] = min(3, S[r] - S[l - 1]);
                S[i] = S[i - 1] + g[i];
                rig[f[i]] = i;
                ans += (g[i] == 2);
            }
        }
    }
}

namespace taskA
{
    void main()
    {
        int len = R[1];
        if (len > 2)
            ans = max(0, n - (2 * len - 2) + 1);
        else
            ans = 0;
    }
}

namespace CCC
{
    void main()
    {

    }
}

void solve()
{
    scanf("%d%lld", &n, &d);
    for (int i = 1;i <= n;++ i)
        scanf("%lld", &a[i]);
    a[0] = -2e18, a[n + 1] = 2e18;
    ans = 0;
    for (int i = 1, j = 1;i <= n;++ i)
    {
        while (a[i] - a[j] > d)
            ++ j;
        L[i] = j;
    }
    for (int i = n, j = n;i >= 1;-- i)
    {
        while (a[j] - a[i] > d)
            -- j;
        R[i] = j;
    }
    if (tid <= 10)
        BF::main();
    else if (tid <= 12)
        taskA::main();
    // else
    //     CCC::main();
    printf("%lld\n", ans);
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int T;
    scanf("%d%d", &tid, &T);
    while (T --)
        solve();

    return 0;
}