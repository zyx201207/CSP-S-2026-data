#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000005,M=2000005,INF=1e9;
int c,T,n,d;
ll p[N];
int way[N];
inline int read(){
    int x=0,f=1; char ch=getchar_unlocked();
    while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=getchar_unlocked(); }
    while(ch>='0'&&ch<='9'){ x=x*10+ch-'0'; ch=getchar_unlocked(); }
    return x*f;
}
struct edge{
    int to,nxt,w;
}e[M*2];
int head[N],tot=0;
void add(int u,int v,int w){
    e[++tot]={v,head[u],w};
    head[u]=tot;
}
struct Node{
    ll d;
    int u;
    bool operator<(const Node&o) const{
        return d>o.d;
    }
};
ll dis[N];
bool vis[N];
priority_queue<Node>q;
void dijkstra(int s){
    dis[s]=0; way[s]=1;
    q.push({0,s});
    while(!q.empty()){
        Node cur=q.top(); q.pop();
        int u=cur.u;
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to; ll w=e[i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w; way[v]=way[u];
                q.push({dis[v],v});
            }
            else if(dis[v]==dis[u]+w){
				 way[v]++;
				q.push({dis[v],v});
			}
        }
    }
}
void init(int n){
	memset(head,0,sizeof(head)); tot=0;
    memset(vis,0,sizeof(vis));
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(); T=read();
    while(T--){
        n=read(); d=read();
        ll ans=0;
        init(n);
        for(int i=1;i<=n;i++) p[i]=read();
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(p[j]-p[i]>d) continue;
                add(i,j,1);
            }
        }
        for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){ dis[j]=INF; vis[j]=0; way[j]=0; }
            dijkstra(i);
            for(int j=i+1;j<=n;j++) if(way[j]==2) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
