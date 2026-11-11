#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e6 + 5;
const int M = 3e2 + 5;
int c, n, t, d;
int x[N];
int dp[M][M];
int cnt[M][M];

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> c >> t;
    
    if(c == 11 || c == 12){
        while(t--){
            cin >> n >> d;
            for(int i = 1; i <= n; i++){
                cin >> x[i];
            }
            int len = 1;
            while(x[1 + len] - x[1] <= d && 1 + len <= n) len++;
            len--;
            if(len <= 1) len = n;
            cout << max(0ll, n - 2 * len + 1) << "\n";
            //cout << len << "\n";
        }
    }
    
    while(t--){
        cin >> n >> d;
        memset(dp, 0x3f, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));

        for(int i = 1; i <= n; i++){
            cin >> x[i];
            dp[i][i] = 0;
        }
        int ans = 0;
        for(int len = 1; len <= n; len++){
            for(int i = 1; i <= n - len + 1; i++){
                int j = i + len - 1;
                cnt[i][j] = 1;
                if(x[j] - x[i] <= d){
                    dp[i][j] = 1;
                    cnt[i][j] = 1;
                    continue;
                }
                for(int k = i; k <= j; k++){
                    if(dp[i][k] <= 1){
                        if(dp[i][k] + dp[k][j] == dp[i][j]){
                            cnt[i][j] += cnt[i][k] * cnt[k][j];
                        }
                        if(dp[i][k] + dp[k][j] < dp[i][j]){
                            cnt[i][j] = cnt[i][k] * cnt[k][j];
                            dp[i][j] = dp[i][k] + dp[k][j];
                        }
                    }
                    else{
                        break;
                    }
                }
                if(cnt[i][j] == 2){
                    ans ++;
                }
            }
        }
        cout << ans << "\n";
    }


    return 0;
}