#include <bits/stdc++.h>
using namespace std;

constexpr size_t MAXN = 5e5 + 1;
constexpr int64_t INF = 0x3f3f3f3f;

struct edge
{
    int64_t v;
    int64_t w;
};

struct node
{
    int64_t to;
    int64_t dis;

    constexpr inline bool operator>(const node &rhs) const
    {
        return dis > rhs.dis;
    }
};

bitset<MAXN> vis;
vector<int64_t> dis;
vector<vector<edge>> g;

void dijkstra(int64_t s)
{
    priority_queue<node, vector<node>, greater<node>> q;
    q.push({s, 0});
    dis[s] = 0;
    while (!q.empty())
    {
        node u = q.top();
        q.pop();
        if (vis[u.to])
            continue;
        vis[u.to] = true;
        for (const edge &v : g[u.to])
            if (dis[v.v] > dis[u.to] + v.w)
            {
                dis[v.v] = dis[u.to] + v.w;
                q.push({v.v, dis[v.v]});
            }
    }
}

struct line
{
    int64_t k;
    vector<int64_t> a;
    vector<int64_t> t;

    line() : a(k), t(k) {}
    line(int64_t _k) : k(_k), a(k), t(k) {}
};

int main(void)
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int64_t c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    vector<int64_t> w(n + 1);
    for (int64_t i = 1; i <= m; ++i)
        cin >> w[i];
    vector<line> input(n + 1);
    for (int64_t i = 1; i <= n; ++i)
    {
        cin >> input[i].k;
        input[i] = line(input[i].k);
        for (int64_t j = 1; j <= input[i].k; ++j)
            cin >> input[i].a[j] >> input[i].t[j];
    }

    return 0;
}