#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n, d, a[2000005], ans;
struct node{
    ll i, pos;
};
void run(){
    ans = 0;
    cin >> n >> d;
    ll *dp = new ll [n + 5]();
    ll *dp1 = new ll [n + 5]();
    for (ll i = 1; i <= n; i++) cin >> a[i];
    for (ll i = 1; i <= n; i++){
        memset(dp, 0x3f, (n + 5) * 8);
        memset(dp1, 0, (n + 5) * 8);
        dp[i] = 0;
        dp1[i] = 1;
        for (ll j = i + 1; j <= n; j++){
            for (ll k = j - 1; k >= i; k--){
                if (a[j] - a[k] <= d){
                    if (dp[j] > dp[k] + 1){
                        dp[j] = dp[k] + 1;
                        dp1[j] = dp1[k];
                    }
                    else if (dp[j] == dp[k] + 1){
                        dp1[j] += dp1[k];
                    }
                }
                else{
                    break;
                }
            }
            if (dp1[j] == 0){
                break;
            }
        }
        for (ll j = i; j <= n; j++){
            ans += (ll)(dp1[j] == 2);
            if (dp1[j] == 0) break;
        }
    }
    cout << ans << endl;
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll c, t;
    cin >> c >> t;
    for (ll i = 1; i <= t; i++){
        run();
    }
    return 0;
}
