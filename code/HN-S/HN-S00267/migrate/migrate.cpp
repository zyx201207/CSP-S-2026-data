#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5, INF = 1e18;
int n, d, x[N];
namespace baoli{
    const int M = 305;
    int dp[M][M];
    void solve(){
        int ans = 0;
        memset(dp, 0, sizeof(dp));
        for(int l = 1; l < n; l++){
            dp[l][0] = 1;
            for(int i = l + 1; i <= n; i++){
                for(int k = 1; k <= n; k++){
                    dp[i][k] = 0;
                }
            }
            for(int i = l + 1; i <= n; i++){
                for(int j = i - 1; j >= l; j--){
                    if(x[i] - x[j] > d) break;
                    for(int k = 1; k <= i - l; k++){
                        dp[i][k] += dp[j][k - 1];
                    }
                }
            }
            for(int i = l + 1; i <= n; i++){
                int mn = INF;
                for(int k = i - l; k >= 1; k--){
                    if(dp[i][k]) mn = k;
                }
                if(mn == INF) continue;
                if(dp[i][mn] == 2){
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int C, T;
    cin >> C >> T;
    while(T--){
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
        }
        baoli::solve();
    }
    return 0;
}
/*
100 + 40 + 24 + 15
Can I get S1?
*/