#include<bits/stdc++.h>
using namespace std;
const int maxm=20010;
const int maxn=510;
const int maxk=4000010;
const int maxd=20;
const int maxp=maxd*maxn+3*maxm;
const int INF=1e9+7;
typedef long long ll;
//#define int ll
ll n,m,d,q;

inline ll read(){
    ll s=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s*f;
}

struct node{
    ll to,nxt,val;
}e[maxk];
ll head[maxp],ind=1;
void add_edge(ll u,ll v,ll w){
    e[++ind].to=v;
    e[ind].val=w;
    e[ind].nxt=head[u];
    head[u]=ind;
    //cout<<u<<" "<<v<<" "<<w<<endl;
}

priority_queue< pair<ll,ll> >que;
ll dis[maxp];
bool vis[maxp];
void dij(ll st){
    for(int i=0;i<=(n+1)*d+2*m;i++){
        vis[i]=false;
        dis[i]=INF;
    }
    dis[st]=0;
    que.push( make_pair(0,st) );
    while(!que.empty()){
        int u=que.top().second;
        que.pop();
        if(vis[u]) continue;
        //cout<<u<<endl;
        vis[u]=1;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to,w=e[i].val;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                que.push( make_pair(-dis[v],v) );
            }
        }
    }
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll c=read();
    n=read(),m=read(),d=read(),q=read();
    //建分层图，第(n+1)层及以后依次是为出入口，站厅
    for(int i=1;i<=m;i++){
        ll wx=read();
        ll ent=(n+1)*d+i;
        ll hal=(n+1)*d+m+i;
        add_edge(hal,ent,wx); //建站厅和出入口之间
        add_edge(ent,hal,wx);
    } 
    for(int i=1;i<=n;i++){
        ll former=0;
        ll k=read();
        for(int j=1;j<=k;j++){
            ll a=read(),t=read();
            ll u=i*d+j;
            ll v=d*(n+1)+m+a;
            add_edge(u,v,t); //建站厅与站台之间
            add_edge(v,u,t);
            if(former){
                add_edge(u,former,0); //建线路之间
                add_edge(former,u,0);
            }
            former=u;
        }
    }
    //build();
    while(q--){
        int x=read(),y=read();
        ll st=(n+1)*d+x,en=(n+1)*d+y;
        dij(st);
        printf("%lld\n",dis[en]);
    }
    return 0;
}
