#include <iostream>
#include <vector>

using namespace std;

const int N = 15;

vector <int> G[N];
int dep[N];
int fa[N];
int p[N];
int d[N];

int c, T;

int cal(int x)
{
    int res = 0;
    while (x)
    {
        res += x % 2;
        x /= 2;
    } return res;
}

void dfs(int u, int f)
{
    fa[u] = f;
    dep[u] = dep[f] + 1;
    for (auto v : G[u])
    {
        if (v != f)
        {
            dfs(v, u);
        }
    }
}

int LCA(int x, int y)
{
    if (dep[x] < dep[y]) swap(x, y);
    while (dep[x] != dep[y])
    {
        x = fa[x];
    }

    while (x != y)
    {
        x = fa[x], y = fa[y];
    } return x;
}

int dist(int x, int y)
{
    return -2 * dep[LCA(x, y)] + dep[x] + dep[y];
}

int find(int x)
{
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
}

void _dfs(int u, int f, int S)
{
    if ((S & (1 << (u - 1))) && (S & (1 << (f - 1))))
    {
        int a = find(u);
        int b = find(f);
        p[u] = f;
    }

    fa[u] = f;
    dep[u] = dep[f] + 1;
    for (auto v : G[u])
    {
        if (v != f)
        {
            _dfs(v, u, S);
        }
    }
}

bool check(int S, int n)
{
    _dfs(1, 0, S);
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (S & (1 << (i - 1)))
            cnt += (p[i] == i);
    } 
    if (cnt > 2) return false;
    return true;
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cin >> c >> T;

    while (T--)
    {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; ++i) G[i].clear();
        for (int i = 1; i <= n; ++i) d[i] = 0, fa[i] = 0, dep[i] = 0;

        for (int i = 1; i < n; ++i)
        {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        dfs(1, 0);

        int U = (1 << n);
        int ans = 1e7;

        for (int S = 0; S < U; ++S)
        {
            for (int i = 1; i <= n; ++i) p[i] = i;
            if (cal(S) == k && check(S, n))
            {

                for (int i = 1; i <= n; ++i)
                {
                    if (S & (1 << (i - 1)))
                    {
                        d[i] = 0;
                        continue;
                    } else d[i] = 1e7;
                    for (int j = 1; j <= n; ++j)
                    {
                        if (S & (1 << (j - 1)))
                        {
                            d[i] = min(d[i], dist(i, j));
                        }
                    }
                }

                int res = 0;

                for (int i = 1; i <= n; ++i)
                {
                    res = max(res, d[i]);
                }

                ans = min(ans, res);
            }
        }

        cout << ans << endl;
    }

    return 0;
}