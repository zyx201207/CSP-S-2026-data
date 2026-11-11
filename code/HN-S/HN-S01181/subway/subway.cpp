#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 10, INF = 1e9;
const int sub1_N = 10001;

struct edge{
    int v, w;
};

int sub, n, m, k, q, a[N];
vector<edge> adj[N], arr[N];

namespace subtask1{
    int ans;

    struct node{
        int x, id, dis;

        bool operator<(const node &i) const {
            return dis > i.dis;
        }
    };

    void bfs(int s, int id, int d, int t){
        priority_queue<node> q;
        q.push({s, id, d});
        while(!q.empty()){
            int x = q.top().x;
            int dis = q.top().dis;
            if(x == t){
                ans = min(ans, dis);
                return ;
            }
            for(auto e : adj[id]){
                q.push({e.v, id, dis + e.w});
            }
            for(auto e : arr[x]){
                q.push({x, e.v, dis + e.w});
            }
        }
    }

    void solve(){
        for(int i = 1, x, y; i <= q; i++){
            cin >> x >> y;
            ans = 0;
            for(auto e : arr[x]){
                bfs(x, e.v, e.w, y);
            }
            cout << ans << '\n';
        }
    }
}

namespace special_A{
    int ans;

    void dfs(int x, int y, int s, int t, int sum){
        if(y == t){
            ans = min(ans, sum);
            return;
        }
        if(sum >= ans) return ;
        dfs(x, adj[x][1].v, s, t, sum + adj[x][1].w);
        for(auto e : arr[y]){
            dfs(e.v, y, s, t, sum + e.w);
        }
    }

    void solve(){
        for(int i = 1, x, y; i <= q; i++){
            ans = INF;
            cin >> x >> y;
            for(auto e : arr[x]){
                dfs(e.v, x, x, y, e.w);
            }
            cout << ans;
        }
    }
}

namespace special_B{
    int dist[N];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> sub >> m >> n >> k >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1, x; i <= m; i++){
        cin >> x;
        for(int j = 1, u, v; j <= x; j++){
            cin >> u >> v;
            adj[i].push_back({u, v});
            arr[u].push_back({i, v});
        }
    }
    if(sub <= 3){
        subtask1::solve();
    } else if(sub >= 7 && sub <= 11){
        special_A::solve();
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
