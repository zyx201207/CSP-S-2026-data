#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=35;

ll c,t,n,k;
vector<int> g[N];

bool vis[N];

void dfs(ll s,int u,int fa){
    vis[u]=1;
    for(auto v:g[u]){
        if(v==fa) continue;
        if((s>>v-1)&1) dfs(s,v,u);
    }
}

int dfs2(int u,int fa){
    if(vis[u]) return 0;
    int res=n;
    for(auto v:g[u]){
        if(v==fa) continue;
        res=min(res,dfs2(v,u)+1);
    }
    return res;
}

void solve(){
    cin>>n>>k;
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans=n;
    for(ll s=1;s<(1<<n);s++){
        if(__builtin_popcount(s)!=k) continue;
        for(int i=1;i<=n;i++) vis[i]=0;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(!((s>>i-1)&1)) continue;
            if(!vis[i]) dfs(s,i,0),cnt++;
        }
        if(cnt>2) continue;
        int maxn=0;
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            maxn=max(maxn,dfs2(i,0));
        }
        ans=min(ans,maxn);
    }
    cout<<ans<<"\n";
    for(int i=1;i<=n;i++) g[i].clear();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--) solve();
    return 0;
}