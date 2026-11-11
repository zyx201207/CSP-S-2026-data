#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL Maxn = 2e6 + 5;

LL X[Maxn];
vector<LL> Grid[Maxn];

queue<LL> Que;
bool Vis[Maxn];
LL Mind[Maxn];
LL Min_cnt[Maxn];

void init(LL v_n) {
    for (LL i = 0; i <= v_n; ++i)  Grid[i].clear();
    return;
}

void ini_bfs(LL v_n) {
    while (!Que.empty())  Que.pop();
    for (LL i = 0; i <= v_n; ++i) {
        Vis[i] = false;
        Mind[i] = 0;
        Min_cnt[i] = 0;
    }
    return;
}

LL bfs(LL s, LL v_n) {
    ini_bfs(v_n);
    Que.push(s);
    Vis[s] = true;
    Mind[s] = 0;
    Min_cnt[s] = 1;

    LL cur = 0;
    while (!Que.empty()) {
        cur = Que.front(); Que.pop();

        for (auto v : Grid[cur]) {
            if (Vis[v] == false) {
                Mind[v] = Mind[cur] + 1;
                Min_cnt[v] += Min_cnt[cur];
                Que.push(v);
                Vis[v] = true;
            } else {
                if (Mind[cur] + 1 == Mind[v])  Min_cnt[v] += Min_cnt[cur];
            }
        }
    }

    LL cnt = 0;
    for (LL i = 1; i <= v_n; ++i) {
        if (Min_cnt[i] == 2)  ++cnt;
    }

    return cnt;
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL c, t;
    cin >> c >> t;
    LL v_n, d;
    LL res = 0;
    while (t--) {
        cin >> v_n >> d;
        init(v_n);
        for (LL i = 1; i <= v_n; ++i) {
            cin >> X[i];
        }

        for (LL i = 1; i <= v_n; ++i) {
            for (LL j = i + 1; j <= v_n; ++j) {
                if (X[j] - X[i] > d)  break;
                Grid[i].emplace_back(j);
            }
        }

        res = 0;
        for (LL i = 1; i <= v_n; ++i) {
            res += bfs(i, v_n);
        }

        cout << res << '\n';
    }

    return 0;
}
