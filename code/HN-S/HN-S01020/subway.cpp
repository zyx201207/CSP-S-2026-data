#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e2 + 12, M = 5e5 + 12;

int c, n, m, d, q, w[M], E[N][N], dis[N][N];

bool vis[N];

vector<pair<int, int> > vec[M];

void dij(int s){
    priority_queue<pair<int, int> > que;
    que.push({0, s});
    for(int i = 1; i <= n; i ++) dis[s][i] = 1e18, vis[i] = false;
    dis[s][s] = 0; vis[s] = true;
    while(!que.empty()){ pair<int, int> x = que.top(); que.pop();
        vis[x.second] = false;
        for(int i = 1; i <= n; i ++){
            if(dis[s][x.second] + E[x.second][i] < dis[s][i]){
                dis[s][i] = dis[s][x.second] + E[x.second][i];
                if(!vis[i]){ vis[i] = true;
                    que.push({-dis[s][i], i});
                }
            }
        }
    }
}

void solve(){ cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i ++) cin >> w[i];
    for(int i = 1; i <= n; i ++){
        int k; cin >> k;
        for(int j = 1; j <= k; j ++){
            int a, t; cin >> a >> t;
            vec[a].emplace_back(i, t);
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++) E[i][j] = 1e18;
    }
    for(int i = 1; i <= m; i ++){
        for(int j = 0; j < vec[i].size(); j ++){
            for(int k = 0; k < vec[i].size(); k ++){
                E[vec[i][j].first][vec[i][k].first] = E[vec[i][k].first][vec[i][j].first] = min(E[vec[i][j].first][vec[i][k].first], vec[i][j].second + vec[i][k].second);
            }
        }
    }
    // cerr << E[1][2] << '\n';
    for(int i = 1; i <= n; i ++){
        dij(i);
    }
    while(q --){
        int s, t, res = 1e18; cin >> s >> t;
        for(int i = 0; i < vec[s].size(); i ++){
            for(int j = 0; j < vec[t].size(); j ++){
                res = min(res, w[s] + w[t] + vec[s][i].second + vec[t][j].second + dis[vec[s][i].first][vec[t][j].first]);
            }
        }
        cout << res << '\n';
    }
}

signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1;// cin >> T;
    while(T --) solve();
}