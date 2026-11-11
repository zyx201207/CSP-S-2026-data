#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

struct Edge {
    int to;
    ll w;
};

struct Query {
    int id, x, y;
    bool operator < (const Query &other) const {
        return x < other.x;
    }
};

vector<vector<Edge>> g;
vector<ll> w, dis;
vector<Query> ques;
vector<int> cnt;
vector<ll> ans;

void dijkstra(int s, int n) {
    dis.assign(n + 1, 4e18);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dis[s] = 0;
    pq.emplace(dis[s], s);

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d != dis[u]) continue;

        for (const Edge &e : g[u]) {
            if (dis[e.to] > d + e.w) {
                dis[e.to] = d + e.w;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;

    g.resize(m + n + 1);
    w.resize(m + 1);
    cnt.resize(m + 1);
    ans.resize(q);
    ques.resize(q);

    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int a, t;
            cin >> a >> t;
            g[a].push_back({m + i, t});
            g[m + i].push_back({a, t});
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> ques[i].x >> ques[i].y;
        ques[i].id = i;
        cnt[ques[i].x]++;
        cnt[ques[i].y]++;
    }

    for (auto &qu : ques) {
        if (cnt[qu.x] < cnt[qu.y]) {
            swap(qu.x, qu.y);
        }
    }
    sort(ques.begin(), ques.end());

    int cur = 0;
    for (auto &qu : ques) {
        if (qu.x != cur) {
            cur = qu.x;
            dijkstra(cur, m + n);
        }
        ans[qu.id] = dis[qu.y] + w[qu.x] + w[qu.y];
    }

    for (auto &i : ans) {
        cout << i << "\n";
    }

    return 0;
}