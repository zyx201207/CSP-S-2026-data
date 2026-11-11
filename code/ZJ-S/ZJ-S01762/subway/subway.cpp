#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int N = 5e5 + 10, M = 510;
ll dis[M][M], cost[N];
int c, n, m, d, Q;
vector<pair<int, int> > v[N];
void solve(){
    int s, t;
    ll ans = 0x3f3f3f3f3f3f3f3f;
    cin >> s >> t;
    for(int i = 0; i < (int)v[s].size(); i++){
        for(int j = 0; j < (int)v[t].size(); j++){
            int x = v[s][i].first, y = v[t][j].first, xt = v[s][i].second, yt = v[t][j].second;
            ans = min(ans, dis[x][y] + cost[s] + cost[t] + xt + yt);
        }
    }
    cout << ans << endl;
}
int main(){
    // freopen("ex_subway/subway6.in", "r", stdin);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> Q;
    for(int i = 1; i <= m; i++) cin >> cost[i];
    for(int i = 1; i <= n; i++){
        int len;
        cin >> len;
        for(int j = 1, x, w; j <= len; j++){
            cin >> x >> w;
            v[x].push_back({i, w});
        }
    }

    memset(dis, 0x3f, sizeof dis);
    for(int i = 1; i <= n; i++) dis[i][i] = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < (int)v[i].size(); j++){
            for(int k = 0; k < (int)v[i].size(); k++){
                int x = v[i][j].first, y = v[i][k].first, xt = v[i][j].second, yt = v[i][k].second;
                dis[x][y] = min(dis[x][y], 1ll * xt + yt);
            }
        }
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    while(Q--) solve();
    return 0;
}