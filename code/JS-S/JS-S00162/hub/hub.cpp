#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
vector<int> g[N];
int fir[N], eular[N], tot, st[22][N], dep[N], lg[N], n, k;

void dfs(int u, int fa){
    fir[u] = ++tot;
    eular[tot] = u;
    for(auto v : g[u]){
        if(v == fa) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        eular[++tot] = u;
    }
}

void build(){
    lg[1] = 0;
    st[0][1] = eular[1];
    for(int i=2; i<=tot; i++) lg[i] = lg[i/2] + 1, st[0][i] = eular[i];
    for(int j=1; j<=tot; j++){
        for(int i=1; i+(1<<j)-1<=n; j++){
            int x = st[j][i];
            int y = st[j][i+(1<<(j-1))];
            st[i][j] = (dep[x] <= dep[y]) ? x : y;
        }
    }
}

int lca(int u, int v){
    int x = fir[u], y = fir[v];
    int len = lg[x-y+1];

}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1; i<=n; i++){
            fir[i] = 0;
            eular[i] = 0;
            g[i].clear();
            dep[i] = 0;
        }
        tot = 0;
        for(int i=1; i<n; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    



    return 0;
}