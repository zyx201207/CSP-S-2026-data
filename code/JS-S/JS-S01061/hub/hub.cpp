#include<bits/stdc++.h>
#define int long long
#define inf 1073741823
#define llinf 4611686018427387903
using namespace std;

const int mod = 998244353;
const int D[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
};

int c, T = 1;

int read(){
    int n = 0, f = 1;
    char c = getchar();
    for(;c < '0' || c > '9'; c = getchar())
        if(c == '-')
            f = -1;
    for(;c >= '0' && c <= '9'; c = getchar())
        n = n * 10 + c - '0';
    return n * f;
}

int read(int& n){
    return n = read();
}

int n, k, ans;
vector<int> edges[1000010];
int dist[1010][1010];

inline void dfs1(int u, int* dist){
    for(auto v : edges[u])
        if(dist[v] == -1)
            dist[v] = dist[u] + 1, dfs1(v, dist);
}

vector<int> ch;
bool ok[20], vis[20];

inline void dfs(int x){
    vis[x] = 1;
    for(auto v : edges[x])
        if(ok[v] && !vis[v])
            dfs(v);
}

inline void dfs(int p, int w){
    if(p == n + 1){
        if(w != k)
            return;
        for(int i = 1; i <= n; i++)
            vis[i] = 0;
        int cnt = 0;
        for(auto x : ch){
            if(!vis[x])
                dfs(x), cnt++;
        }
        if(cnt > 2)
            return;
        int rrr = -llinf;
        for(int i = 1; i <= n; i++){
            int res = llinf;
            for(auto x : ch)
                res = min(res, dist[x][i]);
            rrr = max(rrr, res);
        }
        ans = min(ans, rrr);
        return;
    }
    if(w < k)
        ch.push_back(p), ok[p] = 1, dfs(p + 1, w + 1), ch.pop_back(), ok[p] = 0;
    dfs(p + 1, w);
}

void solve(){
    read(n), read(k);
    for(int i = 1; i <= n; i++)
        edges[i].clear();
    for(int i = 1, u, v; i < n; i++)
        read(u), read(v), edges[u].push_back(v), edges[v].push_back(u);
    if(n <= 1000){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) 
                dist[i][j] = -1;
        for(int i = 1; i <= n; i++)
            dist[i][i] = 0, dfs1(i, dist[i]);
    }
    if(n <= 10 && c <= 3){
        ans = llinf, dfs(1, 0), printf("%lld\n", ans);
        return;
    }
    if(k <= 2 && c == 7){
        int ans = llinf;
        for(int i = 1; i < n; i++){
            for(int j = i + 1; j <= n; j++){
                int res = 0;
                for(int k = 1; k <= n; k++)
                    res = max(res, min(dist[i][k], dist[j][k]));
                ans = min(ans, res);
            }
        }
        printf("%lld\n", ans);
        return;
    }
    if(c == 13 || c == 14){
        if(k == 1){
            printf("%lld\n", n / 4 + 1);
            return;
        }
        if(k <= n / 2){
            printf("%lld\n", (n / 2 - k + 2) / 3 + 1);
            return;
        }
        if(k == n)
            puts("0");
        else
            puts("1");
    }
}

signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    read(c), read(T);
    for(;T--;)
        solve();
}
