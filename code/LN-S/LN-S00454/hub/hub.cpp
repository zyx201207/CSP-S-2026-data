#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define inf 1e18
#define ls (2 * k)
#define rs (2 * k + 1)
using namespace std;
// hub
const int mod = 1e9 + 7;
const int N = 1e6 + 5, M = 5e5 + 5;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
mt19937_64 rng(time(0));

int Case, n, k, ans;
int dep[N], pl[N][25];
vector <int> E[N];

void dfs(int x, int fa){
    dep[x] = dep[fa] + 1, pl[x][0] = fa;
    for(int i = 1;i <= 20; i++)
        pl[x][i] = pl[pl[x][i - 1]][i - 1];
    for(auto to : E[x]){
        if(to == fa) continue;
        dfs(to, x);
    }
    return ;
}

inline int LCA(int x, int y){
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = 20;i >= 0; i--){
        if(dep[pl[x][i]] < dep[y]) continue;
        x = pl[x][i];
    }
    if(x == y) return x;
    for(int i = 20;i >= 0; i--){
        if(pl[x][i] == pl[y][i]) continue;
        x = pl[x][i], y = pl[y][i];
    }
    return pl[x][0];
}

inline int getdis(int x, int y){
    int L = LCA(x, y);
    return dep[x] + dep[y] - 2 * dep[L];
}

struct dsu{
    bool in[N];
    int f[N], siz[N];
    int find(int x){
        if(f[x] == x) return x;
        return f[x] = find(f[x]);
    }
    inline void merge(int x, int y){
        int rx = find(x), ry = find(y);
        if(rx == ry) return ;
        if(siz[rx] > siz[ry]) swap(rx, ry);
        f[rx] = ry, siz[ry] += siz[rx], in[ry] |= in[rx];
        return ;
    }
}G;

void work(){
    ans = inf;
    for(int s = 0;s < (1ll << n); s++){
        int cnt = 0;
        for(int i = 0;i < n; i++)
            if(s & (1ll << i)) cnt += 1;
        if(cnt != k) continue;
        int now = 0;
        for(int i = 0;i < n; i++){
            int nx = inf;
            for(int j = 0;j < n; j++){
                if(!(s & (1ll << j))) continue;
                nx = min(nx, getdis(i + 1, j + 1));
            }
            now = max(now, nx);
        }
        for(int i = 1;i <= n; i++){
            G.f[i] = i, G.siz[i] = 1;
            G.in[i] = ((s & (1ll << (i - 1))) ? true : false);
        }
        for(int i = 0;i < n; i++){
            if(!(s & (1ll << i))) continue;
            for(auto j : E[i + 1]){
                if(!(s & (1ll << (j - 1)))) continue;
                G.merge(i + 1, j);
            }
        }
        int num = 0;
        for(int i = 1;i <= n; i++)
            if(G.in[G.find(i)] == true && G.find(i) == i) num += 1;
        if(num <= 2) ans = min(ans, now);
    }
    return ;
}

inline void init(){
    for(int i = 1;i <= n; i++){
        E[i].clear(), dep[i] = 0;
        for(int j = 1;j <= 20; j++) pl[i][j] = 0;
    }
    return ;
}
inline void solve(){
    cin >> n >> k;
    for(int i = 1, u, v;i < n; i++){
        cin >> u >> v;
        E[u].push_back(v), E[v].push_back(u);
    }
    dfs(1, 0); work();
    cout << ans << "\n";
    init();
    return ;
}
signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int tc = 1;
    cin >> Case >> tc;
    while(tc--) solve();
    
    return 0;
}