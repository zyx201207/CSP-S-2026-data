#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int status;
    bool operator==(node b) const
    {
        return u == b.u && status == b.status;
    }
};
struct edge
{
    node v;
    int w;
    bool operator<(edge b) const
    {
        if (!(v == b.v))
            return w > b.w;
        else if (v.u != b.v.u)
            return v.u > b.v.u;
        return v.status > b.v.status;
    }
};
namespace std
{
    template <>
    struct hash<node>
    {
        size_t operator()(const node &b) const
        {
            return hash<int>()(b.u) ^ hash<int>()(b.status);
        }
    };

} // namespace std
unordered_map<node, vector<edge>> mp;
int c, n, m, d, q;
unordered_map<node, int> dij(node s)
{
    priority_queue<edge> pq;
    unordered_map<node, int> dist;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[{i, -3}] = INT_MAX;
            dist[{i, -2}] = INT_MAX;
            dist[{i, j}] = INT_MAX;
        }
    }
    dist[s] = 0;
    pq.push({s, 0});
    while (!pq.empty())
    {
        auto u = pq.top();
        pq.pop();
        if (u.w > dist[u.v])
            continue;
        for (auto v : mp[u.v])
        {
            if (v.w + u.w < dist[v.v])
            {
                dist[v.v] = v.w + u.w;
                pq.push({v.v, dist[v.v]});
            }
        }
    }
    return dist;
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        int w;
        cin >> w;
        mp[{i, -3}].push_back({{i, -2}, w});
        mp[{i, -2}].push_back({{i, -3}, w});
    }
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        int l;
        for (int j = 1; j <= k; j++)
        {
            int a, t;
            cin >> a >> t;
            if (j != 1)
            {
                mp[{l, i}].push_back({{a, i}, 0});
                mp[{a, i}].push_back({{l, i}, 0});
            }
            mp[{a, -2}].push_back({{a, i}, t});
            mp[{a, i}].push_back({{a, -2}, t});
            l = a;
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        auto dist = dij({x, -3});
        cout << dist[{y, -3}] << '\n';
    }
}