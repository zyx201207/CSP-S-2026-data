#include<bits/stdc++.h>
using namespace std;
#define gc getchar
#define pc putchar
#define mp make_pair
using ll=long long;
using pii=pair<ll,int>;
using ppp=pair<int,ll>;
ll read()
{
    char ch=gc();
    ll x=0,f=1;
    for(;ch<'0'||ch>'9';ch=gc())if(ch=='-') f=-1;
    for(;ch>='0'&&ch<='9';ch=gc()) x=x*10+ch-'0';
    return x*f;
}
void write(ll x)
{
    if(x>=10) write(x/10);
    pc(x%10+'0');
}
int c,t;
const int N=2e6+5;
const ll inf=2e9+5;
int n;
ll d,x[N];
ll dist[N];
int cnt[N];
vector<ppp> g[N];
void init()
{
    fill(dist,dist+n+1,inf);
    memset(cnt,0,(n+3)*sizeof(int));

}
ll dijkstra(int st)
{
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push(mp(0,st));
    dist[st]=0;
    cnt[st]=1;
    while(!pq.empty())
    {
        int u=pq.top().second;
        ll d=pq.top().first;
        pq.pop();
        if(d!=dist[u]) continue;
        for(auto &k:g[u])
        {

            int v=k.first;
            ll w=k.second;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                pq.push(mp(dist[v],v));
                cnt[v]=cnt[u];
            }
            else if(dist[v]==dist[u]+w) cnt[v]+=cnt[u];
        }
    }
    ll res=0;
    for(int i=st+1;i<=n;i++)
    {
        if(cnt[i]==2)
        {
            res++;
        }
    }
    init();
    return res;
}

void addedge(int u,int v,ll w)
{
    g[u].push_back(mp(v,w));
    g[v].push_back(mp(u,w));
}
void process()
{

    n=read();d=read();
    fill(dist,dist+n+1,inf);
    for(int i=1;i<=n;i++) x[i]=read();
    for(int i=1;i<n;i++)
    {
        int ptr=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
        for(int j=i+1;j<=ptr;j++)
        {
            if(abs(x[j]-x[i])>d) continue;
            addedge(i,j,abs(x[i]-x[j]));
        }
    }

    ll ans=0;
    for(int i=1;i<n;i++)
    {
        ans+=dijkstra(i);
    }
    write(ans);
    pc('\n');
    return;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    c=read();
    t=read();
    while(t--) process();
}
