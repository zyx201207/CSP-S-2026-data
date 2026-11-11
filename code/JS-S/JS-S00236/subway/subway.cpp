#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
using namespace std;
vector<pii> nb[505]; //to,dis
int ans[505];
priority_queue<pii, vector<pii>, greater<pii>> qq; //dis,n
int frk[500005];
vector<pii> xl[500005];
//vector<pii> dtz[505];
int quicker[505][505];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(quicker, -1, sizeof(quicker));
    int c, n, m, d, q, k, l1, lass, ti;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> frk[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> l1 >> ti;
            xl[l1].pb({i, ti});
            //dtz[i].pb({l1, ti});
        }
    }
    for (int i = 1; i < m; i++) {
        for (auto j : xl[i]) {
            for (auto k : xl[i]) {
                if (j.first == k.first) continue;
                nb[j.first].pb({k.first, j.second + k.second});
            }
        }
    }
    while (q--) {
        int xx, yy, nowp, minn = 0x3fffffffffffffff;
        cin >> xx >> yy;
        for (auto x : xl[xx]) {
            for (auto y : xl[yy]) {
                if (quicker[x.first][y.first] != -1) {
                    minn = min(minn, quicker[x.first][y.first] + x.second + y.second);
                    continue;
                }
                memset(ans, 0x3f, sizeof(ans));
                ans[x.first] = 0;
                while (qq.size()) {
                    qq.pop();
                }
                qq.push({0, x.first});
                while (qq.size()) {
                    nowp = qq.top().second;
                    if (qq.top().first > ans[nowp]) {
                        qq.pop();
                        continue;
                    }
                    qq.pop();
                    if (nowp == y.first) {
                        quicker[x.first][y.first] = ans[nowp];
                        quicker[y.first][x.first] = ans[nowp];
                        minn = min(minn, x.second + y.second + ans[nowp]);
                        break;
                    }
                    for (auto i : nb[nowp]) {
                        if (ans[i.first] > ans[nowp] + i.second) {
                            ans[i.first] = ans[nowp] + i.second;
                            qq.push({ans[i.first], i.first});
                        }
                    }
                }
            }
        }
        cout << minn + frk[xx] + frk[yy] << endl;
    }
    return 0;
} //OHHHHHHHHH! It's a bit(lot) slow, but it passed!!!!!
  //If I know floyd,I can do it better.
  //But I don't.