#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500010];
vector<int> G[500010];
unordered_map<int,int> t[520];
int dis[500010];
vector<int> cross;
vector<int> allroad[500010];
int cnt[500010];
bool vis[500010],vvis[500010];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> c>> n >> m >> d >> q;
    for(int i = 1;i <= m;i ++) cin >> w[i];
    for(int i = 1;i <= n;i ++)
    {
        int k;
        cin >> k;
        int pre = -1;
        for(int j = 1;j <= k;j ++)
        {
            int x,ti;
            cin >> x >> ti;
            t[i][x] = ti;
            G[x].push_back(i);
            cnt[x]++;
        } 
    }  
    for(int i = 1;i <= m;i ++)
        if(cnt[i] >= 2)
            for(int j : G[i])
                allroad[j].push_back(i);
    while(q--)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        int u,v;
        cin >> u >> v;
        q.push({0,u});
        int ans = 0x7f7f7f7f7f7f7f7f;
        for(int i = 1;i <= m;i ++) dis[i] = 0x7f7f7f7f7f7f7f7f,vvis[i] = false;;
        for(int i = 1;i <= n;i ++) vis[i] = false;
        dis[u] = 0;
        if(G[u].size() == 1) allroad[G[u][0]].push_back(u);
        if(G[v].size() == 1) allroad[G[v][0]].push_back(v);
        while(!q.empty())
        {
            int u = q.top().second;
            q.pop();
            if(vvis[u]) continue;
            vvis[u] = true;
            for(auto x : G[u])
            {
                if(vis[x]) continue;
                vis[x] = true;
                int up = 0;
                up = t[x][u];
                for(auto al : allroad[x])
                {
                    if(al == v)
                    {
                        ans = min(ans,up + dis[u] + t[x][al]);
                    }
                    dis[al] = min(dis[al],dis[u] + up + t[x][al]);
                    q.push({dis[al],al});
                }
            }
        }
        if(G[u].size() == 1) allroad[G[u][0]].pop_back();
        if(G[v].size() == 1) allroad[G[v][0]].pop_back();
        cout<<ans + w[u] + w[v]<<"\n";
    }

    return 0;
}