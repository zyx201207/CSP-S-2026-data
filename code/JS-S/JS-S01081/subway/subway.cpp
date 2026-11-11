#include<bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second

int c, n, m, d, q, a, b, res, w[500100], K[510], dist[510][510];
vector<pair<int, int> > v[510], s[500100];

signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(dist, 0x3f, sizeof(dist));
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
        cin >> w[i];
    for(int i = 1; i <= n; i++){
        cin >> K[i], dist[i][i] = 0;
        for(int j = 1; j <= K[i]; j++)
            cin >> a >> b, v[i].push_back({a, b}), s[a].push_back({i, b});
    }
    for(int i = 1; i <= n; i++)
        for(auto j : v[i])
            for(auto k : s[j.F])
                dist[i][k.F] = dist[k.F][i] = min(dist[i][k.F], j.S + k.S);
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    while(q--){
        cin >> a >> b, res = 1e18;
        for(auto i : s[a])
            for(auto j : s[b])
                res = min(res, dist[i.F][j.F] + w[a] + w[b] + i.S + j.S);
        cout << res << endl;
    }
    return 0;
}