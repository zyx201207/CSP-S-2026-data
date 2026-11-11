#include<bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
const int INF = INT_MAX;
int c, n, m, d, q, t[maxn][maxn], w[maxn];
int f[maxn][maxn][maxn], v[maxn][maxn][maxn], p[maxn][maxn];
vector <int> to[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    int len;
    for(int i = 1; i <= n; i++) {
        cin >> len;
        int tmp1, tmp2;
        for(int j = 1 ;j <= len; j++) {
            cin >> tmp1 >> tmp2;
            f[tmp1][i][0] = tmp2;
            f[tmp1][0][i] = tmp2;
            to[tmp1].push_back(i);
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                f[i][j][k] = f[i][j][0] + f[i][0][k];
                f[i][k][j] = f[i][k][0] + f[i][0][j];
                if(f[i][j][0] && f[i][0][k]) v[i][j][k] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            p[i][j] = INF;
            p[j][i] = INF;
            if(i == j) {
                p[i][j] = 0;
                p[j][i] = 0;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= m; k++) {
                if(v[k][i][j] && v[k][j][i]){
                    p[i][j] = min(p[i][j], f[k][i][j]);
                    p[j][i] = min(p[j][i], f[k][j][i]);
                }

            }
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(p[i][k] != INF && p[k][j] != INF) {
                    p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
                }
            }
        }
    }

    int x, y;
    while(q--) {
        cin >> x >> y;
        int ans = INF;
        for(auto i : to[x]) {
            for(auto j : to[y]) {
                ans = min(ans, p[i][j] + f[x][i][0] + f[y][j][0]);
            }
        }
        ans += w[x] + w[y];
        cout << ans << "\n";
    }
    return 0;
}
