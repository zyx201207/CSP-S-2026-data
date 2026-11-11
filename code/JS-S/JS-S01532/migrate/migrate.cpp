#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int c, t, n;
long long d, x[N], dp[N][N];
long long f[N][N];
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> c >> t;
    while(t--){
        memset(x, 0x3f, sizeof(x));
        memset(dp, 0x3f, sizeof(dp));
        cin >> n >> d;
        for (int i = 1; i <= n; i++){
            cin >> x[i];
        }
        for (int i = 1; i <= n; i++){
            for (int j = i + 1; j <= n; j++){
                if(x[j] - x[i] > d) break;
                dp[i][j] = 1;
            }
        }
        for (int i = 1; i <= n; i++){
            dp[i][i] = 0;
        }
        for (int k = 1; k <= n; k++){
            for (int i = 1; i <= k; i++){
                for (int j = k + 1; j <= n; j++){
                    if(dp[i][j] > dp[i][k] + dp[k][j]){
                        dp[i][j] = dp[i][k] + dp[k][j];
                        f[i][j] = 1;
                    }
                    else if(dp[i][j] == dp[i][k] + dp[k][j]){
                        f[i][j]++;
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++){
            for (int j = i; j <= n; j++){
                if(f[i][j] == 2)ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
