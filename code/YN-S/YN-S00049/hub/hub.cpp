#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,INF=1e9;
int n,k,hd[N],to[N*2],nxt[N*2],ecnt;
inline void add(int u,int v){to[++ecnt]=v,nxt[ecnt]=hd[u],hd[u]=ecnt;}
int fa[N],sz[N],dep[N],son[N];
void dfs1(int u,int lst){
    fa[u]=lst,sz[u]=1,dep[u]=dep[lst]+1,son[u]=0;
    for(int i=hd[u];i;i=nxt[i]){
        int v=to[i];if(v==lst)continue;
        dfs1(v,u),sz[u]+=sz[v];
        if(sz[v]>sz[son[u]])son[u]=v;
    }
}
int top[N];
void dfs2(int u,int tp){
    top[u]=tp;
    if(son[u])dfs2(son[u],tp);
    for(int i=hd[u];i;i=nxt[i]){
        int v=to[i];if(v==fa[u]||v==son[u])continue;
        dfs2(v,v);
    }
}
inline int lca(int u,int v){
    for(;top[u]^top[v];u=fa[top[u]])if(dep[top[u]]<dep[top[v]])swap(u,v);
    return (dep[u]<dep[v]?u:v);
}
namespace sol1{
    void dfs(int u,int lst,int j,int k,int &res){
        bool chk=1;
        for(int i=hd[u];i;i=nxt[i]){
            int v=to[i];if(v==lst)continue;
            dfs(v,u,j,k,res),chk=0;
        }
        if(chk){
            if(k)res=max(res,min(dep[u]+dep[j]-2*dep[lca(u,j)],dep[u]+dep[k]-2*dep[lca(u,k)]));
            else res=max(res,dep[u]+dep[j]-2*dep[lca(u,j)]);
        }
    }
    inline void sol(){
        cin>>n>>k,ecnt=0;
        for(int i=1;i<=n;i++)hd[i]=0;
        for(int i=1,u,v;i<n;i++)cin>>u>>v,add(u,v),add(v,u);
        dfs1(1,0),dfs2(1,1);
        int ans=INF;
        if(k==1){
            for(int i=1;i<=n;i++){
                int res=dep[i]-1;
                dfs(1,0,i,0,res);
                ans=min(ans,res);
            }
        }
        else{
            for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
                int res=min(dep[i],dep[j])-1;
                dfs(1,0,i,j,res);
                ans=min(ans,res);
            }
        }
        cout<<ans<<'\n';
    }
}
namespace sol2{
    int f[N];vector<int>vec;
    inline int fd(int x){return f[x]==x?x:f[x]=fd(f[x]);}
    int ans;
    void dfs(int p,int x){
        if(x==k){
            for(int i=1;i<=n;i++)fa[i]=i;
            for(int x:vec){
                for(int i=hd[x];i;i=nxt[i]){
                    int y=to[i];auto it=lower_bound(vec.begin(),vec.end(),y);
                    if(*it==y)fa[fd(x)]=fd(y);
                }
            }
            int cnt=0;
            for(int x:vec)cnt+=(fd(x)==x);
            if(cnt<=2){
                int tmp=0;
                for(int i=1;i<=n;i++){
                    int res=INF;
                    for(int j:vec)res=min(res,dep[i]+dep[j]-2*dep[lca(i,j)]);
                    tmp=max(tmp,res);
                }
                ans=min(ans,tmp);
            }
            return;
        }
        if(p>n||n-p+1+x<k)return;
        vec.push_back(p),dfs(p+1,x+1),vec.pop_back(),dfs(p,x);
    }
    inline void sol(){
        cin>>n>>k,ecnt=0,ans=INF;
        for(int i=1;i<=n;i++)hd[i]=0;
        for(int i=1,u,v;i<n;i++)cin>>u>>v,add(u,v),add(v,u);
        dfs1(1,0),dfs2(1,1),dfs(1,0);
        cout<<ans<<'\n';
    }
}
int main(){
    freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int c,T;cin>>c>>T;
    while(T--){
        if(c==7)sol1::sol();
        else sol2::sol();
    }
}
