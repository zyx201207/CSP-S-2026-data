#include <bits/stdc++.h>
using namespace std;
const long long M=5e5+5;
long long c,n,m,d,q;
long long w[M];
long long k[55];
long long a[55][M];
long long ans=0;
long long cnt;
bool f[M];
long long x,y;
long long t;
vector<long long> pq[M];
void dfs(long long u,long long dep)
{
    if (u==y)
    {
        cnt=min(cnt,dep);
        return;
    }
    for (long long i=0;i<pq[u].size();++i)
    {
        if (!f[pq[u][i]])
        {
            f[pq[u][i]]=true;
            dfs(pq[u][i],dep+1);
            f[pq[u][i]]=false;
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for (int i=1;i<=m;++i)
        scanf("%lld",&w[i]);
    for (long long i=1;i<=n;++i)
    {
        scanf("%lld",&k[i]);
        scanf("%lld%lld",&a[i][1],&t);
        for (long long j=2;j<=k[i];++j)
        {
            scanf("%lld%lld",&a[i][j],&t);
            pq[a[i][j]].push_back(a[i][j-1]);
            pq[a[i][j-1]].push_back(a[i][j]);
        }
    }
    while (q--)
    {
        ans=0;
        scanf("%lld%lld",&x,&y);
        ans+=w[x]+w[y];
        cnt=INT_MAX;
        memset(f,0,sizeof(f));
        dfs(x,0);
        ans+=cnt*t;
        printf("%lld\n",ans);
    }
    return 0;
}
