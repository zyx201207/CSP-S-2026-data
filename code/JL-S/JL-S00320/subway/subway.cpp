#include<bits/stdc++.h>
using namespace std;
long long INF=1e12;
long long c,n,m,d,q;
long long w[5000005],k[5000005],a[505][100005],t[505][100005];
long long head[5000005],cnt,dis[5000005],vis[5000005];
struct node
{
    long long next,ww,to;
}aa[5000005];
void add(long long from,long long to,long long ww)
{
    cnt++;
    aa[cnt].to=to;
    aa[cnt].ww=ww;
    aa[cnt].next=head[from];
    head[from]=cnt;
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) head[i]=-1;
    for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&k[i]);
        for(int j=1;j<=k[i];j++)
        {
            scanf("%lld%lld",&a[i][j],&t[i][j]);
            for(int l=1;l<=j-1;l++)
            {
                add(a[i][j],a[i][l],t[i][j]+t[i][l]);
                add(a[i][l],a[i][j],t[i][j]+t[i][l]);
            }
        }
    }
    while(q--)
    {
        long long x,y;
        scanf("%lld%lld",&x,&y);
        for(int i=1;i<=m;i++) dis[i]=INF;
        dis[x]=0;
        queue<long long> q;
        q.push(x);
        vis[x]=1;
        while(q.empty()==false)
        {
            long long u=q.front();
            q.pop();
            vis[u]=0;
            for(int i=head[u];i!=-1;i=aa[i].next)
            {
                long long to=aa[i].to,ww=aa[i].ww;
                if(dis[to]>dis[u]+ww)
                {
                    dis[to]=dis[u]+ww;
                    if(vis[to]==0)
                    {
                        vis[to]=1;
                        q.push(to);
                    }
                }
            }
        }
        printf("%lld\n",dis[y]+w[x]+w[y]);
    }
    return 0;
}
