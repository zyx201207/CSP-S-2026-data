#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[200010];
vector<int> G[200010];
int dis[200010],cnt[200010];
bool vis[200010];
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0')
    {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10+ ch - '0';
        ch = getchar();
    }
    return x * f;
}
void solve()
{
    n = read(),k = read();
    for(int i = 1;i <= n;i ++) G[i].clear();
    for(int i =1 ;i <= n;i ++)
        a[i] = read();
    for(int i =1 ;i <= n;i ++)
    {
        for(int j = 1;j < i;j ++)
        {
            if(a[i] - a[j] <= k)
            {
                // G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
    long long ans = 0;
    for(int i = 1;i <= n;i ++)
    {
        for(int j =1 ;j <= n;j ++) dis[j] = 9e18,cnt[j] = 0,vis[j] = 0;
        cnt[i] = 1;
        queue<int> q;
        q.push(i);
        dis[i] = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            if(vis[u]) continue;
            vis[u] = true;
            for(auto to : G[u])
            {
                if(dis[to] > dis[u] + 1)
                {
                    dis[to] = dis[u] + 1;
                    cnt[to] = cnt[u];
                    q.push(to);
                }else if(dis[to] == dis[u] + 1) 
                    cnt[to] += cnt[u];
            }
        }
        for(int j = 1;j <= n;j ++) if(cnt[j] == 2)ans++;
    }
    cout<<ans<<"\n";
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    c = read(),t = read();
    while(t--) solve();
    return 0;
}