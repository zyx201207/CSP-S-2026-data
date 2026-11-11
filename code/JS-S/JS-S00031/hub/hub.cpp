#include<bits/stdc++.h>
using namespace std;
#define gc getchar
#define pc putchar
#define mp make_pair
using  pii=pair<int,int>;
using ll=long long;
ll read()
{
    char ch=gc();
    ll x=0;
    for(;ch<'0'||ch>'9';ch=gc());
    for(;ch>='0'&&ch<='9';ch=gc()) x=x*10+ch-'0';
    return x;
}
void write(ll x)
{
    if(x>=10) write(x/10);
    pc(x%10+'0');
}
const int N=1e6+5,inf=0x3f3f3f3f;
int c,t;
int n,k,fa[N];
vector<int> g[N],h[N];
vector<int> taken;
int find(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
void mg(int u,int v)
{
    int ufa=find(u),vfa=find(v);
    if(ufa!=vfa) fa[ufa]=vfa;
}
int dist[N],best=INT_MAX;
void dijkstra(int st)
{
    memset(dist,inf,(n+4)*sizeof(int));
    dist[st]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push(mp(0,st));
    while(!pq.empty())
    {
        int u=pq.top().second,d=pq.top().first;
        if(d!=dist[u]) continue;
        for(auto &v:g[u])
        {
            if(dist[v]>dist[u]+1)
            {
                dist[v]=dist[u]+1;
                pq.push(mp(dist[v],v));
            }
        }
        for(auto &v:h[u])
        {
            if(dist[v]>dist[u])
            {
                dist[v]=dist[u];
                pq.push(mp(dist[v],v));
            }
        }
    }
    return;
}
int process3()
{
    int maxn=-1;
    for(int i=1;i<=n;i++)
    {
        dijkstra(i);
        for(int j=1;j<=n;j++) maxn=max(maxn,dist[i]);
    }

    return maxn;
}
int process2()
{
    for(int i=0;i<taken.size()-1;i++)
    {
        for(int j=i+1;j<taken.size();j++)
        {
            mg(taken[i],taken[j]);
            h[taken[i]].push_back(taken[j]);
            h[taken[j]].push_back(taken[j]);
        }
    }
    int type1=0,type2=0;
    for(int i=0;i<taken.size();i++)
    {
        int got=find(taken[i]);
        if(got!=type1)
        {
            if(type1==0) type1=got;
            else
            {
                if(got!=type2)
                {
                    if(type2==0) type2=got;
                    else return INT_MAX;
                }
            }
        }
    }
    return process3();

}
void choose(int ptr,int use)
{
    if(ptr>n+1) return;
    if(use==k)
    {
        best=min(best,process2());
        return;
    }
    if(ptr==n+1) return;
    taken.push_back(ptr);
    choose(ptr+1,use+1);
    taken.pop_back();
    choose(ptr+1,use);
}
void process()
{
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<=n;i++) h[i].clear();
    n=read();
    k=read();
    best=INT_MAX;
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    choose(1,0);
    write(best);
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    c=read();
    t=read();
    while(t--) process();
}
