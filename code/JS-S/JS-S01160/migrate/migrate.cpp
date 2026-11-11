#include <bits/stdc++.h>
#define int long long

using namespace std;

void dfs(int i, int s, vector<pair<int, int>> & dis, vector<int> & a, int n, int d){
    if (s > dis[i].first) return;
    if (s == dis[i].first) dis[i].second++;
    if (s < dis[i].first) dis[i].first = s, dis[i].second = 1;
    if (i == n) return;
    int x = a[i];
    int y = a[i] + d;
    auto itr = upper_bound(a.begin(), a.end(), y);
    int k;
    if (itr != a.end()){
        itr--;
        k = itr - a.begin();
    }
    else{
        k = n;
    }
    for (int j = k; j >= (i + 1); --j){
        if ((a[j] - x) <= d){
            dfs(j, s + 1, dis, a, n, d);
        }
    }
    return;
}

signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, t;
    cin >> c >> t;

    if (c <= 10){
        while (t--){
            int n, d;
            cin >> n >> d;
            vector<int> a(n + 1);
            for (int i = 1; i <= n; ++i){
                cin >> a[i];
            }
            int ans = 0;
            for (int i = 1; i <= n; ++i){   //meiju start
                vector<pair<int, int>> dis(n + 1, {1e7, 0});
                dfs(i, 0, dis, a, n, d);
                for (int j = i + 1; j <= n; ++j){
                    if (dis[j].second == 2){
                        ans++;
                    }
                }
            }
            cout << ans << endl;
        }
    }
    else if (c == 11 || c == 12){
        while (t--){
            int n, d;
            cin >> n >> d;
            vector<int> a(n + 1);
            for (int i = 1; i <= n; ++i){
                cin >> a[i];
            }
            int x = a[2] - a[1];
            if (d < 2 * x){
                cout << 0 << endl;
                continue;
            }
            int y = 1 + d/x + 1;
            cout << n - y + 1 << endl;
        }
    }
    return 0;
}