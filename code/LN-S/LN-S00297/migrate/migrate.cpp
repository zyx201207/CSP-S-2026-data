#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e6+5;
int x[N];

int dis[N],vis[N],cnt[N];
const int INF=1e18;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin>>c>>t;
    while(t--)
    {
        vector<int> g[N];
        int n,d;
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(x[j]-x[i]<=d)
                {
                    g[j].push_back(i);
                    g[i].push_back(j);
                }
            }
        }
        for(int o=1;o<n;o++)
        {
            for(int i=1;i<=n;i++)
            {
                dis[i]=INF;
                vis[i]=false;
                cnt[i]=0;
            }
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
            dis[o]=0;
            q.push({0,o});
            while(!q.empty())
            {
                auto cur=q.top();
                if(vis[cur.second])
                    continue;
                int u=cur.second;
                vis[u]=true;
                for(int v:g[u])
                {
                    if(dis[v]>dis[u]+1)
                    {
                        dis[v]=dis[u]+1;
                        q.push({dis[v],v});
                        cnt[v]=0;
                    }
                    if(dis[v]==dis[u]+1)
                    {
                        q.push({dis[v],v});
                        cnt[v]++;
                    }
                }
            }
            for(int y=o+1;y<=n;y++)
            {
                if(cnt[y]==2)
                    ans++;
            }
        }
        cout<<ans<<"\n";
    }




    return 0;
}
/*
    第一步应该是把图连出来
    第二步应该需要用dijkstra求出最短路条数；
    我直接一个雷霆暴力枚举拿下部分分ahahahah

    失败了兄弟们，这波卡了
    
*/