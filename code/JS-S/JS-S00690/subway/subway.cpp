#include<bits/stdc++.h>
using namespace std;
const int maxm=2e5+5,maxn=505;
int c,n,m,d,q;
long long  wp[maxm];
long long f[maxm][maxn],h[maxn][maxn];
bool vis[maxn],co[maxm];
struct nope{
    int tot=0;
    int w[21];
    long long t[21];
}s[maxm];

void dij(int x)
{
    if(co[x])return;
    co[x]=1;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=s[x].tot;i++)
    {
        f[x][s[x].w[i]]=s[x].t[i];
    }
    for(int j=1;j<=n;j++)
    {
        int t=0;
        for(int i=1;i<=n;i++)
        {
            if(f[x][t]>f[x][i]&&!vis[i])
            {
                t=i;
            }
        }
        vis[t]=1;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            f[x][i]=min(f[x][t]+h[t][i],f[x][i]);
        }
    }
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&wp[i]);
    }
    memset(h,63,sizeof(h));
    memset(f,63,sizeof(f));

    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            s[x].tot++;
            s[x].w[s[x].tot]=i;
            s[x].t[s[x].tot]=y;
        }
    }
    for(int x=1;x<=m;x++)
    {
        for(int i=1;i<=s[x].tot;i++)
        {
            for(int j=1;j<=s[x].tot;j++)
            {
                if(i==j) h[s[x].w[i]][s[x].w[j]]=0;
                else h[s[x].w[i]][s[x].w[j]]=min(s[x].t[i]+s[x].t[j],h[s[x].w[i]][s[x].w[j]]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        long long ans=0x7fffffffffffffff;
        scanf("%d%d",&x,&y);
        dij(x);
        dij(y);
        for(int i=1;i<=n;i++)
        {
            ans=min(f[x][i]+f[y][i],ans);
        }
        ans+=wp[x]+wp[y];
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
