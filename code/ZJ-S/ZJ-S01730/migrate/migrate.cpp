#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int C,T,n,L,to[N],f[N],g[N],vis[N],tot,s[N],p[N],vis2[N],cnt[N];
long long m,ans,a[N];
void solve(int l,int r)
{
    for(int v=r;v>l;v--)
    {
        f[v]=g[v]=0;
        for(int u=v-1;u>=l;u--)
        {
            if(to[u]>=v)g[u]=1;
            else g[u]=g[to[u]]+1;
        }
        for(int u=v-1;u>=l;u--)
        {
            if(to[u]>=v)f[u]=0;
            else f[u]=f[to[u]];
            if(f[u]==1)ans++;
            if(g[u-1]==g[u])f[u]++;
            if(u>2&&g[u-2]==g[u])f[u]++;
        }
        // for(int i=1;i<=tot;i++)vis2[i]=0;
    }
    return;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--)
    {
        scanf("%d%lld",&n,&m),ans=0;
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]),vis[i]=cnt[i]=0;
        for(int l=1,r=0;l<=n;l++)
        {
            for(r=max(r,l);r<n&&a[r+1]-a[l]<=m;r++);
            to[l]=r,cnt[r]++;
        }
        L=1;
        for(int i=1;i<n;i++)if(a[i+1]-a[i]>m)solve(L,i),L=i+1;
        if(L<=n)solve(L,n);
        printf("%lld\n",ans);
    }
    return 0;
}