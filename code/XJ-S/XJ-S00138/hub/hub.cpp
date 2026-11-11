#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1e6+10;
int c,T,n,k,dep[N],pos,dis[N];
vector<int> e[N];
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    if (dep[u] > dep[pos]) pos=u;
    for (int v:e[u])
        if (v != fa)
            dfs(v,u);
}
void solve(){
    cin >> n >> k;
    int pos=0;
    for (int i=1;i<=n;i++) e[i].clear();
    for (int i=1,u,v;i<n;i++){
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    dfs(pos,0);
    for (int i=1;i<=n;i++) dis[i]=abs(dep[i]-dep[pos]);
    sort(dis+1,dis+n+1,greater<int>());
    cout << dis[k+1] << '\n';
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> T;
    while (T--) solve();
    return 0;
}