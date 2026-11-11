#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define scf scanf
#define prf printf
#define fu(_zzz_, _l_, _r_) for(auto _zzz_ = _l_; _zzz_ <= _r_; _zzz_++)
#define fd(_zzz_, _l_, _r_) for(auto _zzz_ = _l_; _zzz_ >= _r_; _zzz_--)

int cdata, n, k;
vector<int> adj[1000010];
int fa[1000010];

int kk;
int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y){
    int fax = find(x), fay = find(y);
    if(fax == fay)return ;
    fa[fax] = fay;
    kk--;
}

int mn[1010];
void dfs(int u, int fa, int dep){
    mn[u] = min(mn[u], dep);
    for(int v : adj[u]){
        if(v != fa){
            dfs(v, u, dep + 1);
        }
    }
}

ll check(int S){
    kk = __builtin_popcount(S);
    if(kk != k)return 1e18;
    fu(i, 1, n){
        fa[i] = i;
        if(S & (1 << (i - 1))){
            for(int v : adj[i]){
                if(S & (1 << (v - 1))){
                    merge(i, v);
                }
            }
        }
    }
    if(kk > 2)return 1e18;
    memset(mn, 0x3f, sizeof(mn));
    fu(i, 1, n){
        if(S & (1 << (i - 1)))dfs(i, 0, 0);
    }
    mn[0] = 0;
    fu(i, 1, n){
        mn[0] = max(mn[0], mn[i]);
    }
    return mn[0];
}

void solve(){
    scf("%d%d", &n, &k);
    fu(i, 1, n)adj[i].clear();
    fu(i, 1, n - 1){
        int u, v;
        scf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = 1e18;
    fu(S, 0, (1 << n) - 1){
        ans = min(ans, check(S));
        // if(check(S) < 1e18)prf("%d %lld\n", S, check(S));
    }
    prf("%lld\n", ans);
}

signed main(){

     freopen("hub.in", "r", stdin);
     freopen("hub.out", "w", stdout);

    int T;
    scf("%d%d", &cdata, &T);
    while(T--){
        solve();
    }

    return 0;
}