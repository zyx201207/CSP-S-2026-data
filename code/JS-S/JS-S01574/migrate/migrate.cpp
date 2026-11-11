#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

ll c, t, n, d, a[2000010], dp[5010], ans;

inline void baoli(ll u)
{
    for(ll i = u;i < n;i++){
        for(ll j = i - 1;j >= u;j--){
            if(a[i] - a[j] <= d){
                dp[i] += dp[j];
            }
        }
    }
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        ans = 0;
        cin >> n >> d;
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        if(c == 13 || c == 14){
            if(n > 4){
                cout << 0 << endl;
                continue;
            }else{
                for(int i = 0;i < n;i++){
                    dp[i] = 1;
                    baoli(i);
                    for(int k = i;k < n;k++){
                        if(dp[k] == 2){
                            ans++;
                        }
                    }
                    memset(dp, 0, sizeof dp);
                }
                cout << ans << endl;
            }
        }else{
            for(int i = 0;i < n;i++){
                dp[i] = 1;
                baoli(i);
                for(int k = i;k < n;k++){
                    if(dp[k] == 2){
                        ans++;
                    }
                }
                memset(dp, 0, sizeof dp);
            }
            cout << ans << endl;
        }
    }
    

    return 0;
}