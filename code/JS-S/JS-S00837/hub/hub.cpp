/*
   17:43 shang le ge cesuo huilai le. xianzai de xianfa shi ruhe ba shu fen cheng san fen.
   17:45 fencheng san fen keyi qinding liang ge fengedian, dian zhongjian de bufen zhijie yilun pao yixia, waimian de bufen erfen yi ge zui xiao de shendu, ranhou shushang zuo yixia, zheyang jiushi n^3\log n de, ranhou pin yige k=2 de bufen jiu keyi huode 45 fen.
   17:49 zenme yangli jieshi tiantian zha hhh.
*/
#include <bits/stdc++.h>
using namespace std;

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

void solve() {
    i32 n, k;
    cin >> n >> k;
    vector<vector<i32> > g(n + 1);
    for(i32 i = 1; i < n; i++) {
        i32 u, v;
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    vector<i32> disa(n + 1), disb(n + 1), depa(n + 1), depb(n + 1);
    i32 ans = n;
    for(i32 x = 1; x <= n; x++) {
        for(i32 y = x + 1; y <= n; y++) {
            fill(disa.begin(), disa.end(), 1);
            fill(disb.begin(), disb.end(), 1);
            fill(depa.begin(), depa.end(), 0);
            fill(depb.begin(), depb.end(), 0);
            function<void(i32, i32)> dfsa = [&](i32 u, i32 fa) {
                for(auto v : g[u]) {
                    if(v == y) continue;
                    if(v == fa) continue;
                    depa[v] = depa[u] + 1;
                    dfsa(v, u);
                    disa[u] = max(disa[u], disa[v] + 1);
                }
            };
            disa[x] = 0;
            dfsa(x, 0);
            function<void(i32, i32)> dfsb = [&](i32 u, i32 fa) {
                for(auto v : g[u]) {
                    if(v == x) continue;
                    if(v == fa) continue;
                    depb[v] = depb[u] + 1;
                    dfsb(v, u);
                    disb[u] = max(disb[u], disb[v] + 1);
                }
            };
            disb[y] = 0;
            dfsb(y, 0);
            vector<i32> outs;
            i32 res = 0;
            for(i32 i = 1; i <= n; i++) {
                // cerr << i << ' ' << depa[i] << ' ' << depb[i] << ' ' << disa[i] << ' ' << disb[i] << '\n';
                if(depa[i] == 0 || depb[i] == 0)
                    if(i != x && i != y) outs.push_back(max(disa[i], disb[i]));
                else res = max(res, min(depa[i], depb[i]));
            }
            sort(outs.begin(), outs.end(), greater<i32>());
            if((i32)outs.size() > k - 2) res = max(res, outs[k - 2]);
            ans = min(ans, res);
            // cerr << "!!!!  " << x << ' ' << y << ' ' << res << '\n';
        }
    }
    cout << ans << '\n';
    // clog << '\n';
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    
    i32 c, t; cin >> c >> t;
    while(t--) solve();

    return 0;
}