#include <bits/stdc++.h>
using namespace std;
vector<int> w;
int c, n, m, d, q;

struct Node {
    int u, v, ty;
};

int arr[505][505];
int typ[505];

// struct Edge{
//     int dis, u;

//     bool operator<(const Edge o) const{
//         return dis > o.dis;
//     }
// };

vector<Node> g[100005];
//priority_queue<Edge> pq;
bool st[100005];
//int dis[100005];

// int f(int p1, int p2) {

// }

// int dijkstra(int s, int e) {
//     memset(st, false, sizeof st);
//     memset(dis, 0x3f, sizeof dis);

//     if (!pq.empty()) {
//         pq.pop();
//     }

//     pq.push({0, 0});

//     while (pq.size()) {
//         int u = pq.top().u;
//         pq.pop();

//         if (st[u]) {
//             continue;
//         }
//         st[u] = true;

//         for (auto i : g[u]) {
//             if (dis[u] > dis[i.u] + f(i.u, u)) {

//             }
//         }
//     }

// }

int mn = INT_MAX;

void dfs(int n, int e, int tim, int lasttp) {
    if (n == e) {
        mn = min(tim, mn);
        return ;
    }

    for (auto i : g[n]) {
        if (st[i.u]) {
            continue;
        }
        st[i.u] = true;
        int need = arr[n][i.ty];
        if (lasttp != -1) {
            need += arr[n][lasttp];
        }
        dfs(i.u, e, tim + need, i.ty);
        st[i.u] = false;
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(arr, 0x3f, sizeof arr);

    
    cin >> c >> n >> m >> d >> q;

    w.resize(m + 5);

    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }


    

    for (int i = 1; i <= n; i++) {
        int last = 0;
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int a, t;
            cin >> a >> t;
            if (j == 1) {
                last = a;
            } else {
                g[last].push_back({a, 0, i});
                g[a].push_back({last, 0, i});
            }

            arr[a][j] = t;
            //  ^
        }
    }

    

    for (int i = 1; i <= q; i++) {
        int s, e;
        cin >> s >> e;
        mn = INT_MAX;
        dfs(s, e, 0, -1);
        cout << mn + w[s] + w[e] << '\n';
    }

    
    return 0;
}

/*

g++ subway.cpp -o subway -g -O2 -Wall 
./subway

*/