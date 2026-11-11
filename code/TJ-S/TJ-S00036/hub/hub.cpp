#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
long long _, t, n, k, dsu[1000005];
vector <long long> adj[1000005];
vector <vector <long long> > bases;
vector <long long> USL;
long long findf(long long u)
{
    if (u == dsu[u])
    {
        return u;
    }
    dsu[u] = findf(dsu[u]);
    return dsu[u];
}
void unite(long long u, long long v)
{
    u = findf(u), v = findf(v);
    dsu[u] = v;
}
bool testbases(vector <long long> sample)
{
    bool in_sample[1000005] = {};
    for (long long i = 1; i <= n; i++)
    {
        dsu[i] = i;
    }
    for (long long i : sample)
    {
        in_sample[i] = 1;
        for (long long j : adj[i])
        {
            if (in_sample[j])
            {
                unite(i, j);
            }
        }
    }
    long long c = 0;
    for (long long i : sample)
    {
        if (findf(i) == i)
        {
            c++;
        }
    }
    return (c <= 2);
}
void choosebases(vector <long long> chosen, long long nxts)
{
    if (chosen.size() == k)
    {
        if (testbases(chosen))
        {
            bases.push_back(chosen);
        }
        return ;
    }
    else if (nxts > n)
    {
        return ;
    }
    for (long long i = nxts; i <= n-k+chosen.size()+1; i++)
    {
        chosen.push_back(i);
        choosebases(chosen, i+1);
        chosen.pop_back();
    }
}
long long countfurthest(vector <long long> sample)
{
    priority_queue <pair <long long, long long> > pq;
    long long dis[1000005];
    memset(dis, 0x3f3f3f3f3f3f3f3f, sizeof(dis));
    for (long long i : sample)
    {
        pq.push({0, i});
    }
    while (!pq.empty())
    {
        auto [_d, u] = pq.top();
        pq.pop();
        if (dis[u] != 0x3f3f3f3f3f3f3f3f)
        {
            continue;
        }
        dis[u] = -_d;
        for (long long v : adj[u])
        {
            pq.push({_d-1, v});
        }
    }
    long long maxn = -1;
    for (long long i = 1; i <= n; i++)
    {
        maxn = max(maxn, dis[i]);
    }
    return maxn;
}
void solve()
{
    long long ans = 0x3f3f3f3f3f3f3f3f;
    bases.clear();
    choosebases(USL, 1);
    for (vector <long long> baseplan : bases)
    {
        ans = min(ans, countfurthest(baseplan));
    }
    cout << ans << "\n";
}
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> _ >> t;
    while (t--)
    {
        cin >> n >> k;
        for (long long i = 1; i <= n; i++)
        {
            adj[i].clear();
        }
        for (long long i = 1, u, v; i < n; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v), adj[v].push_back(u);
        }
        solve();
    }
    return 0;
}
