#include<bits/stdc++.h>
#define int long long
#define pa pair<int, int>
#define fi first
#define se second
using namespace std;
int c, n, m, dd, q, a[500005];
vector<pa> e[500506];
int d[505][505];
inline int read()
{
    int p = 0;
    char s = getchar();
    while (s>'9' || s<'0') s = getchar();
    while (s<='9' && s>='0')
    {
        p = (p<<3)+(p<<1)+s-'0';
        s = getchar();
    }
    return p;
}
inline void write(int p)
{
    char s[22];
    int pos = 0;
    while (p)
    {
        s[pos++] = p%10+'0';
        p /= 10;
    }
    while (pos--) putchar(s[pos]);
}
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = read();
    n = read();
    m = read();
    dd = read();
    q = read();
    int maxn = m+n;
    for (int i = 1; i <= m; i++) a[i] = read();
    for (int i = 1; i <= n; i++)
    {
        int k;
        k = read();
        for (int j = 1; j <= k; j++)
        {
            int x, y;
            x = read();
            y = read();
            e[m+i].push_back({y, x});
            e[x].push_back({y, m+i});
        }
    }
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= m; i++)
    {
        for (int u = 0; u < e[i].size(); u++)
        {
            for (int v = u+1; v < e[i].size(); v++)
            {
                pa iu = e[i][u];
                pa iv = e[i][v];
                d[iu.se-m][iv.se-m]=min(d[iu.se-m][iv.se-m], iu.fi+iv.fi);
                d[iv.se-m][iu.se-m]=d[iu.se-m][iv.se-m];
            }
        }
    }
    for (int k = 0; k < 502; k++)
    {
        d[k][k] = 0;
        for (int i = 0; i < 502; i++)
        {
            for (int j = 0; j < 502; j++)
            {
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    while (q--)
    {
        int x, y, ans = 4e18;
        x = read();
        y = read();
        for (int i = 0; i < e[x].size(); i++)
        {
            for (int j = 0; j < e[y].size(); j++)
            {
                ans = min(ans, d[e[x][i].se-m][e[y][j].se-m]+e[x][i].fi+e[y][j].fi);
            }
        }
        write(ans+a[x]+a[y]);
        putchar('\n');
    }
    return 0;
}
