#include <bits/stdc++.h>
using namespace std;
struct node
{
    long long d,ti;
};
long long c,n,m,d,r;
long long w,t;
long long a[500002];
long long dis[1500002];
int vis[1500002];
vector<node>g[1500002];
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >q;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&r);
    node gi;
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&w);
        gi.d=i+m;
        gi.ti=w;
        g[i].push_back(gi);
        gi.d=i;
        g[i+m].push_back(gi);
    }
    long long k;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&k);
        for(int j=1;j<=k;j++)
        {
            scanf("%lld%lld",&a[i],&t);
            gi.d=i+2*m;
            gi.ti=t;
            g[a[i]+m].push_back(gi);
            gi.d=a[i]+m;
            g[i+2*m].push_back(gi);
        }
    }
    while(r--)
    {
        long long u,v;
        scanf("%lld%lld",&u,&v);
        memset(dis,0x3f3f3f3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<g[u].size();i++)
        {
            dis[g[u][i].d]=g[u][i].ti;
        }
        dis[u]=0;
        q.push(make_pair(0,u));
        node q1,qq;
        while(!q.empty())
        {
            q1.ti=q.top().first;
            q1.d=q.top().second;
            vis[q1.d]=1;
            q.pop();
            for(int i=0;i<g[q1.d].size();i++)
            {
                qq=g[q1.d][i];
                if(qq.d!=q1.d&&vis[qq.d]==0&&dis[qq.d]>=dis[q1.d]+qq.ti)
                {
                    dis[qq.d]=dis[q1.d]+qq.ti;
                    q.push(make_pair(dis[qq.d],qq.d));
                }
            }
        }
        printf("%lld\n",dis[v]);
    }
    return 0;
}
