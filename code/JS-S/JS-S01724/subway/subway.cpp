#include<bits/stdc++.h>
using namespace std;
using PII=pair<long long,long long>;
const long long N=505;
const long long M=1e3+5;
long long c,n,m,d,q;
long long w[M];
long long sta[M];
long long dis[25*M];
long long vis[25*M];
vector<PII> g[25*M];
const int J=5e5+5;
vector<long long> tmp[J];
vector<long long> adj[J];
bool f(long long a,long long b)
{
    for(long long c:tmp[a])
    {
        for(long long d:tmp[b])
        {
            if(c==d)return 1;
        }
    }
    return 0;
}
void Dijkstra(long long s)
{
    dis[s]=0;
    priority_queue<PII,vector<PII>,greater<PII>> q;
    q.push({dis[s],s});
    while(!q.empty())
    {
        long long u=q.top().second;
        q.pop();
        if(vis[u])
        {
            continue;
        }
        vis[u]=1;
        for(PII i:g[u])
        {
            long long v=i.first;
            long long w=i.second;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    if(12<=c&&c<=19)
    {
        for(long long i=1;i<=m;i++)
        {
            cin>>w[i];
        }
        long long T=0;
        for(long long i=1;i<=n;i++)
        {
            long long k;
            cin>>k;
            long long last=0;
            for(long long j=1;j<=k;j++)
            {
                long long a;
                cin>>a;
                tmp[a].push_back(i);
                long long t;
                cin>>t;
                T=t;
                if(j!=1)
                {
                    adj[last].push_back(a);
                    adj[a].push_back(last);
                }
                last=a;
            }
        }
        for(long long i=1;i<=q;i++)
        {
            long long x,y;
            cin>>x>>y;
            queue<PII> q;
            q.push({x,x});
            vis[x]=1;
            while(!q.empty())
            {
                long long u=q.front().first;
                long long last=q.front().second;
                q.pop();
                for(long long v:adj[u])
                {
                    if(vis[v])
                    {
                        continue;
                    }
                    vis[v]=1;
                    if(f(last,v))
                    {
                        dis[v]=dis[u];
                        q.push({v,u});
                        continue;
                    }
                    dis[v]=dis[u]+2;
                    q.push({v,u});
                }
            }
            cout<<w[x]+w[y]+T*dis[y]+2*T<<endl;
        }
    }
    else
    {
        for(long long i=1;i<=m;i++)
        {
            cin>>w[i];
        }
        for(long long i=1;i<=n;i++)
        {
            long long k;
            cin>>k;
            long long last=0;
            for(long long j=1;j<=k;j++)
            {
                long long a;
                cin>>a;
                sta[a]++;
                if(j!=1)
                {
                    g[(a-1)*(d+1)+1+sta[a]].push_back({(last-1)*(d+1)+1+sta[last],0});
                    g[(last-1)*(d+1)+1+sta[last]].push_back({(a-1)*(d+1)+1+sta[a],0});
                }
                long long t;
                cin>>t;
                g[(a-1)*(d+1)+1].push_back({(a-1)*(d+1)+1+sta[a],t});
                g[(a-1)*(d+1)+1+sta[a]].push_back({(a-1)*(d+1)+1,t});
                last=a;
            }
        }
        for(long long i=1;i<=q;i++)
        {
            long long x,y;
            cin>>x>>y;
            memset(vis,0,sizeof(vis));
            memset(dis,0x3f,sizeof(dis));
            Dijkstra((x-1)*(d+1)+1);
            cout<<w[x]+w[y]+dis[(y-1)*(d+1)+1]<<endl;
        }
    }
    return 0;
}
