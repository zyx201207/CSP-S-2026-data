#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int C,T,n,k,a[N],vis[N],ans;
vector<int> e[N];
void dfs1(int u,int fa){
    vis[u]=0;
    for(int v:e[u]){
        if(v==fa) continue;
        else if(vis[v]){
            dfs1(v,u);
        }
    }
}
bool check(){
    int cnt=0;
    for(int i=1;i<=n;i++){
         vis[i]=a[i];
         if(a[i])cnt++;
    }
    if(cnt!=k) return 0;
    cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) dfs1(i,-1),cnt++;
    }
    if(cnt>2) return 0;
    else return 1;
}
int dfs2(int u,int fa){
    if(a[u]) return 0;
    int minn=LONG_LONG_MAX;
    for(int v:e[u]){
        if(v==fa) continue;
        minn=min(minn,dfs2(v,u)+1);
    }
    return minn;
}
void dfs(int dep){
    if(dep>n){
        if(!check()) return;
        int maxn=0;
        for(int i=1;i<=n;i++){
            maxn=max(maxn,dfs2(i,-1));
        }
        //cout<<maxn<<'\n';
        ans=min(ans,maxn);
        return;
    }
    a[dep]=1;
    dfs(dep+1);
    a[dep]=0;
    dfs(dep+1);
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
    cin>>C>>T;
    while(T--){
        cin>>n>>k;
        ans=INT_MAX;
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1);
        cout<<ans<<'\n';
    }
    return 0;
}
