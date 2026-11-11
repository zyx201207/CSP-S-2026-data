#include <bits/stdc++.h>
using namespace std;

const int M = 5e5+5;
const int N = 500;


int c, n, m, d, q, ans;
int w[M], k[M], a[N][M], t[N][M], x[M], y[M], dis[M];

vector<int> e[M];

//void dijkstra(int s) {
//    queue<pair<int, int>> q;
//    q.push({s, 0});
//    dis[s] = 0;
//    while (!q.empty()) {
//        int head = q.front();
//        q.pop();
//        for (int i = 0; i < e[head].size(); i++) {
//            int v = e[head][i];
//            if (dis[e] + 1 < dis[v]) {
//                e[head][i] = v;
//                q.push({v, dis[v]})
//            }
//        }
//    }
//}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
        }
    }
    for (int i = 1; i <= q; i++){
        cin >> x[i] >> y[i];
        ans = 0;
        ans += w[x[i]] + w[y[i]];
        cout << ans << endl;
    }

    return 0;
}
