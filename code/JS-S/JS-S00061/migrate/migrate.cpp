#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long x[2000010],dis[2000010],ans[2000010],finalans;
int vis[2000010];
struct node
{
    int to;
    int w;
};
vector<node> e[2000010];
struct work
{
    int id;
    long long d;
};
bool operator < (work a,work b)
{
    return a.d>b.d;
}
void Dijkstra(int s)
{
    for(int i=1;i<=n;i++) dis[i]=2000010,vis[i]=0,ans[i]=0;
    priority_queue<work> q;
    q.push(work{s,0});
    dis[s]=0;
    ans[s]=1;
    while(!q.empty())
    {
        int x=q.top().id;
        q.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=0;i<e[x].size();i++)
        {
            if(dis[x]+e[x][i].w<dis[e[x][i].to])
            {
                dis[e[x][i].to]=dis[x]+e[x][i].w;
                ans[e[x][i].to]=ans[x];
                q.push(work{e[x][i].to,dis[e[x][i].to]});
            }
            else if(dis[x]+e[x][i].w==dis[e[x][i].to]) ans[e[x][i].to]+=ans[x];
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)  cin>>x[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(x[j]-x[i]<=d) e[i].push_back(node{j,1});
                else break;
            }
        }
        for(int i=1;i<=n;i++)
        {
             Dijkstra(i);
             for(int j=i+1;j<=n;j++)
            {

                if(ans[j]==2) finalans++;
            }
        }
        cout<<finalans<<endl;
        //for(int i=1;i<=n;i++) ans[i]=0;
        finalans=0;
        for(int i=1;i<=n;i++) e[i].clear();
    }
    return 0;
}
