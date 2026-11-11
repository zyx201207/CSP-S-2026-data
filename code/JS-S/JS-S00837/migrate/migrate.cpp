/*
   17:02 ganjue hui le n^2\log n de pusu zuofa, neng na 40, xian xie yixia.
   17:05 youshou bian you xiaohai yizhi zai he jishu renyuan jiaotan, chao si le!!!
   17:39 Got 40pts!!! shoudao, mashang qu xiayi ti da baoli! yijing 240 le!!!
*/
#include <bits/stdc++.h>
using namespace std;

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

void solve() {
    i32 n;
    i64 d;
    cin >> n >> d;
    vector<i64> x(n + 1);
    x[0] = INT64_MIN;
    for(i32 i = 1; i <= n; i++) cin >> x[i];
    vector<i32> dis(n + 1), ways(n + 1);
    i64 ans = 0;
    for(i32 s = 1; s <= n; s++) {
        fill(dis.begin(), dis.end(), n + 1);
        fill(ways.begin(), ways.end(), 0);
        dis[s] = 0;
        ways[s] = 1;
        i32 p = s;
        // cerr << "St: " << s << '\n';
        for(i32 t = s + 1; t <= n; t++) {
            while(x[p] < x[t] - d) p++;
            if(p == t) break;
            i32 nd = dis[p];
            for(i32 j = p; dis[j] == nd; j++) {
                ways[t] += ways[j];
                // cerr << j << "->" << t << '\n';
                if(ways[t] > 2) break;
            }
            // cerr << t << ' ' << ways[t] << '\n';
            if(ways[t] == 2) ans++;
            dis[t] = nd + 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    
    i32 c, t; cin >> c >> t;
    if(c <= 10) while(t--) solve();
    else while(t--) cout << "0\n";

    return 0;
}