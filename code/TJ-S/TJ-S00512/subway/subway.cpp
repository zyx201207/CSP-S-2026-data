#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1000;
int c, m, n, d, q;
int w[N];
struct Edge {
    int v, t;
};
vector <Edge> G[N];
struct Node {
    int id, dis;
    bool operator <(const Node &u) const {
        return dis > u.dis;
    }
};
long long done[N], dis[N];

void dijkastra(int s, int e) {
    priority_queue <Node> q;
    for(int i = 1; i <= m + n + 10; i++) {
        dis[i] = INT_MAX - 1;
        //cout << dis[i] << endl;
        done[i] = 0;
    }
    dis[s] = 0;
    q.push({s, 0});
    while(!q.empty()) {
        Node u = q.top();
        q.pop();
        if(done[u.id]) continue;
        done[u.id] = 1;
        for(int i = 0; i < G[u.id].size(); i++) {
            int k = G[u.id][i].v;
            if(dis[u.id] + G[u.id][i].t < dis[k]) {
                dis[k] = dis[u.id] + G[u.id][i].t;
                q.push({k, dis[k]});
            }
        }
    }
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
        scanf("%d", &w[i]);
	}
	for(int i = 1; i <= n; i++) {
        int k = 0;
        scanf("%d", &k);
        for(int j = 1; j <= k; j++) {
            int x, c;
            scanf("%d%d", &x, &c);
            G[m + i].push_back({x, c});
            G[x].push_back({m + i, c});
        }
	}
	for(int i = 1; i <= q; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        dijkastra(x, y);
        printf("%d\n", dis[y] + w[x] + w[y]);
	}
	return 0;
}
