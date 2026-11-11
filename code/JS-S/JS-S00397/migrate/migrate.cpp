#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int C,T,n,d,x[N],dis[N][3],cnt;
bool vis[N];
vector<int> g[N];
int dist(int i,int j)
{
    return abs(x[i]-x[j]);
}
void dijkstra(int s)
{
    priority_queue<tuple<int,int,int>> pq;
    dis[s][0]=dis[s][1]=dis[s][2]=0;
    pq.push({-dis[s][0],s,0});
    while(!pq.empty())
    {
        auto [d,u,lyr]=pq.top();
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto v:g[u])
        {
            int w=1;
            if(dis[v][0]>dis[u][0]+w)
            {
                dis[v][1]=dis[v][0];
                dis[v][0]=dis[u][0]+w;
                pq.push({-dis[v][0],v,0});
            }
            else if(dis[v][1]>dis[u][0]+w)
                dis[v][1]=dis[u][0]+w;
            /*else if(dis[v][1]>dis[u][1]+w)
                dis[v][1]=dis[u][1]+w;*/
            /*else if(dis[v][2]>dis[u][0]+w)
                dis[v][2]=dis[u][0]+w;*/
            else if(dis[v][2]>dis[u][1]+w)
                dis[v][2]=dis[u][1]+w;
            /*else if(dis[v][2]>dis[u][2]+w)
                dis[v][2]=dis[u][2]+w;*/
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                int ds=dist(i,j);
                if(ds<=d)
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        for(int i=1;i<=n;i++)
            for(int j=i+2;j<=n;j++)
            {
                memset(dis,0x3f,sizeof dis);
                memset(vis,0,sizeof vis);
                dijkstra(i);
                if(dis[j][0]==dis[j][1]&&dis[j][1]!=dis[j][2]&&dis[j][0]!=dis[j][2]) cnt++;
            }
        cout<<cnt<<"\n";
    }
    return 0;
}
