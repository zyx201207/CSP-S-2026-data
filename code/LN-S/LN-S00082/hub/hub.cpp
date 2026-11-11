#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
struct xxxx
{
    int x,y,w;
};
struct node
{
    long long qq,dd;
    bool operator < (const node& q) const &{
        return dd>q.dd;
    }
};
vector<xxxx>to[maxn*10];
long long dis[maxn],c,n,m,d,q,ii[maxn];
bool vis[maxn];
long long Dij(int root,int sto)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    priority_queue<node> q;
    q.push({root,0});
    vis[root]=1;
    dis[root]=0;
    while(!q.empty())
    {
        node f=q.top();
        q.pop();
        for(xxxx z:to[f.qq])
        {
            long long v=z.y,w=z.w;
            if(!vis[v])
            {
                vis[v]=1;
                if(dis[v]>dis[f.qq]+w)
                {
                    dis[v]=dis[f.qq]+w;
                    q.push({v,dis[v]});
                    if(v==sto)return dis[sto];
                }
            }
        }
    }
    return dis[sto];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        to[m+i].push_back({m+i,i,x});
        to[i].push_back({i,m+i,x});
    }
    for(int i=1;i<=n;i++)
    {
        int k,la=-1;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
            if(la!=-1)
            {
                if(ii[a]==0)
                {
                    ii[a]++;
                }
                to[++ii[a]*m+a].push_back({ii[a]*m+a,la,0});
                to[la].push_back({la,ii[a]*m+a,0});
                to[ii[a]*m+a].push_back({ii[a]*m+a,a,t});
                to[a].push_back({a,ii[a]*m+a,t});

            }
            else
            {
                if(ii[a]==0)
                {
                    ii[a]++;
                }
                to[++ii[a]*m+a].push_back({ii[a]*m+a,a,t});
                to[a].push_back({a,ii[a]*m+a,t});
            }
            la=ii[a]*m+a;
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<Dij(x+m,y+m)<<endl;
    }
    return 0;
}
