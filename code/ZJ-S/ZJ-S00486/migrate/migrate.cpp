#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e6+5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int c;
ll n, d;
ll x[MAXN], cf[MAXN];
int mxl[MAXN];
ll dis[MAXN], val[MAXN];

inline void solveA()
{
    if(d <= cf[1])
    {
        printf("0\n");
        return ;
    }
    printf("%lld\n", max(0LL, n - ((d / cf[1]) * 2 - 1)));
}

inline void solven_3()
{
    ll ans = 0;
    for(int l = 1; l <= n; l++)
    {
        val[l] = 1;
        for(int i = l+1; i <= n; i++)
        {
            ll curl = cf[i-1]; dis[i] = inf;
            val[i] = 0;
            for(int j = i-1; j >= l && curl <= d; j--)
            {
                if(dis[i] > dis[j]+1) dis[i] = dis[j]+1, val[i] = val[j];
                else if(dis[i] == dis[j]+1) val[i] += val[j];
                // cout<<i<<' '<<j<<' '<<dis[i]<<' '<<dis[j]<<endl;
                curl += cf[j];
            }
            if(val[i] == 2) ans++;
        }
    }
    printf("%lld\n", ans);
}

inline void solve()
{
    scanf("%lld%lld%lld", &n, &d, &x[1]);
    for(int i = 2; i <= n; i++) 
    {
        scanf("%lld", &x[i]);
        cf[i-1] = x[i] - x[i-1];
    }
    if(c == 11 || c == 12) { solveA(); return; }
    for(ll i = 1, j = 1, cur = 0; i <= n; i++)
    {
        for(; cur <= d; ) cur -= cf[j++];
        mxl[i] = j;
        cur += cf[i];
    }
    solven_3();
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int T;
    scanf("%d%d", &c, &T);
    for(; T--; ) solve();
    return 0;
}