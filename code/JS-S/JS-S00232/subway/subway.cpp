#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 6e5 + 5, INF = 0x3f3f3f3f3f3f3f3fll;
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while(!isdigit(c))
    {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(isdigit(c))
        x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}
int vis[N];
map < int, int > d[N], a[505], t[505];
struct node
{
    int v, w;
};
vector < node > g[N];
struct Node
{
    int u, d;
    bool operator > (const Node &a) const {return d > a.d;}
};
priority_queue < Node, vector < Node >, greater < Node > > pq;
int W[N], k[N], f[N];
vector < int > zx[N];
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int C = read(), n = read(), m = read(), D = read(), q = read();
    for(int i = 1; i <= m; i++)
        W[i] = read();
    for(int i = 1; i <= n; i++)
    {
        k[i] = read();
        for(int j = 1; j <= k[i]; j++)
            a[i][j] = read(), t[i][a[i][j]] = read(), zx[a[i][j]].push_back(i);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int u = 1; u <= k[i]; u++)
            for(int v = u + 1; v <= k[i]; v++)
                g[i * D + a[i][u]].push_back({i * D + a[i][v], t[i][a[i][v]]}),
                g[i * D + a[i][v]].push_back({i * D + a[i][u], t[i][a[i][u]]});
    }
    for(int i = 1; i <= m; i++)
    {
        int l = zx[i].size();
        if(l < 1)continue;
        for(int u = 0; u < l; u++)
            for(int v = u + 1; v < l; v++)
                g[zx[i][u] * D + i].push_back({zx[i][v] * D + i, t[zx[i][v]][i]}),
                g[zx[i][v] * D + i].push_back({zx[i][u] * D + i, t[zx[i][u]][i]});
    }
    while(q--)
    {
        int x = read(), y = read(), minn = INF;
        int l = zx[x].size();
        if(f[x] != 1)
        {
            f[x] = 1;
            for(int i = 0; i < l; i++)
            {
                int s = zx[x][i] * D + x;
                for(int i = 1; i <= D * n + m; i++)
                    d[s][i] = INF, vis[i] = 0;
                d[s][s] = 0;
                pq.push({s, 0});
                while(!pq.empty())
                {
                    int t = pq.top().u;
                    pq.pop();
                    if(vis[t] == 1) continue;
                    vis[t] = 1;
                    for(node tt : g[t])
                    {
                        int v = tt.v, w = tt.w;
                        if(d[s][v] > d[s][t] + w) d[s][v] = d[s][t] + w, pq.push({v, d[s][v]});
                    }
                }
            }
        }
        for(int i = 0; i < l; i++)
            for(int j = 1; j <= n; j++)
                if(d[zx[x][i] * D + x][j * D + y] != INF)minn = min(minn, d[zx[x][i] * D + x][j * D + y] + t[zx[x][i]][x]);
        cout << W[x] + W[y] + minn << endl;
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
