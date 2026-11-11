#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
const int M=1e8;
int c,n,m,d,T,a[N],xx;
ll w[500005],t[500005],tw[M],idx,ne[M],dj[500005],vis[500005],h[500005],yy,ans;
priority_queue<pair<long long,int>> q;
int e[M];
void add(int x,int y,int z)
{
    e[++idx]=y;
    ne[idx]=h[x];
    tw[idx]=z;
    h[x]=idx;
}
void dijstra(int s)
{
    dj[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vis[u]==1) continue;
        vis[u]=1;
        for(ll i=h[u];i!=-1;i=ne[i])
        {
            int v=e[i];
            if(dj[v]>dj[u]+tw[i])
            {
                dj[v]=dj[u]+tw[i];
                q.push(make_pair(-dj[v],v));
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>T;
    memset(h,-1,sizeof(h));
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>xx>>yy;
            a[j]=xx;
            t[xx]=yy;
        }
        for(int j=1;j<=k;j++)
        {
            for(int p=1;p<=k;p++)
            {
                if(j==p) continue;
                int u=a[j];
                int v=a[p];
                add(u,v,t[u]+t[v]);
            }
        }
    }
    while(T--)
    {
        int x,y;
        cin>>x>>y;
        memset(dj,0x3f,sizeof(dj));
        memset(vis,0,sizeof(vis));
        dijstra(x);
        ans=dj[y]+w[x]+w[y];
        cout<<ans<<endl;
    }
    return 0;
}


