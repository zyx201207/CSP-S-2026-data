#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll w[500005],k[505],b[500005][505],x[100005],y[100005],ans,vis[500005];
void dfs(int u,int v,int to)
{
    if(v==to) return;
    int minn=1e9,a=1,e=1;
    for(int i=1;i<=505;i++)
    {
        if(b[u][i]!=0 and b[u][i]<minn)
        {
             minn=b[u][i];
            a=i;
        }

    }
    ans+=minn;
    minn=1e9;
    for(int i=1;i<=k[a];i++)
    {
        if(b[i][a]<minn)
        {
            e=i;
            minn=b[i][a];
        }
    }
    ans+=minn;
    dfs(e,a,to);
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++)
        cin>>w[i];
    for(ll i=1;i<=n;i++)
    {
        cin>>k[i];
        for(ll j=1;j<=k[i];j++)
        {
            int a1,t;
            cin>>a1>>t;
            b[a1][i]=t;
        }
    }
    for(int i=1;i<=q;i++)
        cin>>x[i]>>y[i];
    for(int i=1;i<=q;i++)
    {
        ans=0;
        ans+=w[x[i]]+w[y[i]];
        dfs(x[i],0,y[i]);
        cout<<ans<<"\n";
    }
    return 0;
}
