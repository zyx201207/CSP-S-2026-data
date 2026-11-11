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

int T = 1;

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

int c, n, m, d, q, w[500010];
vector<array<int, 2>> s[500010];
int f[510][510];

inline void calc(int& x, int y){
    if(x > y)
        x = y;
}

void solve(){
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
        read(w[i]);
    for(int i = 1, k; i <= n; i++){
        read(k);
        for(int u, l;k--;){
            read(u), read(l);
            s[u].push_back({l, i});
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            f[i][j] = llinf;
    for(int i = 1; i <= n; i++)
        f[i][i] = 0;
    for(int i = 1; i <= m; i++){
        for(auto u : s[i])
            for(auto v : s[i])
                calc(f[u[1]][v[1]], u[0] + v[0]);
    }
    for(int w = 1; w <= n; w++)
        for(int u = 1; u <= n; u++)
            for(int v = 1; v <= n; v++)
                calc(f[u][v], f[u][w] + f[w][v]);
    for(int x, y, ans = llinf; q--; ans = llinf){
        read(x), read(y);
        for(auto u : s[x])
            for(auto v : s[y])
                ans = min(ans, u[0] + v[0] + f[u[1]][v[1]]);
        printf("%lld\n", ans + w[x] + w[y]);
    }
}

signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    // read(T);
    for(;T--;)
        solve();
}
