#include <bits/stdc++.h>
#define endl "\n"
#define con continue
#define ret return
#define pb push_back
#define claer clear
#define rp(i,a,b) for(int i=(a);i<=(b);i++)
#define pr(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
#define int long long
#define N 500005
void out(){
    cout<<endl;
}
template<class X,class ...Y>
void out(X x,Y...y){
    cout<<x;
    if(sizeof...(y)>0) cout<<" ";
    out(y...);
}
vector <int> mp[N];
int n,k;
int vis[N];
int dis[N];
int V[N];
void dfs(int u,int fa){
    if(!vis[u]) ret ;
    V[u]=1;
    for(int v:mp[u]){
        if(v==fa) con;
        dfs(v,u);
    }
}
void dfs2(int u,int fa){
    dis[u]=min(dis[u],dis[fa]+1);
    for(int v:mp[u]){
        if(v==fa) con;
        dfs2(v,u);
    }
}
int check(){
    int cnt=0;
    rp(i,1,n) V[i]=0,dis[i]=1e18;
    for(int i=1;i<=n;i++){
        if((!V[i])&&vis[i]==1){
            cnt++;
            dfs(i,0);
        }
    }
    if(cnt>2) ret 1e18;
    rp(i,1,n){
        if(vis[i]==1){
            dis[i]=0;
            dfs2(i,0);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dis[i]);
    }
    ret ans;
}
void solve(){
    cin>>n>>k;
    rp(i,1,n) mp[i].claer();
    rp(i,1,n-1){
        int u,v;
        cin>>u>>v;
        mp[u].pb(v);
        mp[v].pb(u);
    }
    int ans=1e18;
    rp(s,0,(1<<n)-1){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(s&(1<<(i-1))){
                cnt++;
                vis[i]=1;
            }
            else{
                vis[i]=0;
            }
        }
        if(cnt!=k) con;
        ans=min(ans,check());
    }
    out(ans);
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--) solve();
}
