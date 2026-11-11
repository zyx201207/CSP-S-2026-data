#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>

#define MAXM 20100
#define MAXN 512
typedef long long ll;

struct platform
{
    long station,dis;
};

struct node
{
    long v,w;
};

bool cmp(node a,node b)
{
    return(a.w>b.w);
}

ll w[MAXM]= {},cnt[MAXM]={},stations_line[MAXM][20],stations_dis[MAXM][20];
ll res[MAXM][MAXM]= {};

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll n,m,c,d,q,k,i,j,a,t,x,y;
    std::vector<platform> platforms[MAXN];
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
    for(i=1; i<=m; i++)
        scanf("%lld",&w[i]);
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&k);
        platforms[i].resize(k);
        for(j=0; j<k; j++)
        {
            scanf("%lld %lld",&a,&t);
            platforms[i][j].station=a;
            platforms[i][j].dis=t;
            //stations[a].push_back({i,t});
            stations_line[a][cnt[a]]=i;
            stations_dis[a][cnt[a]]=t;
            cnt[a]++;
        }
    }
    for(i=1;i<=m;i++)
        res[i][i]=1;
    while(q--)
    {
        scanf("%lld %lld",&x,&y);
        if(res[x][x]!=0)
        {
            std::priority_queue<node,std::vector<node>,decltype(&cmp)> pq(cmp);
            long cur,curw;
            for(i=1;i<=m;i++)
                res[x][i]=LONG_MAX;
            pq.push({x,0});
            while(!pq.empty())
            {
                cur=pq.top().v;
                curw=pq.top().w;
                pq.pop();
                if(res[x][cur]<curw)
                    continue;
                res[x][cur]=curw;
                for(i=0;i<cnt[cur];i++)
                {
                    long s_line=stations_line[cur][i],s_dis=stations_dis[cur][i];
                    for(platform to:platforms[s_line])
                        if(res[x][to.station]>curw+s_dis+to.dis)
                        {
                            pq.push({to.station,curw+s_dis+to.dis});
                            res[x][to.station]=curw+s_dis+to.dis;
                        }
                }
            }
        }
        printf("%lld\n",res[x][y]+w[x]+w[y]);
    }
    fclose(stdin);
    fclose(stdout);
    return(0);
}
