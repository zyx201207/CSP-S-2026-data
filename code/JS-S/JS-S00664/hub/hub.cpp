#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e6+5;
int C,T;
int n,k;
vector<int> e[MAXN];
int dep[MAXN];
int f[MAXN][24];
int deg[MAXN];
vector<int> ans;
void dfs(int u,int fa){
    f[u][0]=fa;
    dep[u]=dep[fa]+1;
    for(auto&v:e[u]) if(v!=fa) dfs(v,u);
    return;
}
void st(){
    for(int i=1;(1<<i)<=n;i++)
        for(int j=1;j<=n;j++)
            f[j][i]=f[f[j][i-1]][i-1];
    return;
}
int lca(int x,int y){
    if(dep[x]>dep[y]) swap(x,y);
    for(int i=22;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    if(x==y) return x;
    for(int i=22;i>=0;i--) if(f[x][i]!=f[y][i]){x=f[x][i];y=f[y][i];}
    return f[x][0];
}
int dis(int x,int y){
    int z=lca(x,y);
    return dep[x]+dep[y]-(dep[z]<<1);
}
void choose(int u,int k){
    if(k==0) return;
    ans.push_back(u);
    k--;
    if(k==0) return;
    int num=k/e[u].size();
    for(auto&v:e[u]) choose(v,num);
    return;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>C>>T;
    while(T--){
        for(int i=1;i<=n;i++) e[i].clear();
        memset(dep,0,sizeof(dep));
        memset(f,0,sizeof(f));
        memset(deg,0,sizeof(deg));
        ans.clear();
        cin>>n>>k;
        for(int i=1;i<n;i++){int u,v;cin>>u>>v;e[u].push_back(v);e[v].push_back(u);deg[u]++;deg[v]++;}
        dfs(1,0);
        st();
        int maxdeg=0,s=0;
        for(int i=1;i<=n;i++) if(maxdeg<deg[i]){maxdeg=deg[i];s=i;}
        choose(s,k);
        int res=0x7fffffff;
        for(auto&u:ans)
            for(auto&v:ans){
                if(u==v) continue;
                res=min(res,dis(u,v));
            }
        cout<<res<<'\n';
    }
    return 0;
}
