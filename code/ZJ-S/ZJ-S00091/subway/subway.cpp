#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 505, M = 5e5 + 5;
int c, n, m, d, q;
int p[M];
LL cost[M];
LL w[M], dis[M];
bool vis[M];

struct Edge {
    int to;
    LL val;
};

vector <Edge> G[M];

struct dot {
    int id;
    LL dist;
};

bool operator<(dot a, dot b) {
    return a.dist > b. dist;
}

priority_queue <dot> Q;

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
        cin >> w[i];
    for(int i = 1; i <= n; i++) {
        int k; cin >> k;
        for(int j = 1; j <= k; j++) {
            cin >> p[j] >> cost[j]; 
        }
        for(int j= 1; j <= k; j++) {
            for(int c = j + 1; c <= k; c++) {
                G[p[j]].push_back({p[c], cost[j] + cost[c] + w[p[j]] + w[p[c]]});
                G[p[c]].push_back({p[j], cost[j] + cost[c] + w[p[j]] + w[p[c]]});
            }
        }
    }
    while(q--) {
        int x, y; 
        cin >> x >> y;
        for(int i = 1; i <= n; i++)
            dis[i] = LONG_LONG_MAX;
        for(int i = 1; i <= n; i++)
            vis[i] = 0;
        dis[x] = 0;
        // cout << Q.empty() << endl;
        Q.push({x, 0});
        while(!Q.empty()) {
            auto x = Q.top();
            Q.pop();
            // cout << x.id << " " << x.dist << endl;
            if(vis[x.id]) continue;
            vis[x.id] = 1;
            for(auto y : G[x.id]) {
                if(x.dist + y.val <= dis[y.to]) {
                    dis[y.to] = x.dist + y.val;
                    Q.push({y.to, dis[y.to]});
                }
            }
            // for(int i = 1; i <= m; i++)
                // cout << dis[i] << " ";
            // cout << endl;
        }
        cout << dis[y] << endl;
    }
}
// 这和不可以总司令没有什么区别