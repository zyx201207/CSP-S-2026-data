#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr,__VA_ARGS__);
struct FSI{
    template<typename T>
    FSI& operator >> (T&res){
        res=0;T f=1;char ch=getchar();
        while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
        while(isdigit(ch)){res=(res*10)+(ch-48);ch=getchar();}
        res*=f;
        return *this;
    }
} scan;
typedef pair<int,int> pii;
const int N=1e6+5;
const int inf=0x3f3f3f3f;
pii edge[N];
vector<int> G[N];
int n,k,d,dep[N],mxd[N],tmp;
bool ban[N];
namespace brute{
    int dfs(int u,int fa){
        dep[u]=mxd[u]=dep[fa]+1;
        if(ban[u]) tmp=u;
        int res=0;
        for(int v:G[u]){
            if(v==fa) continue;
            if(!ban[u]||!ban[v]) res+=dfs(v,u),mxd[u]=max(mxd[u],mxd[v]);
        }
        res+=(mxd[u]-dep[u]>=d);
        return res;
    }
    bool check(int d){
        ::d=d;
        // debug("d = %d\n",d);
        for(int i=1;i<n;i++){
            int u=edge[i].first,v=edge[i].second;
            ban[v]=true,ban[u]=true;
            // debug("cut %d, %d\n",u,v);
            int f1=inf,f2=inf;
            for(int j=1;j<=n;j++) if(j!=u&&j!=v){
                dep[u]=dep[v]=0;
                int x=dfs(j,0);
                if(tmp==u){
                    // debug("rt = %d, f1 = %d\n",j,x);
                    f1=min(f1,x);
                }
                if(tmp==v){
                    // debug("rt = %d, f2 = %d\n",j,x);
                    f2=min(f2,x);
                }
            }
            ban[u]=ban[v]=false;
            f1=min(f1,dfs(u,v)),f2=min(f2,dfs(v,u));
            f1=max(f1,1),f2=max(f2,1);
            // debug("cut (%d, %d), f1 = %d, f2 = %d\n",u,v,f1,f2);
            if(f1+f2<=k) return true;
        }
        return false;
    }
}
namespace brute2{
    int rt;
    int f[N];
    void dfs(int u,int fa){
        dep[u]=mxd[u]=dep[fa]+1;
        for(int v:G[u]){
            if(v==fa) continue;
            dfs(v,u),mxd[u]=max(mxd[u],mxd[v]);
        }
    }
    void xfs(int u,int fa,int h){
        int mx=dep[u],p=-1,dmx=dep[u];
        for(int v:G[u]){
            if(v==fa) continue;
            if(mxd[v]>mx) dmx=mx,mx=mxd[v],p=v;
            else dmx=max(dmx,mxd[v]);
        }
        f[u]=max(mxd[u]-dep[u],h);
        if(f[u]<f[rt]) rt=u;
        for(int v:G[u]){
            if(v==fa) continue;
            if(v==p) xfs(v,u,max(h,dmx-dep[u])+1);
            else xfs(v,u,max(h,mx-dep[u])+1); 
        }
    }
    bool check(int d){
        ::d=d;
        // debug("d = %d\n",d);
        for(int i=1;i<n;i++){
            int u=edge[i].first,v=edge[i].second;
            // debug("cut (%d, %d)\n",u,v);
            ban[v]=true,ban[u]=true;
            f[0]=inf,rt=0;
            dfs(u,v),xfs(u,v,0);
            // debug("f1 side, rt = %d\n",rt);
            int f1=max(brute::dfs(rt,0),1);
            rt=0,dfs(v,u),xfs(v,u,0);
            int f2=max(brute::dfs(rt,0),1);
            // debug("f1 = %d, f2 = %d\n",f1,f2);
            ban[u]=ban[v]=false;
            if(f1+f2<=k) return true;
        }
        return false;
    }
}
void work(){
    scan>>n>>k;
    // debug("n = %d, k = %d\n",n,k);
    for(int i=1,u,v;i<n;i++){
        scan>>u>>v;
        edge[i]={u,v};
        G[u].emplace_back(v),G[v].emplace_back(u);
    }
    // if(n>3000){
        // debug("n is too big\n");
    // } else {
        int L=0,R=n-1;
        while(L<R){
            int mid=(L+R)>>1;
            if(brute2::check(mid)) R=mid;
            else L=mid+1;
        }
        printf("%d\n",R);
    // }
    for(int i=1;i<=n;i++) G[i].clear();
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    scan>>c>>T;
    while(T--) work();
    return 0;
}