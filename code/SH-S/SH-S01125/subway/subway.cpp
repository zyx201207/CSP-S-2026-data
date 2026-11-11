#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;

struct Node {
    int v, w;
};

struct BNode {
    int u, step;
};

struct DNode {
    int u, dist;
    friend bool operator<(DNode a, DNode b) {
        return a.dist > b.dist;
    }
};

const int N = 5e5 + 600;
const int M = 510;
// nm互换 : n - 地铁站数
//          m - 地铁线路数
int gunmu, m, n, gunmu2, taskcnt;
int wa[N];
int b[N];
int t[N];
int dist[N];
bool vis[N];
vector<Node> a[N];
priority_queue<DNode> q;

void dij(int s) {
    int nn = n + m;
    for (int i = 1; i <= nn; i++) {
        dist[i] = 1e18;
        vis[i] = 0;
    }
    dist[s] = 0;
    q.push({s, 0});
    while (!q.empty()) {
        int u = q.top().u;
        q.pop();

        for (Node& node : a[u]) {
            int v = node.v;
            int w = node.w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push({v, dist[v]});
                }
            }
        }
    }
}

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    
    cin >> gunmu >> m >> n >> gunmu2 >> taskcnt;
    for (int i = 1; i <= n; i++) {
        cin >> wa[i];
    }
    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> b[j] >> t[j];
        }

        for (int j = 1; j <= k; j++) {
            a[n + i].push_back({b[j], t[j]});
            a[b[j]].push_back({n + i, t[j]});
        }
    }

    while (taskcnt--) {
        int x, y;
        cin >> x >> y;
        dij(x);
        cout << dist[y] + wa[x] + wa[y] << '\n';
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 5 4 5
3 2 5 3 5 5 5
1 3
1 2

dij : nq log n
spfa : n2q
floyd : n3

边数5e5
点5e5
*/