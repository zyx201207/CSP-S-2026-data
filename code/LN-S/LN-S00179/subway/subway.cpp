#include <bits/stdc++.h>
using namespace std;

template <typename T> bool ckmx(T &x, T y){return (x < y) ? (x = y, 1) : 0;}
template <typename T> bool ckmn(T &x, T y){return (x > y) ? (x = y, 1) : 0;}
typedef long long ll;

const int N = 505, M = 5e5 + 5;

int c, n, m, d, q;
ll w[M];
vector<pair<int, ll> > route[M];
ll dis[N][N];
vector<pair<int, ll> > a[N];
int k[N];

void solve(){
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++){
            int v;
            ll t;
            cin >> v >> t;
            a[i].push_back({v, t});
            route[v].push_back({i, t});
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i != j)
                dis[i][j] = 1e18;
    for(int i = 1; i <= n; i++){
        for(auto p : a[i]){
            for(auto v : route[p.first]){
                ckmn(dis[i][v.first], p.second + v.second);
            }
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                ckmn(dis[i][j], dis[i][k] + dis[k][j]);
    while(q--){
        int x, y;
        cin >> x >> y;
        ll ans = 1e18;
        for(auto u : route[x]){
            for(auto v : route[y]){
                ckmn(ans, u.second + v.second + dis[u.first][v.first]);
            }
        }
        ans += w[x] + w[y];
        cout << ans << '\n';
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}