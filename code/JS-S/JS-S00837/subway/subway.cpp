/*
   15:45 heihei, gangcai tiaoshi de shihou guolai kanti ba zheti miao le!!!
   16:09 aaaaa qi si wo le!!! zenme RE le!!!
   16:13 aaaaa zenme shi shouhua ba y dacheng x le, qi si wo le!!! all samples passed.
   16:15 bushi chutiren ni zao da yangli meiyou man de????? T1T2 doushi?????
   16:17 ei faxian yangli 6 bijiao man, xing.
   16:19 ooooo 200 le, qiang. nengbuneng bie guafen...
*/
#include <bits/stdc++.h>
using namespace std;

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

constexpr i64 INF = (i64)1 << 60;

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    
    i32 c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    vector<i64> w(m + 1);
    for(i32 i = 1; i <= m; i++) cin >> w[i];

    vector<vector<i64> > t(n + 1, vector<i64>(m + 1, 0)); // (Line, Station)
    vector<vector<i32> > lines(m + 1);
    for(i32 i = 1; i <= n; i++) {
        i32 k; cin >> k;
        while(k--) {
            i32 id; i64 tm;
            cin >> id >> tm;
            t[i][id] = tm;
            lines[id].push_back(i);
        }
    }

    vector<vector<i64> > dis(n + 1, vector<i64>(n + 1, INF));
    for(i32 i = 1; i <= n; i++) dis[i][i] = 0;
    for(i32 i = 1; i <= m; i++) {
        auto &line = lines[i];
        for(i32 x = 0; x < (i32)line.size(); x++) {
            for(i32 y = x + 1; y < (i32)line.size(); y++) {
                dis[line[x]][line[y]] = dis[line[y]][line[x]] = t[line[x]][i] + t[line[y]][i];
            }
        }
    }

    for(i32 k = 1; k <= n; k++) {
        for(i32 i = 1; i <= n; i++) {
            for(i32 j = 1; j <= n; j++) {
                if(dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[j][i] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    while(q--) {
        i32 x, y; cin >> x >> y;
        i64 ans = INF;
        auto &linex = lines[x];
        auto &liney = lines[y];
        for(i32 i = 0; i < (i32)linex.size(); i++) {
            for(i32 j = 0; j < (i32)liney.size(); j++) {
                ans = min(ans, dis[linex[i]][liney[j]] + t[linex[i]][x] + t[liney[j]][y]);
            }
        }
        cout << ans + w[x] + w[y] << '\n';
    }

    return 0;
}
