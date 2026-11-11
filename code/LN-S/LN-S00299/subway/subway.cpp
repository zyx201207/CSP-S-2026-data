#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
const int N = 4e6 + 10;
const int M = 1e5 + 5;
const int A = 1e6 + 5;
const int B = 2e6 + 5;
const int C = 3e6 + 5;

struct Edge {
    int v, w;
};
vector<Edge> arr[N];
vector<pair<int, int>> record;
int dist[N];
vector<pair<int, int>> have[M];
bool vis[N];


struct Point {
    int u, dist;
    bool operator< (const Point p) const {
        return dist > p.dist;
    }
};

void dijkstra(int start) {
    memset(vis, 0, sizeof(vis));
    memset(dist, 0x3f3f3f, sizeof(dist));
    priority_queue<Point> pq;
    pq.push({start, 0});
    dist[start] = 0;
    while (pq.size()) {
        int u = pq.top().u;
        pq.pop();
        if (vis[u]) continue;
        else vis[u] = true;
        for (auto i : arr[u]) {
            int pv = i.v, pw = i.w;
            if (dist[u] + pw < dist[pv]) {
                dist[pv] = dist[u] + pw;
                pq.push({pv, dist[pv]});
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        int time;
        cin >> time;
        arr[A + i].push_back({B + i, time});
        arr[B + i].push_back({A + i, time});
    }
    for (int i = 1; i <= n; i++) {
        int station, a, t;
        cin >> station >> a >> t;
        arr[B + a].push_back({C + a + i * 21, t});
        arr[C + a + i * 21].push_back({B + a, t});
        for (int j = 2; j <= station; j++) {
            int a1, t1;
            cin >> a1 >> t1;
            arr[a1 + C + i * 21].push_back({a + C + i * 21, 0});
            arr[a + C + i * 21].push_back({a1 + C + i * 21, 0});
            arr[B + a1].push_back({C + a1 + i * 21, t1});
            arr[C + a1 + i * 21].push_back({B + a1, t1});
            a = a1, t = t1;
        }
    }
    while (q--) {
        int start, finish;
        cin >> start >> finish;
        have[start].push_back({finish, 0});
        record.push_back({start, finish});
    }
    for (int i = 1; i <= m; i++) {
        if (have[i].size()) {
            dijkstra(i + A);
            if (have[i].size()) {
                for (int j = 0; j < have[i].size(); j++) {
                    have[i][j].second = dist[have[i][j].first + A];
                }
            }
        }
    }
    for (auto i : record) {
        for (auto j : have[i.first]) {
            if (j.first == i.second) {
                cout << j.second << '\n';
                break;
            }
        }
    }
    return 0;
}
