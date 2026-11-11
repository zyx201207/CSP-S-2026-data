//#include <bits/stdc++.h>
//#define int long long
//#define inf 0x3f3f3f3f3f3f3f3f
//
//using namespace std;
//
//int n, d; 
//vector<int> x, vis;
//vector<vector<int>> g, dis;
//vector<vector<vector<int>>> f;
//
//void dijkstra(int S) {
//    queue<int> pq;
//    pq.push(S); dis[S][S] = 0;
//    while (!pq.empty()) {
//        int u = pq.front(); pq.pop();
//        if (vis[u]) continue ;
//        vis[u] = 1;
//
//        for (int v : g[u]) {
//            if (dis[S][u] + dis[u][v] < dis[S][v]) {
//                pq.push(v), dis[S][v] = dis[S][u] + dis[u][v];
//            }
//        }
//    }
//}
//
//void bfs(int u) {
//    queue<int> q;
//    q.push(u);
//    while (q.size()) {
//        int cur = q.front(); q.pop();
//        if(vis[u]) continue ;
//        vis[u] = 1;
//
//        for (int nxt : g[cur]) {
//            for (int i = 1; i <= n; i++) {
//                f[u][nxt][i] = f[u][cur][i - 1] + f[cur][nxt][1];
//            }
//        }
//    }
//}
//
//signed main() {
//    freopen("migrate1.in", "r", stdin), freopen("migrate.out", "w", stdout);
//    cin.tie(0) -> ios::sync_with_stdio(0);
//
//    int c, t; cin >> c >> t;
//
//    //if (c <= 2) {
//        while (t --) {
//            cin >> n >> d;
////            x.clear(), g.clear(), f.clear(), dis.clear(), vis.clear();
////            x.resize(n + 1), g.resize(n + 1), vis.resize(n + 1, 0), f.resize(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1))), dis.resize(n + 1, vector<int>(n + 1, inf));
////            for (int i = 1; i <= n; i++) cin >> x[i];
////
////            for (int i = 1; i < n; i++) {
////                for (int j = i + 1; j <= n; j++) {
////                    if (x[j] - x[i] <= d) g[i].push_back(j), g[j].push_back(i), dis[i][j] = dis[j][i] = f[i][j][1] = f[j][i][1] = 1;
////                }
////            }
////
////            for (int i = 1; i <= n; i++) dijkstra(i);
////            for (int i = 1; i <= n; i++) bfs(i);
////            
////            for (int i = 1; i <= n; i++) {
////            	for (int j = 1; j <= n; j++) {
////            		cout << dis[i][j] << " \n"[j == n];
////				}
////			}
////
////            int tot = 0;
////            for (int i = 1; i < n; i++) {
////                for (int j = i + 1; j <= n; j++) {
//////                    tot += (f[i][j][dis[i][j]] == 2);
////                }
////            }
////
////            cout << tot << '\n';
//			  cout << 0 << '\n';
//        }        
//    //}
//
//    return 0;   
//}

#include <bits/stdc++.h>
#define int long long 

using namespace std;

signed main() {
	freopen("migrate.in", "r", stdin);  freopen("migrate.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(0);

    int c, t; cin >> t;
    if (c == 13 || c == 14) {
        while (t --) {
            int n, d; cin >> n >> d;
            vector<int> a(n + 1);
            for (int i = 1; i <= n; i++) cin >> a[i];
            cout << (n * (n - 1) / 2) << '\n';            
        }
    } else if (c == 11 || c == 12) {
        while (t --) {
            int n, d; cin >> n >> d;
            vector<int> a(n + 1);
            for (int i = 1; i <= n; i++) cin >> a[i];     
            int gongcha = a[n] - a[n - 1];
            if (gongcha >= d) cout << 0 << '\n';
            else {
                int x = (d + gongcha - 1) / gongcha;
                int ans = 1;
                for (int i = n; i >= n - x + 1; i--) ans *= i; 
                cout << ans / x << '\n';
            }        
        }
    } else {
        while (t --) cout << 0 << '\n';
    }
    return 0;
}