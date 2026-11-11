#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=25,M=1e9;
int C,T,n,k,a[N],dis[N][N],f[N];
vector<int> e[N];
int find(int u){
    return f[u]==u?u:f[u]=find(f[u]);
}void dfs(int u,int fa,int d,int s){
    dis[s][u]=d;
    for(int v:e[u])if(v!=fa)
        dfs(v,u,d+1,s);
}void solve(){
    cin>>n>>k;int ans=M;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }for(int i=1;i<=n;++i)
        dfs(i,0,0,i);
    for(int s=0;s<(1<<n);++s){
        if(__builtin_popcount(s)!=k)continue;
        for(int i=1;i<=n;++i)a[i]=((s>>i-1)&1),f[i]=i;
        for(int u=1;u<=n;++u)if(a[u]){
            for(int v:e[u])if(a[v]){
                f[find(v)]=find(u);
            }
        }int ct=0;
        for(int u=1;u<=n;++u)
            if(a[u])ct+=(f[u]==u);
        if(ct>2)continue;
        int cnt=0;
        for(int u=1;u<=n;++u)if(!a[u]){
            int tp=M;
            for(int v=1;v<=n;++v)if(a[v]){
                tp=min(tp,dis[u][v]);
            }cnt=max(cnt,tp);
        }ans=min(ans,cnt);
    }cout<<ans<<'\n';
    for(int i=1;i<=n;++i)e[i].clear();
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    for(cin>>C>>T;T;--T)solve();
    return 0;
}