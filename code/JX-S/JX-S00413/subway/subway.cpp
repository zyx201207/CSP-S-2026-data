#include<bits/stdc++.h>
using namespace std;
long long h[10500005],nxt[10500005],idx,d1[10500005],ne[500005];
void add(long long u,long long v,long long t)
{
    ++idx;
    ne[u]=idx;
    nxt[idx]=nxt[u];
    nxt[u]=idx;
    h[idx]=v;d1[idx]=t;
}
long long c,n,m,d,q,w[500005],dis[505][505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    memset(dis,0x3f,sizeof(dis));
    cin>>c>>n>>m>>d>>q;
    idx=m;
    for(long long i=1;i<=m;i++)cin>>w[i];
    for(long long i=1;i<=n;i++)
    {
        dis[i][i]=0;
        long long k;cin>>k;
        for(long long j=1;j<=k;j++)
        {
            long long a,t;cin>>a>>t;
            add(a,i,t);
        }
    }
    for(long long i=1;i<=m;i++)
    {
        for(long long j=ne[i];j;j=nxt[j])
        {
            long long a1=h[j],t1=d1[j];
            //cout<<a1<<" "<<t1<<" "<<j<<"\n";
            for(long long k=ne[i];k;k=nxt[k])
            {
                if(j==k)continue;
                long long a2=h[k],t2=d1[k];
                dis[a1][a2]=dis[a2][a1]=min(dis[a1][a2],t1+t2);
            }
        }
    }
    for(long long k=1;k<=n;k++)
    {
        for(long long i=1;i<=n;i++)
        {
            for(long long j=1;j<=n;j++)
            {
                if(i==j)continue;
                dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(long long z=1;z<=q;z++)
    {
        long long x,y;cin>>x>>y;
        long long ans=1000000000000000;
        for(long long j=ne[x];j;j=nxt[j])
        {
            long long a1=h[j],t1=d1[j];
            for(long long k=ne[y];k;k=nxt[k])
            {
                long long a2=h[k],t2=d1[k];
                ans=min(ans,w[x]+w[y]+t1+t2+dis[a1][a2]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
