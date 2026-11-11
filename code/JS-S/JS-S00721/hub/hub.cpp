#include <bits/stdc++.h>
using namespace std;

#define FIO "hub"

using ll = long long;
using pii = pair <int, int>;

const int MOD = 998244353;

int n, k;
vector <int> ch[1000005];

bool ans;
int r;
struct I{
    int sz, dep;
    void extend(){
        dep++;
        if (sz == 0){
            if (dep >= r){
                sz = 1;
                dep = 0;
            }
        } else {
            if (dep > r){
                sz++;
                dep--;
            }
        }
    }
    int get(){
        return max(1, sz);
    }
} f[1000005], g[1000005], suf[1000005], ef[1000005];

inline I mg(I u, const I &v){
    if (u.sz and v.sz){
        return I{u.sz + v.sz + u.dep + v.dep - 1, 0};
    } else if (!u.sz and !v.sz){
        return I{0, max(u.dep, v.dep)};
    } else {
        I tmp = v;
        if (tmp.sz) swap(u, tmp);
        int tot = u.dep + tmp.dep;
        if (tot > r){
            int t = tot - r;
            u.sz += t;
            u.dep -= t;
        }
        return u;
    }
}

int mx = 0;
void build(int u, int dep){
    mx = max(mx, dep);
    for (auto v: ch[u]){
        ch[v].erase(find(ch[v].begin(), ch[v].end(), u));
        build(v, dep + 1);
    }
}

void dfs1(int u){
    f[u] = {0, 0};
    for (auto v: ch[u]){
        dfs1(v);
        ef[v] = f[v];
        ef[v].extend();
        if (f[u].sz and ef[v].sz){
            f[u].sz += ef[v].sz + f[u].dep + ef[v].dep - 1;
            f[u].dep = 0;
        } else if (!f[u].sz and !ef[v].sz){
            f[u].dep = max(f[u].dep, ef[v].dep);
        } else {
            I tmp = ef[v];
            if (tmp.sz) swap(f[u], tmp);
            int tot = f[u].dep + tmp.dep;
            if (tot > r){
                int t = tot - r;
                f[u].sz += t;
                f[u].dep -= t;
            }
        }
    }
}
void dfs2(int u){
    if (u != 1 and f[u].get() + g[u].get() <= k){
        ans = 1;
        return ;
    }
    if (ch[u].empty()) return ;
    I eg = g[u];
    eg.extend();
    int m = ch[u].size();
    suf[m] = {0, 0};
    for (int i = m - 1; i >= 0; i--){
        int v = ch[u][i];
        suf[i] = mg(suf[i + 1], ef[v]);
    }
    for (int i = 0; i < m; i++){
        int v = ch[u][i];
        g[v] = mg(eg, suf[i + 1]);
        
        if (eg.sz and ef[v].sz){
            eg.sz += ef[v].sz + eg.dep + ef[v].dep - 1;
            eg.dep = 0;
        } else if (!eg.sz and !ef[v].sz){
            eg.dep = max(eg.dep, ef[v].dep);
        } else {
            I tmp = ef[v];
            if (tmp.sz) swap(eg, tmp);
            int tot = eg.dep + tmp.dep;
            if (tot > r){
                int t = tot - r;
                eg.sz += t;
                eg.dep -= t;
            }
        }
    }
    for (auto v: ch[u]){
        dfs2(v);
        if (ans) return ;
    }
}

bool calc(int _r){
    r = _r;

    dfs1(1);
    if (f[1].get() <= k) return 1;
    ans = 0;
    g[1] = {0, -1};
    dfs2(1);
    return ans;
}

void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++) ch[i].clear();
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        ch[u].push_back(v);
        ch[v].push_back(u);
    }
    mx = 0;
    build(1, 0);

    if (k == n){
        cout << 0 << "\n";
        return ;
    }
    int l = 0, r = mx + 1;
    while (l + 1 < r){
        int mid = l + r >> 1;
        if (calc(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
}

int main(){
    freopen(FIO".in", "r", stdin);
    freopen(FIO".out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c, t; cin >> c >> t;
    while (t--) solve();

    return 0;
}
// chennie bless me
// ping ce ji neng bu neng pao kuai dian rang wo guo a