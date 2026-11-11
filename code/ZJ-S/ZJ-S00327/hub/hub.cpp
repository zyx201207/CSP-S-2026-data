#include <bits/stdc++.h>
using namespace std;

#define int long long 

constexpr int maxn = 1e6 + 100;
constexpr int INF = 0x3f3f3f3f3f3f3f3f;

vector<pair<int, int>> gra[maxn];

int fa[maxn];
int son[maxn];
int siz[maxn];
int depth[maxn];
bool vis[maxn];

void dfs1(int u, int p, int ban = 0)
{
    fa[u] = p;
    son[u] = 0;
    siz[u] = 1;
    depth[u] = depth[p] + 1;
    vis[u] = true;

    for(auto E : gra[u])
    {
        int v = E.first;
        int eid = E.second;
        
        if(v == p) continue;
        if(eid == ban) continue;
        dfs1(v, u, ban);

        siz[u] += siz[v];

        if(siz[son[u]] < siz[v])
        {
            son[u] = v;
        }
    }
}

int top[maxn];

void dfs2(int u, int h)
{
    top[u] = h;

    if(son[u]) dfs2(son[u], h);

    for(auto E : gra[u])
    {
        int v = E.first;
        int eid = E.second;
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

int LCA(int x, int y)
{
    while(top[x] != top[y])
    {
        if(depth[top[x]] < depth[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return depth[x] < depth[y] ? x : y;
}

int calcdis(int x, int y)
{
    int ans = depth[x] + depth[y] - 2 * depth[LCA(x, y)];
    return ans;
}

vector<pair<int, int>> edges;

signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    int c, t;
    scanf("%lld%lld", &c, &t);

    while(t--)
    {
        int n, k;
        scanf("%lld%lld", &n, &k);

        for(int i = 1; i <= n; ++i) gra[i].clear();
        edges.clear();

        for(int i = 1; i < n; ++i)
        {
            int u, v;
            scanf("%lld%lld", &u, &v);
            
            gra[u].emplace_back(v, i);
            gra[v].emplace_back(u, i);

            edges.emplace_back(u, v);
        }

        if(k <= 2 && n > 10)
        {
            int ans = INF;
            for(int x = 1; x < n; ++x)
            {
                int now = -1;

                for(int i = 1; i <= n; ++i) vis[i] = false;

                int u1 = edges[x-1].first;
                int u2 = edges[x-1].second;
                
                dfs1(u1, 0, x);

                int cand = u1;
                for(int j = 1; j <= n; ++j)
                {
                    if(!vis[j]) continue;
                    if(depth[cand] < depth[j])
                    {
                        cand = j;
                    }
                }
                
                dfs1(cand, 0, x);
                for(int j = 1; j <= n; ++j)
                {
                    if(!vis[j]) continue;
                    if(depth[cand] < depth[j])
                    {
                        cand = j;
                    }
                }

                // cerr << "! " << depth[cand] << '\n'; 

                now = max(now, depth[cand] / 2);

                for(int i = 1; i <= n; ++i) vis[i] = false;

                dfs1(u2, 0, x);

                cand = u2;
                for(int j = 1; j <= n; ++j)
                {
                    if(!vis[j]) continue;
                    if(depth[cand] < depth[j])
                    {
                        cand = j;
                    }
                }
                
                dfs1(cand, 0, x);
                for(int j = 1; j <= n; ++j)
                {
                    if(!vis[j]) continue;
                    if(depth[cand] < depth[j])
                    {
                        cand = j;
                    }
                }

                now = max(now, depth[cand] / 2);
                // cerr << "! " << depth[cand] << '\n';

                // cerr << "? " << x << ' ' << now << '\n';

                ans = min(ans, now);
            }

            printf("%lld\n", ans);

            continue;
        }

        dfs1(1, 0);
        dfs2(1, 1);

        int full = (1LL << n) - 1;

        int ans = INF;

        for(unsigned int mask = 0; mask <= full; ++mask)
        {
            if(__builtin_popcountll(mask) == k)
            {
                vector<int> nodes;
                for(int i = 1; i <= n; ++i)
                {
                    if((mask >> (i-1)) & 1)
                    {
                        nodes.emplace_back(i);
                    }
                }

                int connect = k;

                for(auto e : edges)
                {
                    int u = e.first;
                    int v = e.second;
                    if(((mask >> (u-1)) & 1) && ((mask >> (v-1)) & 1))
                    {
                        --connect;
                    }
                }

                if(connect > 2) continue;

                int mx_d = -1;

                for(int i = 1; i <= n; ++i)
                {
                    int mndis = INF;
                    for(int j = 0; j < k; ++j)
                    {
                        mndis = min(mndis, calcdis(i, nodes[j]));
                    }
                    mx_d = max(mx_d, mndis);
                }

                ans = min(ans, mx_d);
            }
        }

        printf("%lld\n", ans);
    }
}