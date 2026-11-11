#include<bits/stdc++.h>
using namespace std;
using itn = int;
using ll = int64_t;
#define endl '\n'
#define file "migrate"
template<typename T> void read(T &d)
{
    T x = 0; char ch;
    do ch=getchar_unlocked(); while (isspace(ch));
    do x=x*10+ch-'0', ch=getchar_unlocked(); while (isdigit(ch));
    d = x;
}
template<typename T> void readneg(T &d)
{
    T x = 0; char ch; bool neg;
    do ch=getchar_unlocked(); while (isspace(ch));
    neg = ch == '-'; if (neg) ch = getchar();
    do x=x*10+ch-'0', ch=getchar_unlocked(); while (isdigit(ch));
    d = neg ? -x : x;
}
const int maxn = 2000083;
ll x[maxn]; int dis[maxn], cnt[maxn], lst[maxn], ld[maxn], nxt[maxn];
int C;
ll solve_sp1(int n)
{
    int i = 1, j;
    ll ans = 0;
    fill(ld, ld+n, 0);
    dis[i] = 0; ld[0] = i; cnt[i] = 1; cnt[i-1] = 0;
    for (j=i+1; j<=n; j++)
    {
        int lt = max(i, lst[j]);
        if (lt == j) break;
        dis[j] = dis[lt] + 1;
        ld[dis[j]] = j;
        cnt[j] = cnt[ld[dis[j]-1]] - cnt[lt-1];
        if (cnt[j] == 2) ans += n-j+1;
        cnt[j] += cnt[j-1];
    }
    return ans;
}
ll solve_sp2(int n)
{
    int i, u, v;
    for (u=1; nxt[u]!=n; u++);
    for (v=u; v<=n and lst[v]==1; v++);
    if (v == n+1) return 0;
    ll ans = 0;
    for (i=1; i<u; i++)
    {
        if (lst[u+2] == 1 and nxt[i] >= u+2) break;
        if (nxt[i] == u+2) ans += n-v+1;
    }
    return ans;
}
ll solve(void)
{
    int n; ll d; read(n); read(d);
    int i, j;
    for (i=1; i<=n; i++) readneg(x[i]);
    for (i=1; i<=n; i++) lst[i] = lower_bound(x+1, x+n+1, x[i]-d) - x;
    for (i=1; i<=n; i++) nxt[i] = upper_bound(x+1, x+n+1, x[i]+d) - x - 1;
    if (C == 11 or C == 12) return solve_sp1(n);
    if (C == 13 or C == 14) return solve_sp2(n);
    int ans = 0;
    for (i=1; i<=n; i++)
    {
        fill(ld, ld+n, 0);
        dis[i] = 0; ld[0] = i; cnt[i] = 1; cnt[i-1] = 0;
        for (j=i+1; j<=n; j++)
        {
            int lt = max(i, lst[j]);
            if (lt == j) break;
            dis[j] = dis[lt] + 1;
            ld[dis[j]] = j;
            cnt[j] = cnt[ld[dis[j]-1]] - cnt[lt-1];
            if (cnt[j] == 2) ans++;
            cnt[j] += cnt[j-1];
        }
    }
    return ans;
}
int main(void)
{
    #ifndef NO_FREOPEN
    (void)!freopen(file ".in", "r", stdin);
    (void)!freopen(file ".out", "w", stdout);
    #endif
    int t; read(C); read(t);
    while (t--) cout << solve() << endl;
}
