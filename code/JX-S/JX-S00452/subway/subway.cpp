#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int N = 510;
const int M = 5e3 + 10;
const int D = 21;
const int Q = 1e5 + 10;
const ll inf = 2e18;
int c, n, m, d, q;
int w[M], k[N];
vector<pair<int, int>> sta[N];
vector<pair<int, int>> e[M];
int wz[M][N];
bool vis[M][N];
ll dis[M][N];
struct node{
    int u, l;
    bool operator <(const node& other) const{
        return u < other.u;
    }
};
void dij(int st){
    priority_queue<pair<ll, node>> q;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            dis[i][j] = inf;
            vis[i][j] = false;
        }
    }
    for(auto p : e[st]){
        int l = p.fi, v = p.se;
        dis[st][l] = w[st] + 2 * v;
        q.push({-dis[st][l], {st, l}});
    }
    while(q.size()){
        int u = q.top().se.u, l = q.top().se.l;
        q.pop();
        vis[u][l] = true;
        if(wz[u][l] != k[l]){
            int v = sta[l][wz[u][l] + 1].fi, w2 = sta[l][wz[u][l] + 1].se;
            int w1 = sta[l][wz[u][l]].se;
            if(!vis[v][l] && dis[v][l] > dis[u][l] - w1 + w2){
                dis[v][l] = dis[u][l] - w1 + w2;
                q.push({-dis[v][l], {v, l}});
            }
        }
        if(wz[u][l] != 1){
            int v = sta[l][wz[u][l] - 1].fi, w = sta[l][wz[u][l] - 1].se;
            int w1 = sta[l][wz[u][l]].se;
            if(!vis[v][l] && dis[v][l] > dis[u][l] - w1 + w){
                dis[v][l] = dis[u][l] - w1 + w;
                q.push({-dis[v][l], {v, l}});
            }
        }
        for(auto p : e[u]){
            int nxtl = p.first, w = p.second;
            if(l == nxtl) continue;
            int w1 = sta[l][wz[u][l]].se;
            //if(!vis[u][nxtl] && dis[u][nxtl] > dis[u][l] + w){
                //dis[u][nxtl] = dis[u][l] + w;
                //q.push({-dis[u][nxtl], {u, nxtl}});
            //}
            if(!vis[u][nxtl] && dis[u][nxtl] > dis[u][l] + 2 * w){
                dis[u][nxtl] = dis[u][l] + 2 * w;
                q.push({-dis[u][nxtl], {u, nxtl}});
            }
        }
    }
}
void print(){
    for(int i = 1; i <= m; i++){
        cout << i << '\n';
        for(int j = 1; j <= n; j++){
            cout << j << ' ' << (dis[i][j] == inf ? -1 : dis[i][j]) << '\n';
        }
        cout << '\n';
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        cin >> k[i];
        sta[i].resize(k[i] + 1);
        for(int j = 1, a, t; j <= k[i]; j++){
            cin >> a >> t;
            sta[i][j] = make_pair(a, t);
            e[a].push_back({i, t});
            wz[a][i] = j;
        }
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        dij(x);
        //print();
        ll ans = 2e18;
        for(auto p : e[y]){
            int l = p.first;
            ans = min(ans, dis[y][l]);
        }
        cout << ans + w[y] << '\n';
    }
    return 0;
}
// kai long long

