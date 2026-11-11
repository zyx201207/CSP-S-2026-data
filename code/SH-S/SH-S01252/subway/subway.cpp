#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
int s,t,c,w[500010],k[510],a[500010],dis[500010];
bool vis[500010];
vector<pair<int,int>> adj[500010];
void dij(int s,int c)
{
    queue<pair<int,int>> q;
    q.push({s,0}),dis[s] = 0;
    while (!q.empty())
    {

        int u = q.front().first,i = q.front().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto [v,j] : adj[u])
        {
            if (dis[v] > dis[u] + 2 * c && j != i)
            {
                dis[v] = dis[u] + 2 * c;
                q.push({v,j});
            }
            if (dis[v] > dis[u] && i == j)
            {
                dis[v] = dis[u];
                q.push({v,j});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++)
        {
            cin >> a[j] >> c;
            if (j == 1) continue;
            adj[a[j]].push_back({a[j - 1],i});
            adj[a[j - 1]].push_back({a[j],i});
        }
    }
    while (q--)
    {
        memset(dis,INF,sizeof(dis));
        memset(vis,0,sizeof(vis));
        cin >> s >> t;
        dij(s,c);
        cout << dis[t] + w[s] + w[t] << "\n";
    }
    return 0;
}
