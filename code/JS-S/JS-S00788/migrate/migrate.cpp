#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, d, a[N];
int dp[N];
int main(){
    freopen("migrate.in", "r",stdin);
    freopen("migrate.out", "w", stdout);
    int c, t, ans = 0;
    scanf("%d%d", &c, &t);
    while(t --){
        ans = 0;
        scanf("%d%d", &n, &d);
        for(int i = 1; i <= n; i ++){
            scanf("%d", &a[i]);
        }
        int ans = 0;
        for(int i = 1; i <= n; i ++){
            memset(dp, 0, sizeof(dp));
            dp[i] = 1;
            for(int j = i + 1; j <= n; j ++){
                for(int k = j; k >= i; k --){
                    if(a[j] - a[k] <= d){
                        dp[j] += dp[k];
                        if(dp[j] > 2){
                            break;
                        }
                    }else{
                        break;
                    }
                }
                if(dp[j] == 2){
                    ans ++;
                }
                cout << i << " " << j << " " << dp[j] << endl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
//AFO
