/*#include<bits/stdc++.h>
#define int long long
#define PI pair<int,int>
using namespace std;
const int N=5e5+3,inf=5e17;
int c,n,m,d,q,w[N],dis[N];
vector<int>rt,tms;
vector<PI>g[N];
map<PI,int>mp;
/*
思考：现在的问题是边实在太多了
可以开一个map把边存其来
接下来每次进来一个q，跑一次dijkstra

priority_queue<PI,vector<PI>,greater<PI> >qq;
bool vis[N];
void dijkstra(int st)
{
    while(!qq.empty())qq.pop();
    for(int i=1;i<=m;++i)dis[i]=inf,vis[i]=0;
    qq.push({0,st});dis[st]=0;
    while(!qq.empty())
    {
        int u=qq.top().second;qq.pop();
        if(vis[u])continue;vis[u]=1;
        for(auto x:g[u])
        {
            int v=x.first,w=x.second;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                qq.push({dis[v],v});
            }
        }
    }
    for(int i=1;i<=m;++i)
        if(i!=st)mp[{min(i,st),max(i,st)}]=dis[i];
}
/*queue<PI>qqq;
void Dijkstra(int st,int ed)
{
    while(!qqq.empty())qqq.pop();
    for(int i=1;i<=m;++i)dis[i]=inf,vis[i]=0;
    qqq.push({0,st});dis[st]=0;
    while(!qqq.empty())
    {
        int u=qqq.front().second;qqq.pop();
        if(vis[u])continue;vis[u]=1;
        for(auto x:g[u])
        {
            int v=x.first,w=x.second;
            if(vis[v])continue;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(v==ed)return;
                if(!vis[v])qqq.push({w,v});
            }
        }
    }
    for(int i=1;i<=m;++i)
        if(i!=st)mp[{min(i,st),max(i,st)}]=dis[i];
}
signed main()
{
#define FILE "subway"
//freopen(FILE".in","r",stdin);
//freopen(FILE".out","w",stdout);
cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)cin>>w[i];
    int stw=-1,ok=1;
    for(int i=1;i<=n;++i)
    {
        int siz;cin>>siz;
        while(siz--)
        {
            int x,tt;cin>>x>>tt;
            rt.push_back(x);tms.push_back(tt);
        }
        siz=rt.size();
        /*if(ok)
        {
            for(int i1=0;i1<siz;++i1)
            {
                int u=rt[i1],v1=rt[0],v2=rt[siz-1];
                if(i!=0)mp[{min(u,v1),max(u,v1)}]=tms[i1]*2;
                if(i!=siz-1)mp[{min(u,v2),max(u,v2)}]=tms[i1]*2;
            }
        }
        else
        {
        for(int i1=0;i1<siz;++i1)
            for(int i2=i1+1;i2<siz;++i2)
            {
                int u=rt[i1],v=rt[i2];
                if(u>v)swap(u,v);
                if(mp.find({u,v})==mp.end())mp[{u,v}]=inf;
                mp[{u,v}]=min(mp[{u,v}],tms[i1]+tms[i2]);
            }
    }
    //cout<<mp.size()<<endl;
    for(auto it:mp)
    {
        int u=it.first.first,v=it.first.second,w=it.second;
        g[u].push_back({v,w});g[v].push_back({u,w});
        //cout<<u<<' '<<v<<' '<<w<<endl;
    }
    mp.clear();
    //cout<<ok<<endl;
    while(q--)
    {
        int l,r;cin>>l>>r;
        if(l>r)swap(l,r);
        if(l==r)cout<<"0\n";
        else if(mp.find(make_pair(l,r))!=mp.end())cout<<mp[{l,r}]+w[l]+w[r]<<"\n";
        else
        {
            dijkstra(l);
            cout<<mp[{l,r}]+w[l]+w[r]<<"\n";
        }
    }
    return 0;
}

总步行时间都尽可能少
也就是地铁用时不算了，发现c,d不重要
先发现t(x->y)=t(y->x)
dp[i][j]表示从第i条线路转到第j号站台的最少用时
第一种:i->j也就是i号站台和j号站台在同一条线路上
如果不在呢？
考虑枚举k号站台(类似floyd放在最外面)

这道题目我好像是在哪里见过？
显然是动态规划

*/
#include<bits/stdc++.h>
#define int long long
#define PI pair<int,int>
using namespace std;
const int M=5e5+3,inf=5e17;
vector<int>rt,tms;
int dis[1001][1001],c,n,m,d,q,w[M];
signed main()
{
#define FILE "subway"
freopen(FILE".in","r",stdin);
freopen(FILE".out","w",stdout);
cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)cin>>w[i];
    
        for(int i=1;i<=m;++i)
            for(int j=1;j<=m;++j)
            {
                if(i==j)dis[i][j]=0;
                else dis[i][j]=inf;
            }
    for(int i=1;i<=n;++i)
    {
        rt.clear();tms.clear();
        int siz;cin>>siz;
        while(siz--)
        {
            int x,tt;cin>>x>>tt;
            rt.push_back(x);tms.push_back(tt);
        }
        siz=rt.size();
        for(int i1=0;i1<siz;++i1)
            for(int i2=i1+1;i2<siz;++i2)
            {
                int u=rt[i1],v=rt[i2];
                dis[u][v]=dis[v][u]=min(dis[u][v],tms[i1]+tms[i2]);
            }
    }
    for(int k=1;k<=m;++k)
    {
        for(int i=1;i<=m;++i)
            for(int j=1;j<=m;++j)
                if(i!=j)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    }
    while(q--)
    {
        int l,r;cin>>l>>r;
        cout<<w[l]+w[r]+dis[l][r]<<"\n";
    }
    return 0;
}
/*
总步行时间都尽可能少
也就是地铁用时不算了，发现c,d不重要
先发现t(x->y)=t(y->x)
dp[i][j]表示从第i条线路转到第j号站台的最少用时
第一种:i->j也就是i号站台和j号站台在同一条线路上
如果不在呢？
考虑枚举k号站台(类似floyd放在最外面)

这道题目我好像是在哪里见过？
显然是动态规划

dp[]
*/