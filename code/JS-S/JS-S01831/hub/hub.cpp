#include <bits/stdc++.h>
using namespace std;

inline int read(){
    int x = 0, f = 1;
    char c = getchar();
    while(!isdigit(c)){
        if(c == '-') f = -1;
        c = getchar();
    }
    while(isdigit(c)){
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int n, k;
vector<int> g[N];
int dep[N], up[N][20];
bool fre[N];

void dfs(int u, int fa){
    dep[u] = dep[fa] + 1;
    up[u][0] = fa;
    for(int j = 1;j < 20;j++){
        up[u][j] = up[up[u][j-1]][j-1];
    }
    for(int v : g[u]){
        if(v == fa) continue;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int j = 20;j >= 0;j--){
        if(dep[up[u][j]] >= dep[v]) u = up[u][j];
    }
    if(v == u) return u;
    for(int j = 20;j >=0;j--){
        if(up[u][j] != up[v][j]) u = up[u][j], v = up[v][j];
    }
    return up[u][0];
}

int dis(int u, int v){
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c = read(), t = read();
    while(t--){
        n = read(), k = read();
        for(int i = 0;i < n - 1;i++){
            int u = read(), v = read();
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans =0;
        dfs(1, 0);
        for(int mask = 1;mask <= (1 << n);mask++){
            for(int i = 0;i < n;i++){
                int cnt = 0;
                if(mask >> i & 1){
                    cnt++;
                    fre[i] = 1;
                }
                if(cnt == k){
                    for(int i = 1;i <= n;i++){
                        for(int j = 1;j <= n;j++){
                            if(i < j){
                                int d = dis(i, j);
                                if(fre[i] || fre[j]) d = 0;
                                ans = max(ans, d);
                            }
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
