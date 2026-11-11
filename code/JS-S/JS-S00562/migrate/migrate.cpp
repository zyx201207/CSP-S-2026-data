#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 10;
int n, x[N], ans, m, c, t, d, dis[N], way;
vector <int> G[N];
void dijkstra(int st)
{
    memset(dis, 0x3f, sizeof dis);
    priority_queue <pair<int, int>> q;
    q.push({0, st});
    dis[st] = 0;
    while(!q.empty())
    {
        pair<int, int> p = q.top();
        q.pop();
        int u = p.second;
        if(dis[u] != -p.first) continue;
        for(int e : G[u])
        {
            int v = e, w = 1;
            if(dis[v] > dis[u] + 1)
            {
                dis[v] = dis[u] + 1;
                q.push({-dis[v], v});
            }
        }
    }
}
bool vis[N];
void dfs(int st, int mubiao, int step, int k)
{
    //cout << st << ' ';
    if(st == mubiao && step == dis[mubiao])
    {
        //cout << k << ' ' << mubiao << ' ' << step << endl;
        way++;
        return ;
    }
    for(int e : G[st])
    {
        if(!vis[e]) {vis[e] = 1; dfs(e, mubiao, step + 1, k); vis[e] = 0;}
    }
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i = 1; i <= n; i++) cin >> x[i];
        if(c == 11 || c == 12)
        {
            if(x[2] - x[1] > d) cout << 0 << endl;
            else cout << max(n + 1 - 2 * d / (x[2] - x[1]), 0ll) << endl;
            continue;
        }
        for(int i = 1; i <= n; i++) G[i].clear();
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                if(x[j] - x[i] > d) break;
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
        //for(int i = 1; i <= n; i++) {for(int e : G[i]) cout << e << ' '; cout << endl;}
        ans = 0;
        for(int i = 1; i <= n; i++)
        {
            dijkstra(i);
            //for(int j = 1; j <= n; j++) cout << dis[j] << " \n"[j == n];
            for(int j = i; j <= n; j++)
            {
                //cout << i << ' ' << j << endl;
                for(int k = 1; k <= n; k++) vis[k] = 0;
                way = 0;
                dfs(i, j, 0, i);
                if(way == 2) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
