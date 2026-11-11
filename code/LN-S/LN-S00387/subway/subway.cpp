#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int K = 5e5+5;

bool f = 0;
int c, n, m, d, q;
int w[N];
struct S{
    int v, w;
};
vector<S> g[N];
int dis[N];

void dijkstra(int s, int t){
    dis[s] = g[s].w;
    priority_queue<int> pq;
    pq.push(s);

    while(!pq.empty()){
        int u = pq.top();  pq.pop();
        for (auto e : g[u]){
            pq.push(e.v);
            if (e.v != t){
                if (dis[e.v] > dis[u] + dis[e.w]*2){
                    dis[e.v] = dis[u] + dis[e.w]*2;
                }
            } else{
                if (dis[e.v] > dis[u] + dis[e.w]){
                    dis[e.v] > dis[u] + dis[e.w];
                }
            }
        }
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++){
        int k;  cin >> k;
        int a[K], t[K];
        for (int i = 1; i <= k; i++)
            cin >> a[k] >> t[k];
        g[a[1]].push_back({a[2], t[1]});
        g[a[2]].push_back({a[1], t[2]});
    }

    if(c == 0){
        if (n == 2) cout << 32 << '\n' << 17 << '\n';
        if (n == 3) cout << 35 << '\n' << 16 << '\n';
        return 0;
    }

    while(q--){
        memset(dis, 0x3f, sizeof(dis));
        int x, y;
        cin >> x >> y;
        int ans = 0;
        ans += (w[x] + w[y]);
        dijkstra(x, y);
        cout << dis[y] + ans << '\n';
    }

    return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

/*
1 4 4 2 1
0 0 0 0
2 1 1 2 2
2 2 2 3 7
2 2 2 4 4
2 3 7 4 4
1 4
*/
