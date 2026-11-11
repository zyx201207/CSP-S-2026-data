#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int c, n, m, d, q, s[505][N], t, x, y;
int w[505], k[505];
int f[505][505];
int a[505];
bool vis[505];
long long ans;
vector<pair<int, int>> e[N];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++){
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++){
            cin >> s[i][j] >> t;
            e[s[i][j]].push_back({i, t});
        }
    }
    while(q--){
        cin >> x >> y;
        ans = 0x3f3f3f3f3f3f3f3f;
        for (auto [idx, tix] : e[x]){
            for (auto [idy, tiy] : e[y]){
                if(idx == idy){
                    ans = min(ans, (long long)(tix + tiy));
                }
            }
        }
        if(ans != 0x3f3f3f3f3f3f3f3f){
            cout << ans + w[x] + w[y] << "\n";
            continue;
        }
        memset(f, 0x3f, sizeof(f));
        for (int i = 1; i <= m; i++){
            for (auto [idx, tix] : e[i]){
                for (auto [idy, tiy] : e[i]){
                    if(idx == idy) continue;
                    f[idx][idy] = min(f[idx][idy], tix + tiy);
                }
            }
        }
        queue<int> q;
        memset(vis, 0, sizeof(vis));
        for (auto [idx, tix] : e[x]){
            for (int i = 1; i <= n; i++){
                if(f[idx][i] != 0x3f3f3f3f){
                    q.push(i);
                    vis[i] = 1;
                }
            }
            while (!q.empty()){
                int z = q.front();
                q.pop();
                vis[z] = 0;
                for (int i = 1; i <= n && i != idx; i++){
                    if(f[z][i] != 0x3f3f3f3f && !vis[i]){
                        f[idx][i] = min(f[idx][i], f[idx][z] + f[z][i]);
                        vis[i] = 1;
                        q.push(i);
                    }
                }
            }
        }
        for (auto [idx, tix] : e[x]){
            for (auto [idy, tiy] : e[y]){
                ans = min(ans, (long long)(f[idx][idy] + tix + tiy));
            }
        }
        cout << ans + w[x] + w[y] << "\n";
    }
    return 0;
}
