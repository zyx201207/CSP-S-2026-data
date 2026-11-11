#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2000010;

int n;
LL range, x[N];

namespace S1 {
    const int NN = 5010, MM = 50000010;

    bool st[NN];
    int h[NN], e[MM], ne[MM], idx, d[NN], cnt[NN];
    priority_queue<PII, vector<PII>, greater<PII>> pq;

    void Add(int x, int y) {
        e[idx] = y, ne[idx] = h[x], h[x] = idx++;
    }

    void Dijkstra(int bg) {
        memset(d, 0x3f, sizeof(d));
        memset(st, 0, sizeof(st));
        memset(cnt, 0, sizeof(cnt));
        pq.push({ 0, bg });
        d[bg] = 0, cnt[bg] = 1;
        while (!pq.empty()) {
            auto [dist, pos] = pq.top(); pq.pop();
            if (st[pos]) continue;
            st[pos] = true;
            for (int i = h[pos]; i != -1; i = ne[i]) {
                int v = e[i];
                if (d[v] > d[pos] + 1) {
                    d[v] = d[pos] + 1;
                    pq.push({ d[v], v });
                    cnt[v] = cnt[pos];
                } else if (d[v] == d[pos] + 1) cnt[v] += cnt[pos];
            }
        }
    }

    void Solve() {
        memset(h, -1, sizeof(h));
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (abs(x[i] - x[j]) <= range) {
                    Add(i, j), Add(j, i);
                    // cout << i << ' ' << j << endl;
                }
            }
        }
        // puts("");
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            Dijkstra(i);
            // printf("i: %d\n", i);
            // for (int j = 1; j <= n; ++j) printf("%d%c", cnt[j], " \n"[j == n]);
            for (int j = i + 1; j <= n; ++j) {
                if (cnt[j] == 2) {
                    ++ans;
                    // cout << i << ' ' << j << endl;
                }
            }
        }

        printf("%d\n", ans);
    }
};

void Solve() {
    scanf("%d%lld", &n, &range);
    for (int i = 1; i <= n; ++i) scanf("%lld", &x[i]);

    S1::Solve();
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, t;
    scanf("%d%d", &c, &t);
    while (t--) {
        Solve();
    }

    return 0;
}
// rp++
// jbw tql ORZ
