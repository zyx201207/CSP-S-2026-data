#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+7;
const int N=509;
int c,n,m,d,q;
int w[M],k[N];
struct kei{
    int v,w;
};
vector<kei>g[5*M];
int dis[5*M];
bool vis[5*M];
int dj(int s,int t)
{
    for(int i=0;i<=m;++i)
    {
        for(int j=-1;j<=d;++j)
        {
            dis[i*d+j+1]=0x5f5f5f5f5f;
            vis[i*d+j+1]=0;
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
    dis[s*d]=0;
    q.push({0,s*d});
    while(!q.empty())
    {
        pair<int,int>x=q.top();
        q.pop();
        int u=x.second;
        if(vis[u])
            continue;
        vis[u]=1;
        for(int i=0;i<g[u].size();++i)
        {
            kei kk=g[u][i];
            int ww=kk.w,v=kk.v;
            if(dis[v]>=dis[u]+ww)
            {
                dis[v]=dis[u]+ww;
                q.push({dis[v],v});
            }
        }
    }
    return dis[t*d];
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    d+=n+1;
    for(int i=1;i<=m;++i)
    {
        scanf("%lld",&w[i]);
        g[i*d].push_back({i*d+1,w[i]});
        g[i*d+1].push_back({i*d,w[i]});
    }
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&k[i]);
        int aa=0;
        //xianlu:i
        for(int j=1;j<=k[i];j++)
        {
            //a  t
            int a,ww;//1--2
            scanf("%lld%lld",&a,&ww);
            g[d*a+1].push_back({d*a+i+1,ww});
            g[d*a+i+1].push_back({d*a+1,ww});
            if(j!=1)
            {
                g[a*d+i+1].push_back({aa*d+i+1,0});
                g[aa*d+i+1].push_back({a*d+i+1,0});
            }
            aa=a;
        }
    }
    while(q--)
    {
        int s,t;
        scanf("%lld%lld",&s,&t);
        printf("%lld\n",dj(s,t));
    }
    return 0;
}
