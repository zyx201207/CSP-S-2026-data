#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
int C,n,m,d,q,idx,w[M],hd[M],to[M],len[M],nxt[M];
long long f[N][N];
vector<pair<int,int>>e[N];
void add(int u,int v,int w)
{
    ++idx,to[idx]=v,len[idx]=w,nxt[idx]=hd[u],hd[u]=idx;
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&C,&n,&m,&d,&q);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=1e18;
    for(int i=1;i<=n;i++)f[i][i]=0;
    for(int i=1;i<=m;i++)scanf("%d",&w[i]);
    for(int i=1,k;i<=n;i++)
    {
        scanf("%d",&k);
        for(int j=1,x,y;j<=k;j++)scanf("%d%d",&x,&y),add(x,i,y);
    }
    for(int i=1;i<=m;i++)for(int i1=hd[i];i1;i1=nxt[i1])for(int i2=hd[i];i2;i2=nxt[i2])f[to[i1]][to[i2]]=min(f[to[i1]][to[i2]],1ll*len[i1]+len[i2]);
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--)
    {
        int x,y;
        long long ans=1e18;
        scanf("%d%d",&x,&y);
        for(int i1=hd[x];i1;i1=nxt[i1])for(int i2=hd[y];i2;i2=nxt[i2])ans=min(ans,f[to[i1]][to[i2]]+len[i1]+len[i2]);
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}