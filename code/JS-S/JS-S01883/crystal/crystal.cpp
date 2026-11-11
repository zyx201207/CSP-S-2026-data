#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 5e5 + 5;

ll n, m;
ll a[maxn];
ll ans = 1;
ll dp[maxn];
ll cnt[maxn];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    dp[0] = 0;
    cnt[0] = 0;
    for(ll i = 1; i <= n; i++){
        dp[i] = dp[i - 1] + (cnt[i - 1]) * (a[i] - a[i - 1]);
        if(dp[i] <= m){
            cnt[i] = cnt[i - 1] + 1;
            ans = max(ans, cnt[i]);
        }else{
            cnt[i] = cnt[i - 1] + 1;
            for(ll j = i - cnt[i] + 1; j <= i; j++){
                dp[i] -= (a[i] - a[j]);
                cnt[i] -= 1;
                if(dp[i] <= m){
                    break;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
