#include<bits/stdc++.h>
#define rep(i, r) for(int i = 1; i <= r; i++)
#define Rep(i, l, r) for(int i = l; i <= r; i++)
#define lep(i, r) for(int i = r; i; i--)
#define Lep(i, l, r) for(int i = r; i >= l; i--)
using namespace std;
const int N = 2e6 + 5, M = 15;
int c, T, n, k, d[M], cnt, dd[N], f[N];
vector<int> e[N];
int count(int x) {
    int res=0;
    while(x) res++, x-=x&-x;
    return res;
}
void dfs(int x, int fa, int dep) {
    for(int y:e[x]) if(y != fa) d[y] = min(d[y], dep+1), dfs(y, x, dep+1);
}
void dfs1(int x, int fa, bool lst) {
    if(!lst && !d[x]) cnt++;
    for(int y : e[x]) if(y != fa) dfs1(y, x, !d[x]);
}
void solve1() {
    int ans= 1e9;
    rep(i, (1 << n) - 1) {
        if(count(i) != k) continue;
        memset(d, 0x3f, sizeof d);
        rep(j, n) if((i >> j - 1) & 1) d[j]=0, dfs(j, 0, 0);
        cnt=0;
        dfs1(1,0,0);
        if(cnt>2) continue;
        int res = 0;
        rep(j, n) res = max(res, d[j]);
        ans = min(ans, res);
    }
    cout << ans << '\n';
}
void solve2() {
    if(n == k) return cout << "0\n", void();
    int m = n / 2;
    if(k >= m) return cout << "1\n", void();
    rep(i, n) {
        int t = m - k - 2 * i + 2, y;
        if(t & 1) y = t / 2 + 2;
        else y = t / 2 + 1;

        if(y <= i) return cout << i << '\n', void();
    }
}
void dfs3(int x, int fa) {
    dd[x] = dd[fa] + 1;
    f[x]=dd[x];
    for(int y:e[x])if(y!=fa)dfs3(y,x),f[x]=max(f[x],dd[y]);
}
int s[N], mn[N], top;
void dfs4(int x, int fa, int l) {
    int maxx = 0, lmx = 0, cnt = 0;
    for(int y:e[x])if(y!=fa) {
        if(maxx<dd[y]) maxx=dd[y], cnt=1;
        else if(maxx==dd[y]) cnt++;
    }
    for(int y:e[x])if(y!=fa){
        if(cnt>1 || maxx != dd[y]) {
            
        } else {
            s[++top] = maxx;

        }
    }
    top--;
}
void solve3() {
    dd[0] = -1;
    rep(i, n) {
        dd[i] = 0;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> T;
    while(T--) {
        cin >> n >> k;
        rep(i, n) e[i].clear(), e[i].shrink_to_fit();
        rep(i, n - 1) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v), e[v].push_back(u);
        }
        if(c <= 3) solve1();
        if(c==13||c==14) solve2();
        if(c==7) solve3();
    }
    return 0;
}
