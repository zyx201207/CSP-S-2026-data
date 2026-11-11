#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> PI;
const int O = 1e3, N = 5e5 + 5, I = 1e17, QwQ = 1e5 + 3;
int C, n, m, D, Q, w[N], d[N + O], cnt, Z[N];
struct P
{
    int x, y;
};
vector<P> e[N + O];
map<int, int> G[N];
struct R
{
    int id, x, y, ans;
}q[QwQ];
bool cmpR(R a, R b)
{
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
bool cmpRR(R a, R b)
{
    return a.id < b.id;
}

int dot(int x, int o)
{
    return x + o * m;
}
void add(int x, int y, int z)
{
    e[x].push_back({y, z});
    e[y].push_back({x, z});
}
void dijkstra(int X)
{
    priority_queue<PI, vector<PI>, greater<PI> > q;
    cnt = 0;
    for (int i = 1; i <= 2 * m + n; i++)
    {
        d[i] = I;
    }
    d[X] = 0;
    q.push({0, X});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i].x, w = e[u][i].y;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v], v});
                if (G[X].count(v) > 0)
                {
                    cnt++;
                    if (cnt >= Z[X]) return;
                }
            }
        }
    }
}
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> C >> n >> m >> D >> Q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
        //add(i, dot(i, 1), w[i]);
    }
    for (int i = 1, k, x, y; i <= n; i++)
    {
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> x >> y;
            add(dot(x, 0), dot(i, 1), y);
        }
    }
    for (int i = 1, x, y; i <= Q; i++)
    {
        q[i].id = i;
        cin >> x >> y;
        if (x > y) swap(x, y);
        q[i].x = x;
        q[i].y = y;
    }
    sort(q + 1, q + Q + 1, cmpR);
    for (int i = 1; i <= Q; i++)
    {
        int id = q[i].id, x = q[i].x, y = q[i].y;
        G[x][y] = 1;
        Z[x]++;
    }
    for (int i = 1; i <= Q; i++)
    {
        int id = q[i].id, x = q[i].x, y = q[i].y;
        if (id != q[i - 1].id) dijkstra(x);
        q[i].ans = d[y] + w[x] + w[y];
    }
    sort(q + 1, q + Q + 1, cmpRR);
    for (int i = 1; i <= Q; i++)
        cout << q[i].ans << "\n";
    return 0;
}
