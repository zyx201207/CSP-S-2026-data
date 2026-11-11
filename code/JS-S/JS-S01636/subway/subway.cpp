#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Pair pair<int,int>

int c, n, m, d, q, w[500005], t[505][500005], x[505][500005], dis[505][505];
bool vis[505];

map< int, vector< int > > mp;

int getrand() {
    return rand() % 10 + 1;
}

//si lu: Dijkstra bian zhong
//update: ou bu wo zhi dao le bu shi dan dian shi yi zheng tiao xian lu hai sheng xia 30 fen zhong

vector< pair< int, int > > a[505];
vector< int > haxi[500005];

void dijkstra(int s) {
    for(int i = 1 ; i <= m ; i++) {
        dis[s][i] = 1e11 + 5;
        vis[i] = 0;
    }
    dis[s][s] = 0;
    priority_queue < Pair, vector<Pair>, greater<Pair> > pq;
    pq.push({dis[s][s], s});
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(Pair aaa : a[u]) {
            int v = aaa.first, w = aaa.second;
            if(dis[s][u] + w < dis[s][v]) {
                dis[s][v] = dis[s][u] + w;
                pq.push({dis[s][v], v});
            }
        }
    }
}

signed main() {
    srand(time(0));
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1 ; i <= m ; i++) {
        cin >> w[i];
    }
    for(int i = 1 ; i <= n ; i++) {
        cin >> x[i][0];
        for(int j = 1 ; j <= x[i][0] ; j++) {
            cin >> x[i][j] >> t[i][j];
            haxi[x[i][j]].push_back(i);
            for(int l = 1 ; l <= m ; l++) {
                for(int k = 1 ; k < i ; k++) {
                    if(x[k][l] == x[i][j]) {
                        a[k].push_back({i, t[i][j] + t[k][l]});
                    }
                }
            }
        }
    }
    for(int i = 1 ; i <= m ; i++) dijkstra(i);
    while(q--) {
        int u, v;
        cin >> u >> v;
        int ans = 1e11 + 5;
        for(int i : haxi[u]) {
            for(int j : haxi[v]) {
                if(i == j) {
                    ans = 0;
                    break;
                }
            }
            if(ans == 0)
                break;
        }
        if(ans == 0) cout << w[u] + w[v] << endl;
        else {
            for(int i : haxi[u]) {
                for(int j : haxi[v]) {
                    ans = min(ans, dis[i][j] + w[u] + w[v]);
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
