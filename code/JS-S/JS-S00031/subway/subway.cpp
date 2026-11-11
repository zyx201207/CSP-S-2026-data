#include<bits/stdc++.h>
using namespace std;
#define gc getchar
#define pc putchar
#define mp make_pair
using ll=long long;
using pii=pair<int,ll>;
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
const int Q=1e5+5,N=5e5+500+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
long long w[N];
vector<pii>g[N];
void addedge(int u,int v,ll w)
{
    g[u].push_back(mp(v,w));
    g[v].push_back(mp(u,w));
}
ll dist[N];
inline void dijkstra(int st)
{
    memset(dist,inf,sizeof(dist));
    dist[st]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push(mp(0,st));
    while(!pq.empty())
    {
        int u=pq.top().second;
        ll d=pq.top().first;
        pq.pop();
        if(d!=dist[u]) continue;
        for(auto &k:g[u])
        {
            int v=k.first,w=k.second;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                pq.push(mp(dist[v],v));
            }
        }
    }
    return;
}
struct query{
    int from,to,rks;
    ll ans;
}qq[Q];
bool cmp(query a,query b)
{
    return a.from<b.from;
}
bool recmp(query a,query b)
{
    return a.rks<b.rks;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=m;i++) w[i]=read();
    //cout<<"finish1"<<endl;
    int top=m;
    for(int i=1;i<=n;i++)
    {
        top++;
        int k=read();
        for(int j=1;j<=k;j++)
        {
            int a=read();
            int t=read();
            addedge(a,top,t);
        }
    }
    //cout<<"finish2"<<endl;
    for(int i=1;i<=q;i++)
    {
        qq[i].from=read();
        qq[i].to=read();
        qq[i].rks=i;
    }
    sort(qq+1,qq+q+1,cmp);
    //cout<<"finish3"<<endl;
    for(int i=1;i<=q;i++)
    {
        if(qq[i].from==qq[i-1].from)
        {
            qq[i].ans=w[qq[i].from]+dist[qq[i].to]+w[qq[i].to];
            continue;
        }
        dijkstra(qq[i].from);
        qq[i].ans=w[qq[i].from]+dist[qq[i].to]+w[qq[i].to];
        //cout<<"finish4-"<<i<<endl;
    }
    sort(qq+1,qq+q+1,recmp);
    for(int i=1;i<=q;i++)
    {
        write(qq[i].ans);
        pc('\n');
    }
    //cout<<"finish5"<<endl;
    return 0;
}
