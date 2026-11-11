#include<bits/stdc++.h>
#define int long long
#define PII pair<int, int>

using namespace std;

const int MAXX = 5e5 + 5, MAXN =  5e2 + 5;

int s, t, ans, c, n, m, d, q, w[MAXX], dis[MAXN][MAXN], vis[MAXN], x, y, k, sum[MAXN][MAXN];
vector<PII> a[MAXX], e[MAXN];

void dj(int s){
    memset(vis, 0, sizeof vis);
    priority_queue<PII, vector<PII>, greater<PII> > q;
    q.push({0, s}), dis[s][s] = 0;
    while(!q.empty()){
        int x = q.top().second; q.pop();
        if(vis[x]) continue; vis[x] = 1;
        for(int i = 0; i < e[x].size(); i++){
            // cout << s << " : " << x << " " << y << '\n';
            int y = e[x][i].first, w = e[x][i].second;
            if(dis[s][y] > dis[s][x] + w) dis[s][y] = dis[s][x] + w, q.push({dis[s][y], y});
        }
    }
}


signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        cin >> k;
        for(int j = 1; j <= k; j++) cin >> x >> y, a[x].push_back({i, y});
    } memset(sum, 0x3f, sizeof sum), memset(dis, 0x3f, sizeof dis);
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < a[i].size(); j++){
            // cout << i << " " << a[i][j].first << '\n';
            for(int k = j + 1; k < a[i].size(); k++){
                x = a[i][j].first, y = a[i][k].first;
                sum[x][y] = min(sum[x][y], a[i][j].second + a[i][k].second);
                sum[y][x] = min(sum[y][x], a[i][j].second + a[i][k].second);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            // cout << i << " " << j << " " << sum[i][j] << '\n';
            if(sum[i][j] != sum[0][0]) e[i].push_back({j, sum[i][j]}), e[j].push_back({i, sum[i][j]});
        }
    } for(int i = 1; i <= n; i++) dj(i);
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++) cout << dis[i][j] << " "; cout << '\n';
    // }
    while(q--){
        cin >> s >> t; ans = sum[0][0];
        for(int i = 0; i < a[s].size(); i++){
            for(int j = 0; j < a[t].size(); j++){
                // cout << w[a[s][i].first] << " " << w[a[t][j].first] << '\n';
                ans = min(ans, w[s] + w[t] + a[s][i].second
                 + a[t][j].second + dis[a[s][i].first][a[t][j].first]);
            }
        } cout << ans << '\n';
    }
    return 0;
}