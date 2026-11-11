#include<bits/stdc++.h>

using namespace std;

#define int long long
#define uint unsigned long long
#define inf (LLONG_MAX>>1)

constexpr int maxn=5e2+10;
constexpr int maxm=5e5+10;
constexpr int maxq=1e5+10;

int c,n,m,d,q;
int w[maxm];
int k[maxn];
int t[maxm][maxn];
int gra[maxn][maxn];
vector<int> subs[maxm];

int x,y;

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;++i)
    {
        scanf("%lld",&w[i]);
    }

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(i==j) gra[i][j]=0;
            else gra[i][j]=inf;
        }
    }

    //cerr<<"ok0\n";

    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&k[i]);
        //cerr<<"running "<<i<<'\n';
        for(int j=1;j<=k[i];++j)
        {
            int idx;
            scanf("%lld",&idx);
            scanf("%lld",&t[idx][i]);
            //cerr<<i<<" ok!\n";
            for(int x:subs[idx])
            {
                gra[i][x]=min(gra[i][x],t[idx][i]+t[idx][x]);
                gra[x][i]=min(gra[x][i],t[idx][i]+t[idx][x]);
            }
            subs[idx].emplace_back(i);
        }
    }
    //cerr<<"ok1\n";

    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                gra[i][j]=min(gra[i][j],gra[i][k]+gra[k][j]);
            }
        }
    }
    //cerr<<"ok2\n";
/*
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            printf("%lld ",gra[i][j]);
        }
        printf("\n");
    }
*/

    while(q--)
    {
        scanf("%lld%lld",&x,&y);
        int ans=inf;
        for(int i:subs[x])
        {
            for(int j:subs[y])
            {
                int val=gra[i][j];
                val+=t[x][i]+t[y][j];
                //printf("%lld %lld %lld\n",gra[i][j],t[x][i],t)
                ans=min(ans,val);
            }
        }
        ans+=w[x]+w[y];
        printf("%lld\n",ans);
    }
    return 0;
}