// subway

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

bool mbegin;

const int N = 2e6 + 10, M = 2e3 + 10, INF = 0x3f3f3f3f3f3f3f3f;
struct T {
    int to, w;
};
int gA[N], gDist[N], gF[M][M];
vector<PII> subway[N], fan[N];
vector<T> gVec[N];
bool gVis[N];

inline void AddEdge(int a, int b, int w) {
    gVec[a].push_back((T){b, w});
    gVec[b].push_back((T){a, w});
}

bool mend;

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m, d, q;
    cin >> n >> n >> m >> d >> q;

    for (int i = 1; i <= m; i++)
        cin >> gA[i];
    
    for (int i = 1; i <= n; i++) {
        int len;
        cin >> len;

        for (int j = 1, x = 0, y = 0; j <= len; j++)
            cin >> x >> y, AddEdge(i, x + n, y), subway[x].push_back(make_pair(i, y)), fan[i].push_back(make_pair(x, y));
    }

    memset(gF, 0x3f, sizeof(gF));
    for (int i = 1; i <= n; i++)
        gF[i][i] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (auto top : fan[i]) {
            int to = top.first, w = top.second;
            for (auto top2 : subway[to])
                if (top2.first != i) {
                    gF[i][top2.first] = min(gF[i][top2.first], w + top2.second);
                    gF[top2.first][i] = min(gF[top2.first][i], w + top2.second);
                }
        }
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                gF[i][j] = min(gF[i][j], gF[i][k] + gF[k][j]);

    // int lim = n + m;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= lim + 5; j++) gDist[j] = INF, gVis[j] = false; gDist[i] = 0;
    //     priority_queue<PII, vector<PII>, greater<PII> > pq;
    //     pq.push(make_pair(gDist[i], i));

    //     while (!pq.empty()) {
    //         PII top = pq.top();
    //         pq.pop();

    //         int u = top.second;
    //         if (gVis[u]) continue;
    //         gVis[u] = true;

    //         for (auto top : gVec[u]) {
    //             int to = top.to, w = top.w;
    //             if (gDist[to] > gDist[u] + w) {
    //                 gDist[to] = gDist[u] + w;
    //                 pq.push(make_pair(gDist[to], to));
    //             }
    //         }
    //     }

    //     for (int j = 1; j <= n; j++)
    //         gF[i][j] = gDist[j];
    // }

    while (q--) {
        int x, y;
        cin >> x >> y;

        int ans = INF;
        for (auto fgx : subway[x])
            for (auto lyx : subway[y])
                ans = min(ans, fgx.second + gF[fgx.first][lyx.first] + lyx.second);
        
        cout << ans + gA[x] + gA[y] << '\n';
    }

    cerr << abs(&mend - &mbegin) / 1048576.0 << " " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    return 0;
}