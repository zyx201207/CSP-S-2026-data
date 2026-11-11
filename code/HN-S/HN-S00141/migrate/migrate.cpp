#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 7, M = 307;
int c, T, n;;
ll a[N], ans, d;
int f[M][M], dis[M][M];
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> T;
    while(T --) {
        ans = 0;
        cin >> n >> d;
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                f[i][j] = 0;
        for(int i = 1; i <= n; i ++)
            dis[i][i] = 0;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        int t = 1;
        for(int i = 1; i <= n; i ++) {
            while(t < i && a[i] - a[t] > d) t ++;
            for(int j = t; j <= i; j ++) dis[j][i] = f[j][i] = 1;
            for(int j = 1; j < t; j ++) 
                dis[j][i] = dis[j][t] + 1;
            for(int j = 1; j < t; j ++)
                for(int k = t; k < i; k ++)
                    if(dis[j][i] == dis[j][k] + 1) 
                        f[j][i] += f[j][k];
        }
        for(int i = 1; i <= n; i ++)
            for(int j = i; j <= n; j ++) if(f[i][j] == 2) ans ++;
        cout << ans << '\n';
    }
    return 0;
}