#include<bits/stdc++.h>
#define ll long long
#define lowbits(x) ((x)&(-(x)))
using namespace std;
int c,n,m,d,qk,k,w[100005],pos;
long long st[505][505];
long long g[505][505];
struct node
{
    long long x,val;
    bool operator<(const node t)const
    {
        return val>t.val;
    }
};
bool vis[505],v[505];
priority_queue<node> q;
vector<node> vec[600005],qp[505];
void dijkstra(int x)
{
    q.push({x,0});
    st[x][x]=0;
    while(!q.empty())
    {
        node t=q.top();
        q.pop();
        if(vis[t.x]==true)continue;
        vis[t.x]=true;
        st[x][t.x]=t.val;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&g[t.x][i]+t.val<st[x][i])
            {
                q.push({i,g[t.x][i]+t.val});
            }
        }
    }
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>qk;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            g[i][j]=1e18;
            st[i][j]=1e18;
        }
    }
    for(int i=1;i<=n;i++)
    {
        g[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            vec[n+u].push_back({i,v});
            vec[i].push_back({n+u,v});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<vec[i].size();j++)
        {
            for(int k=0;k<vec[vec[i][j].x].size();k++)
            {
                node k1=vec[i][j],k2=vec[k1.x][k];
                long long tmp=k1.val+k2.val;
                g[i][k2.x]=min(g[i][k2.x],tmp);
                g[k2.x][i]=min(g[k2.x][i],tmp);
            }
        }
    }
    //memset(st,0x3f,sizeof st);
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof vis);
        dijkstra(i);
    }
    for(int i=1;i<=qk;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        long long minn=1e18+7;
        for(int i=0;i<vec[n+x].size();i++)
        {
            for(int j=0;j<vec[n+y].size();j++)
            {
                minn=min(vec[n+x][i].val+st[vec[n+x][i].x][vec[n+y][j].x]+vec[n+y][j].val,minn);
            }
        }
        cout<<minn+w[x]+w[y]<<"\n";
    }
    return 0;
}
