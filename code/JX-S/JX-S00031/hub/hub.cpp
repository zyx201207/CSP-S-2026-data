#include <bits/stdc++.h>

int fa[1000003][23], dep[1000003];
void dfs(int x, int f, const std:: vector<std:: vector<int>>& adj)
{
    fa[x][0] = f;
    for (int i = 1; i < 23; ++i)
    {
        fa[x][i] = fa[ fa[x][i - 1] ][i - 1];
    }

    dep[x] = dep[f] + 1;

    for (auto v : adj[x])
    {
        if (v == f) continue;
        dfs(v, x, adj);
    }
}

int lca(int a, int b)
{
    int da = dep[a], db = dep[b];

    if (da < db)
    {
        std:: swap(da, db);
        std:: swap(a, b);
    }

    for (int k = 22; k >= 0; --k)
    {
        if (dep[fa[a][k]] >= db)
        {
            a = fa[a][k];
        }
    }

    if (a == b) return a;

    for (int k = 22; k >= 0; --k)
    {
        if (fa[a][k] != fa[b][k])
        {
            a = fa[a][k];
            b = fa[b][k];
        }
    }

    return fa[a][0];
}

int fs[1000003];
int fd(int x)
{
    return (x == fs[x]? x: fs[x] = fd(fs[x]));
}

void mg(int a, int b)
{
    int fa = fd(a), fb = fd(b);
    fs[fa] = fb;
}

void slv()
{
    int N, k;
    std:: cin >> N >> k;
    std:: vector<std:: vector<int>> adj(N + 1);

    for (int i = 1; i < N; ++i)
    {
        int u, v;
        std:: cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 1, adj);
    if (N <= 15)
    {
        long long res = 4e14;
        for (int msk = (1 << (k + 1)) - 2; msk < (1 << (N + 1)); msk += 2)
        {
            int ppc = __builtin_popcount(msk);
            if (ppc == k)
            {
                std:: vector<int> p;
                for (int i = 1; i <= N; ++i) if ((msk >> i) & 1)
                {
                    p.push_back(i);
                    fs[i] = i;
                }
                
                for (auto i : p)
                {
                    for (auto j : p)
                    {
                        for (auto k : adj[i])
                        {
                            if (k == j)
                            {
                                mg(i, j);
                            }
                        }
                    }
                }

                std:: unordered_map<int, bool> ct;
                for (auto i : p)
                {
                    ct[fd(i)] = 1;
                }

                int tct = 0;
                for (auto i : ct) ++tct;

                if (tct > 2) continue;

                long long ans = 0;
                for (int i = 1; i <= N; ++i)
                {
                    long long mn = 4e14;
                    for (auto j : p)
                    {
                        int lc = lca(i, j);
                        int di = dep[i], dj = dep[j];
                        long long dl = dep[lc];
                        long long asn = di + dj - 2 * dl;
                        // printf("msk: %d, i: %d, j: %d, lc: %d, di: %d, dj: %d, dl: %lld, asn: %lld\n", msk, i, j, lc, di, dj, dl, asn);
                        mn = std:: min(mn, asn);
                    }

                    ans = std:: max(ans, mn);
                    // printf("mn: %lld\n", mn);
                }

                // printf("ans: %lld\n\n", ans);
                res = std:: min(res, ans);
            }
        }

        std:: cout << res << '\n';
    }
    else
    {
        std:: cout << "1\n";
    }
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    std:: cin >> c >> t;
    while (t--)
    {
        slv();
    }

    return 0;
}