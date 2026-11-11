#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n, k;
vector<int> g[N];
inline void readin(){
    cin >> n >> k;
    for (int i=1;i<=n;++i) g[i].clear();
    for (int i=1, u, v;i<n;++i){
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
}
namespace force{
    const int N = 1003;
    int dis[N][N], s, vis;
    void dfs(int x, int fa, int rt){
        for (int i:g[x]){
            if (i==fa) continue;
            dis[rt][i] = dis[rt][x]+1;
            dfs(i, x, rt);
        }
    }
    void dfs2(int x, int fa){
        vis |= 1<<x-1;
        for (int i:g[x]) if (i!=fa&&(s>>i-1&1)) dfs2(i, x);
    }
    inline bool chk(int S){
        int cnt = 0;
        vis = 0, s = S;
        for (int i=0;i<n;++i){
            if ((S>>i&1)&&!(vis>>i&1)){
                ++cnt;
                dfs2(i+1, 0);
            }
        }
        // fprintf(stderr, "S=%d cnt=%d\n", S, cnt);
        return cnt<=2;
    }
    void main(){
        for (int i=1;i<=n;++i) dfs(i, 0, i);
        int ans = 1e9;
        for (int i=0;i<(1<<n);++i){
            if (__builtin_popcount(i)!=k) continue;
            if (!chk(i)) continue;
            // fprintf(stderr, "test: i=%d\n", i);
            int mx = 0;
            for (int j=0;j<n;++j) if (!(i>>j&1)) {
                int mn = 1e9;
                for (int k=0;k<n;++k) if (i>>k&1){
                    mn = min(mn, dis[j+1][k+1]);
                }
                mx = max(mx, mn);
            }
            ans = min(ans, mx);
        }
        // fprintf(stderr, "------------\n");
        cout << ans << '\n';
    }
}
namespace solA{
    void main(){
        int len = n/2+1;
        int ans = max(len-k, 0)/4+1;
        if (ans==1&&len-k==3) ans = 2;
        else if (k==n) ans = 0;
        cout << ans << '\n';
    }
}
namespace k_is_2{
    int p, q, mx, from[N], zj[N], tot, val[N];
    bool on[N];
    struct seg{int l, r;}s[N];
    void dfs1(int x, int fa, int dis){
        if (dis>mx) mx = dis, p = x;
        for (int i:g[x])
            if (i!=fa)
                dfs1(i, x, dis+1);
    }
    void dfs2(int x, int dis){
        if (dis>mx) mx = dis, q = x;
        for (int i:g[x]) if (i!=from[x]){
            from[i] = x;
            dfs2(i, dis+1);
        }
    }
    int dfs3(int x, int fa){
        int res = 0;
        for (int i:g[x]) if (i!=fa&&!on[i]){
            res = max(res, dfs3(i, x)+1);
        }
        return res;
    }
    bool check(int d){
        for (int i=1;i<=tot;++i){
            if (d<val[i]) return 0;
            int l = max(1, i-(d-val[i])), r = min(tot, i+d-val[i]);
            s[i] = {l, r};
        }
        sort(s+1, s+1+tot, [&](const seg &x, const seg &y){
            return x.l<y.l;
        });
        int mnr = 0, cnt = 0;
        for (int i=1;i<=tot;++i){
            if (i==1||s[i].l>mnr) ++cnt, mnr = s[i].r;
            else mnr = min(mnr, s[i].r);
        }
        return cnt<=2;
    }
    void main(){
        if (n==2) return cout << 0 << '\n', void();
        p = q = mx = tot = 0;
        for (int i=1;i<=n;++i) on[i] = 0;
        dfs1(1, 0, 0), mx = from[p] = 0, dfs2(p, 0);
        while (q!=p){
            zj[++tot] = q, on[q] = 1;
            q = from[q];
        }
        zj[++tot] = p, on[p] = 1;
        for (int i=1;i<=tot;++i){
            val[i] = dfs3(zj[i], 0);
        }
        int l = 1, r = n, mid;
        while (l<r){
            mid = l+r>>1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int c, t; cin >> c >> t;
    while (t--){
        readin();
        if (n<=10) force::main();
        else if (c==13||c==14) solA::main();
        else if (k==2) k_is_2::main();
    }
    return 0;
}