#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e6 + 5;
const int P = 1e9 + 7;
int c, n, m, d, q;
struct to{
    int v, w;
    bool operator < (const to &p) const {
        return w > p.w;
    }
};
struct node{
    int x, y, q;
    bool operator < (const node &p) const {
        return x < p.x;
    }
};
int a[N], dis[N], ans[N], we[N], di[3][N];
node b[N];
bool ex[N];
vector <to> G[N];
void dij(int s){
    fill(dis + 1, dis + n + m + 1, P);
    fill(ex + 1, ex + n + m + 1, 0);
    priority_queue <to> q;
    q.push({s, 0});
    dis[s] = 0;
    ex[s] = 1;
    while(!q.empty()){
        to u = q.top();
        q.pop();
        for(auto v : G[u.v]){
            if(!ex[v.v]) q.push(v), ex[v.v] = 1;
            dis[v.v] = min(dis[u.v] + v.w, dis[v.v]);
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> a[i];
    if(n <= 2){
        if(n == 1){
            int x;
            cin >> x;
            for(int i = 1; i <= x; i++){
                int u, w;
                cin >> u >> w;
                we[u] = w;
            }
            for(int i = 1; i <= q; i++){
                int x, y;
                cin >> x >> y;
                cout << a[x] + a[y] + we[x] + we[y] << endl;
            }
            return 0;
        }
        for(int i = 1; i <= 2; i++){
            int x;
            cin >> x;
            for(int j = 1; j <= x; j++){
                int u, w;
                cin >> u >> w;
                di[i][u] = w;
            }
        }
        int c = P;
        for(int i = 1; i <= m; i++){
            if(!di[1][i] && !di[2][i]) c = min(di[1][i] + di[2][i], c);
        }
        for(int i = 1; i <= q; i++){
            int x, y;
            cin >> x >> y;
            int res = P;
            if(!di[1][x] && !di[1][y]) res = min(res, di[1][x] + di[1][y]);
            if(!di[1][x] && !di[2][y]) res = min(res, di[1][x] + di[2][y] + c);
            if(!di[2][x] && !di[1][y]) res = min(res, di[2][x] + di[1][y] + c);
            if(!di[2][x] && !di[2][y]) res = min(res, di[2][x] + di[2][y]);
            cout << res + a[x] + a[y] << endl;
        }
        return 0;
    }
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        for(int j = 1; j <= x; j++){
            int u, w;
            cin >> u >> w;
            G[u].push_back({i + m, w});
            G[i + m].push_back({u, w});
        }
    }
    for(int i = 1; i <= q; i++) cin >> b[i].x >> b[i].y, b[i].q = i;
    sort(b + 1, b + q + 1);
    for(int i = 1; i <= q; i++){
        if(b[i].x != b[i - 1].x) dij(b[i].x);
        ans[b[i].q] = a[b[i].x] + a[b[i].y] + dis[b[i].y];
    }
    for(int i = 1; i <= q; i++) cout << ans[i] << endl;
    return 0;
}
