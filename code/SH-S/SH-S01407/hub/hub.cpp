#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
using ll=long long;
const int N=109,inf=1e9;
int n,k,d[N][N];
vector<int> to[N];
void dfs(int u,int fa,int anc){
    d[anc][u]=d[anc][fa]+1;
    for(auto v:to[u]){
        if(v==fa) continue;
        dfs(v,u,anc);
    }
}
int pa[N];
int fl(int x){
    if(pa[x]==x) return x;
    return pa[x]=fl(pa[x]);
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        to[u].pb(v);
        to[v].pb(u);
    }
    for(int i=1;i<=n;i++){
        d[i][0]=-1;
        dfs(i,0,i);
    }
    int res=inf;
    for(int i=0;i<(1<<n);i++){
        int _=__builtin_popcount(i);
        if(_>k) continue;
        int ans=0;
        for(int j=1;j<=n;j++) pa[j]=j;
        for(int j=1;j<=n;j++){
            if(!(i>>(j-1)&1)) continue;
            for(auto k:to[j]){
                if(!(i>>(k-1)&1)) continue;
                pa[fl(j)]=fl(k);
            }
        }
        int o=0;
        for(int j=1;j<=n;j++){
            if(!(i>>(j-1)&1)) continue;
            if(fl(j)==j) o++;
        }
        if(o>2) continue;
        for(int l=1;l<=n;l++){
            int ret=inf;
            for(int k=1;k<=n;k++){
                if(i&(1<<(k-1))) ret=min(ret,d[k][l]);
            }
            ans=max(ans,ret);
        }
        res=min(res,ans);
    }
    cout<<res<<"\n";
    for(int i=1;i<=n;i++) to[i].clear();
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--) solve();
    return 0; 
}