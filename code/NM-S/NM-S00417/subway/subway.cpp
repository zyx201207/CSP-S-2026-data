#include <bits/stdc++.h>
using namespace std;

const int NR = 501010;
vector<pair<int, int>> g[NR];// m : zhan , n : xian

int dis[NR], w[NR];
int c_, n, m, d, q;

void dijkstra(int _s){
    memset(dis, sizeof dis, 0x3f);
    dis[_s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> _q;
    _q.push({0, _s});

    while (_q.size()){
        auto [_d, x] = _q.top();
        _q.pop();
        if (_d > dis[x]) continue;
        for (auto [y, _w] : g[x]){
            if (dis[x] + _w >= dis[y]) continue;
            dis[y] = dis[x] + _w;
            _q.push({dis[y], y});
        }
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c_ >> n >> m >> d >> q;

    for (int i = 1; i <= m; i++){
        cin >> w[i];
    }

    int last = -1;
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++){
            int a, t;
            cin >> a >> t;
            g[a].push_back({m + i, t});
            g[m + i].push_back({a, t});
        }
    }

    for (int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        dijkstra(x);

        cout << dis[y] + w[x] + w[y] << '\n';
    }
}

// yo a ke ni i no ru ~