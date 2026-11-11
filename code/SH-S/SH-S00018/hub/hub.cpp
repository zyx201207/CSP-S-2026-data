#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int T,c;
int n,k;
vector<int> edg[N];
int dep[N];
void dfs(int u,int f){
    dep[u] = dep[f] + 1;
    for(int v : edg[u]){
        if(v!=u)continue;
        dfs(v,u);
    }
}
int cmx = 0,cor = 0;
void dfs2(int u,int f,int ds){
    if(ds > cmx){
        cmx = ds,cor = u;
    }
    for(int v : edg[u]){
        if(v == f)continue;
        dfs2(v,u,ds+1);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> c >> T;
    while(T--){
        cin >> n >> k;
        for(int i = 1; i <= n ; ++ i)edg[i].clear();
        for(int i = 1,u,v; i < n ; ++ i)cin >> u >> v,edg[u].push_back(v),edg[v].push_back(u);
        dfs(1,0);
        int umx = 0,uor = 0;
        cmx = cor = 0;
        for(int i = 1; i <= n ; ++ i){
            if(dep[i] >= umx){
                umx = dep[i],uor = i;
            }
        }
        dfs2(uor,0,0);
        cout << (cmx)/k << "\n";
    }
    return 0;
}