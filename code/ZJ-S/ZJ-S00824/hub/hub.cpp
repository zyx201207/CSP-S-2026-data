#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int head[N],cnt,deps[N],lca[5005][5005],Fa[N];
int LCA(int u,int v){
    if(u==v) return u;
    if(lca[u][v]!=-1) return lca[u][v];
    if(deps[u]<deps[v]) swap(u,v);
    return (lca[u][v]=lca[v][u]=LCA(Fa[u],v));
}
struct edge{
    int v,next;
}e[N<<1];
void add_edge(int u,int v){
    e[cnt]=edge{v,head[u]};
    head[u]=cnt++;
}
void DFS(int u,int fa){
    Fa[u]=fa;
    for(int i=head[u];~i;i=e[i].next){
        const int v=e[i].v;
        if(v==fa) continue;
        deps[v]=deps[u]+1;
        DFS(v,u);
    }
}
int find(int x){return (fa[x]==x?x:fa[x]=find(fa[x]));}
void merge(int x,int y){fa[find(x)]=find(y);}
int dis(int u,int v){return deps[u]+deps[v]-2*deps[LCA(u,v)];}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int Case,T;
    cin >> Case >> T;
    while(T--){
        int n,k;
        cin >> n >> k;
        for(int i=0;i<n;++i) head[i]=-1;
        cnt=0;
        for(int i=0,u,v;i<n-1;++i){
            cin >> u >> v;
            --u;
            --v;
            add_edge(u,v);
            add_edge(v,u);
        }
        deps[0]=0;
        DFS(0,-1);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j) lca[i][j]=-1;
        }
        int ans=inf;
        for(int S=0;S<(1<<n);++S){
            if(__builtin_popcount(S)!=k) continue;
            for(int i=0;i<n;++i) fa[i]=i;
            for(int u=0;u<n;++u){
                if((S>>u)&1){
                    for(int i=head[u];~i;i=e[i].next){
                        const int v=e[i].v;
                        if((S>>v)&1) merge(u,v);
                    }
                }
            }
            int cnt=0;
            for(int i=0;i<n;++i){
                if((S>>i)&1){
                    if(fa[i]==i) ++cnt;
                }
            }
            if(cnt<=2){
                int mx=-inf;
                for(int i=0;i<n;++i){
                    int D=inf;
                    for(int u=0;u<n;++u){
                        if((S>>u)&1) D=min(D,dis(u,i));
                    }
                    mx=max(mx,D);
                }
                ans=min(ans,mx);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}