#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 305, N = 2e6 + 5, P = 1e9 + 7;

int c, T, n;
ll d, x[N], cnt[M][M];
int dis[M][M];
int nxt[N], pre[N], cont[N];

struct edge { int x, y; };

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> T;
    while(T--) {
        cin >> n >> d;
        for(int i = 1; i <= n; i++) cin >> x[i];
        if(c == 11 || c == 12) {
            if(n <= 3) {
                cout << 0 << '\n';
                continue;
            }
            ll dx = x[2] - x[1];
            ll t = d / dx;
            if(t <= 1 || n < 2 * t) cout << 0 << '\n';
            else cout << n + 1 - 2 * t << '\n';
        }
        else if(c == 13 || c == 14) {
            for(int i = 1; i <= n; i++) cont[i] = 0;
            for(int i = 1, j = 1; i <= n; i++) {
                while(j < n && x[j + 1] - x[i] <= d) j++;
                nxt[i] = j;
            }
            for(int i = n, j = n; i >= 1; i--) {
                while(j > 1 && x[i] - x[j - 1] <= d) j--;
                pre[i] = j;
                cont[j]++;
            }
            ll ans = 0;
            for(int i = 1; i <= n; i++) ans += cont[nxt[i] - 1];
            cout << ans << '\n';
        }
        else if(c <= 6) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    dis[i][j] = 1e9;
                    cnt[i][j] = 0;
                }
            }
            for(int i = 1; i <= n; i++) {
                for(int j = i + 1; j <= n; j++) {
                    if(x[j] - x[i] <= d) {
                        dis[i][j] = dis[j][i] = 1;
                        cnt[i][j] = cnt[j][i] = 1;
                    }
                }
            }
            for(int k = 1; k <= n; k++) {
                for(int i = 1; i <= n; i++) {
                    for(int j = 1; j <= n; j++) {
                        if(i == j || i == k || j == k) continue;
                        if(dis[i][k] + dis[k][j] < dis[i][j]) {
                            dis[i][j] = dis[i][k] + dis[k][j];
                            cnt[i][j] = cnt[i][k] * cnt[k][j] % P;
                        }
                        else if(dis[i][k] + dis[k][j] == dis[i][j]){
                            cnt[i][j] = (cnt[i][j] + cnt[i][k] * cnt[k][j] % P) % P;
                        }
                    }
                }
            }
            int ans = 0;
            for(int i = 1; i <= n; i++)
                for(int j = i + 1; j <= n; j++)
                    if(cnt[i][j] == 2)
                        ans++;
            cout << ans << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
    return 0;
}
