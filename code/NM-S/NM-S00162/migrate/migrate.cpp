#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 +5;

int c, t, x[N], Mx, n, d, ans;
vector<int> path[N];
void dfs(int a, int len){

    if (a > Mx || a < 0) return ;
    cout << a << ' ' << len << endl;
    path[a].push_back(len);
    for (int i = a; i <= n; i++) {
        for (int j = d; j >= 1; j++) {
            dfs(a + j, len+1);
        }
    }
    return ;
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            Mx = max(Mx, x[i]);
        }
        cout << x[3] << endl;
        continue;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) path[j].clear();
            dfs(i, 0);
            for (int j = 1; j <= n; j++) sort(path[j].begin(), path[j].end());
            int short_path = 1;
            for (int j = 1; j <= n; j++) {
                for (int l = 1; l < path[j].size(); l++) {
                    if (path[j][l] == path[j][0]) short_path++;
                }
            }
            if (short_path == 2) {
                ans++;
            }
        }
        cout << ans;
    }
    return 0;
}
