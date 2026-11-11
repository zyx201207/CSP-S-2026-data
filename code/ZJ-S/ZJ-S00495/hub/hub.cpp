#include <bits/stdc++.h>
using namespace std; bool _M_membg;
int c, t;
int n, k;
vector<int> e[1000010];
int N = 0;
namespace S1 {
    int ds[20][20];
    void dfs(int u, int fa, int *ds, int d){
        ds[u] = d;
        for (int v : e[u])if (v ^ fa)dfs(v, u, ds, d + 1);
    }
    int f[20];
    int fnd(int x){
        return x == f[x]? x : f[x] = fnd(f[x]);
    }
    void sol1(){
        vector<pair<int, int> > edg;
        for (int i = 1; i <= n; ++i)for (int j : e[i])if (i < j)edg.emplace_back(i, j);
        for (int i = 1; i <= n; ++i)dfs(i, 0, ds[i], 0);
        vector<int> hs;
        int rs = n + 1;
        for (int s = 0; s < 1 << n; ++s)if (__builtin_popcount(s) == k){
            hs.clear();
            bool is[20];
            for (int i = 1; i <= n; ++i)if ((is[i] = s >> i - 1 & 1))hs.emplace_back(i);
            iota(f + 1, f + n + 1, 1);
            for (auto &ee : edg){
                int u = ee.first, v = ee.second;
                if (is[u] && is[v])f[fnd(u)] = fnd(v);
            }
            int c = 0;
            for (int x : hs)if (f[x] == x)++c;
            if (c > 2)continue;
            int mxd = 0;
            for (int i = 1; i <= n; ++i)if (!is[i]){
                int mn = n + 1;
                for (int x : hs)mn = min(mn, ds[x][i]);
                mxd = max(mxd, mn);
            }
            rs = min(rs, mxd);
        }
        cout << rs << "\n";
    }
}
namespace SA {
    int m;
    bool chk(int L){ // [L... ] and [ ...m+1-L]
        int md = m + 1 - L - L - (k - 2);
        return md <= L - 1 + L - 1;
    }
    void solA(){
        assert(n & 1);
        m = n >> 1;
        if (k == n){
            cout << 0 << "\n";
            return;
        }
        int L = 1, R = n, rs = n + 1;
        while (L <= R){
            int M = L + R >> 1;
            if (chk(M))rs = M, R = M - 1;
            else L = M + 1;
        }
        cout << rs << "\n";
    }
}
void work(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)e[i].clear();
    for (int i = 1, u, v; i < n; ++i){
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    N += n;
    if ((1 <= c && c <= 3) || (N <= 30 && n <= 10))return S1::sol1();
    if ((13 <= c && c <= 14))return SA::solA();
}
bool _M_memed; int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    double _M_use_mem = fabs(&_M_membg - &_M_memed) / 1024 / 1024;
    clog << _M_use_mem << "M" << endl;
    assert(_M_use_mem <= 256);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while (t--)work();
    return 0;
}
/*
g++ hub.cpp -o hub -std=c++14 -O2 -static -pedantic
./hub <hub1.in >hub.out
diff hub.out hub1.ans -w
./hub <hub2.in >hub.out
diff hub.out hub2.ans -w
./hub <hub5.in >hub.out
diff hub.out hub5.ans -w
*/