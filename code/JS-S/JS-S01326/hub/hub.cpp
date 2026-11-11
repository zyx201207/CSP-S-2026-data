#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
int c,t;
vector<int> g[100005];
int nxt[100005];
int far,fd;
void dfs1(int x,int fa,int dep){
    if (dep>fd){
        fd=dep;
        far=x;
    }
    for (int u:g[x]){
        if (u!=fa) dfs1(u,x,dep+1);
    }
    return;
};
int dfs2(int x,int fa){
    int ret=0;
    for (int u:g[x]){
        if (u!=fa){
            ret=max(ret,dfs2(u,x)+1);
        }
    }
    return ret;
}
void solve(){
    int n,k,u,v;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        g[i].clear();
    }
    for (int i=1;i<=n-1;i++){
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs1(1,0,0);
    int D=dfs2(far,0);
    if (k==2){
        cout<<D/3<<'\n';
        return;
    }
    if (k==n){
        cout<<0<<'\n';
        return;
    }
    cout<<D/2<<'\n';
    return;
}
int main(){
    freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
