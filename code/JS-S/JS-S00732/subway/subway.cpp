#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<cstring>
using namespace std;
long long w[500010],dis[510][510],inf=0x7f7f7f7f7f7f7f7fll;
vector< pair<long long,long long> > a[510],e[500010];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x7f,sizeof(dis));
    long long c,n,m,d,q,k,p,t;
    pair<long long,long long> nw;
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=0;i<m;i++)
    {
        scanf("%lld",&w[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&k);
        for(int j=0;j<k;j++)
        {
            scanf("%lld%lld",&p,&t);
            p--;
            a[i].push_back({p,t});
            for(int k=0;k<e[p].size();k++)
            {
                nw=e[p][k];
                dis[nw.first][i]=min(dis[nw.first][i],t+nw.second);
                dis[i][nw.first]=min(dis[i][nw.first],t+nw.second);
            }
            e[p].push_back({i,t});
        }
    }
    for(int i=0;i<n;i++)
    {
        dis[i][i]=0;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dis[i][k]!=inf&&dis[k][j]!=inf&&dis[i][k]+dis[k][j]<dis[i][j])
                {
                    dis[i][j]=dis[i][k]+dis[k][j];
                    dis[j][i]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    int x,y,stx,sty;
    long long ans=0;
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&x,&y);
        x--;
        y--;
        ans=inf;
        for(int j=0;j<e[x].size();j++)
        {
            for(int k=0;k<e[y].size();k++)
            {
                stx=e[x][j].first;
                sty=e[y][k].first;
                if(dis[stx][sty]!=inf)
                {
                 //   printf("%lld %lld %lld %lld %lld\n",dis[stx][sty],w[x],w[y],e[x][j].second,e[y][k].second);
                    ans=min(ans,dis[stx][sty]+w[x]+w[y]+e[x][j].second+e[y][k].second);
                }
            }
        }
        printf("%lld\n",ans);
    }

    return 0;
}
