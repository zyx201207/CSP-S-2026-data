#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int cards[MAXN], cnt[MAXN];
vector<int> records[MAXN];
int main() {
#ifndef PDEBUG
    auto _1 = freopen("card.in", "r", stdin);
    auto _2 = freopen("card.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> cards[i], records[cards[i]].push_back(i);
    for (int k = 1; k <= n; ++k) for (int i = k; i <= n;) {
        int var = 0;
        for (int j = 0; j < records[cards[i]].size(); ++j) {
            if (records[cards[i]][j] == i) {
                var = records[cards[i]][j + 1];
            }
        }
        if (var != 0) i = var;
        else ++cnt[cards[i]], ++i;
    }

    for (int i = 1; i <= m; ++i) cout << cnt[i] << ' ';
}

// 10 3
// 3 1 2 1 3 2 3 1 2 1