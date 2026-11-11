#include <bits/stdc++.h>
using namespace std;
long long n, m, d, q;
long long w[500010];
long long mp[510][510];
vector <pair<int, long long> > zt[500010];
void jxd(int x){
    int y = zt[x].size() - 1;
    for (int j = 0; j < zt[x].size() - 1; j++){
        mp[zt[x][y].first][zt[x][j].first] = min(mp[zt[x][y].first][zt[x][j].first], zt[x][y].second + zt[x][j].second);
        mp[zt[x][j].first][zt[x][y].first] = min(mp[zt[x][j].first][zt[x][y].first], zt[x][j].second + zt[x][y].second);
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            mp[i][j] = 1e18;
        }
    }
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++){
            int x;
            long long y;
            cin >> x >> y;
            zt[x].push_back({i, y});
            jxd(x);
        }
    }
    for (int i = 1; i <= n; i++){
        mp[i][i] = 0;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                if(i == j || i == k || j == k) continue;
                mp[j][k] = min(mp[j][k], mp[j][i] + mp[i][k]);
            }
        }
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        long long mi = 1e18;
        for (int j = 0; j < zt[x].size(); j++){
            for (int k = 0; k < zt[y].size(); k++){
                mi = min(mi, mp[zt[x][j].first][zt[y][k].first] + zt[x][j].second + zt[y][k].second);
            }
        }
        mi += w[x] + w[y];
        cout << mi << "\n";
    }
    return 0;
}
