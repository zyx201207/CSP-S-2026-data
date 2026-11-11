#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
const int M = 5e5 + 505;
struct Edge
{
    ll v;
    ll w;
};
ll c, n, m, d, q;
ll zuzong;
ll w[N];
ll siz[M];
ll ind[M];
bool vis[M];
ll floyd[355][355];
vector<Edge> g[M];
void read(ll &x)
{
    x = 0;
    int flag = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-')
        {
            flag = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch - 48);
        ch = getchar();
    }
    x *= flag;
}
void write(ll x)
{
    int top = 0;
    static int sta[40] = {0};
    if(x < 0)
    {
        putchar('-');
        x = -x;
    }
    do
    {
        sta[++top] = x % 10ll;
        x /= 10ll;
    }
    while(x);
    while(top)
    {
        putchar(sta[top--] + 48);
    }
    putchar('\n');
}
void Dfs(ll u)
{
    vis[u] = 1;
    for(Edge v : g[u])
    {
        if(!vis[v.v])
        {
            Dfs(v.v);
            siz[u] = siz[v.v] + v.w;
        }
    }
}
void solveA()
{
    read(n);read(m);read(d);read(q);
    for(int i = 1;i <= m;++i)
    {
        read(w[i]);
    }
    for(int i = 1;i <= n;++i)
    {
        ll k;
        read(k);
        k *= 2ll;
        ll to = m + i;
        ll a = 0;
        ll t = 0;
        for(int j = 1;j <= k;++j)
        {
            if(j & 1ll)
            {
                read(a);
            }
            else
            {
                read(t);
                g[a].push_back({to, t});
                g[to].push_back({a, t});
                ++ind[a];
                ++ind[to];
            }
        }
    }
    for(int i = 1;i <= m + n;++i)
    {
        if(ind[i] == 1)
        {
            zuzong = i;
            break;
        }
    }
    Dfs(zuzong);
    while(q--)
    {
        ll st;
        ll ed;
        read(st);
        read(ed);
        ll ans = w[st] + w[ed];
        ll tmp = siz[ed] - siz[st];
        if(tmp < 0ll)
        {
            tmp = -tmp;
        }
        ans += tmp;
        write(ans);
    }
}
void solveBL()
{
    read(n);read(m);read(d);read(q);
    for(int i = 1;i <= m;++i)
    {
        read(w[i]);
    }
    ll mxtmp = LLONG_MAX;
    mxtmp >>= 4ll;
    for(int i = 0;i <= m + 1;++i)
    {
        for(int j = 0; j <= m + 1; ++j)
        {
            if(i == j)
            {
                continue;
            }
            floyd[i][j] = mxtmp;
        }
    }
    ll a[505] = {0};
    ll t[505] = {0};
    for(int i = 1;i <= n;++i)
    {
        ll k;
        read(k);
        k *= 2ll;
        for(int j = 1;j <= k;++j)
        {
            if(j & 1ll)
            {
                read(a[j / 2ll + 1]);
            }
            else
            {
                read(t[j / 2ll]);
            }
        }
        k /= 2ll;
        for(int j = 1;j <= k; ++j)
        {
            for(int qnw = 1; qnw <= k; ++qnw)
            {
                if(j == qnw)
                {
                    continue;
                }
                floyd[a[j]][a[qnw]] = t[j] + t[qnw];
                floyd[a[qnw]][a[j]] = t[j] + t[qnw];
            }
        }
    }
    for(int k = 1;k <= m; ++k)
    {
        for(int i = 1;i <= m; ++i)
        {
            for(int j = 1;j <= m;++j)
            {
                floyd[i][j] = min(floyd[i][k] + floyd[k][j], floyd[i][j]);
            }
        }
    }
    while(q--)
    {
        ll st;
        ll ed;
        read(st);
        read(ed);
        ll ans = floyd[st][ed] + w[st] + w[ed];
        write(ans);
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    read(c);
    if(7 <= c && c <= 11)
    {
        solveA();
    }
    else if(0 <= c && c <= 6)
    {
        solveBL();
    }
    else
    {
        solveBL();
    }
    return 0;
}
