#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;
const ll inf = 1e18;
int c, t, n;
ll d, x[maxn], dp[maxn];
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> x[i];
        }
        bool bo = true;
        int w = x[2] - x[1];
        for(int i = 3;i <= n;i++){
            if(w != x[i] - x[i - 1]){
                bo = false;
                break;
            }
        }
        if(bo == 1){
            ll ans = 0;
            for(int j = 1;j <= n;j++)dp[j] = 0;
            for(int j = 2;j <= n;j++){
                int p = j - 1, cnt = 1;
                ll mi = inf;
                while(p >= 1 && x[j] - x[p] <= d){
                    if(mi > dp[p]){
                        mi = dp[p];
                        cnt = 1;
                    }else if(mi == dp[p])cnt++;
                    p--;
                }
                if(mi == inf)break;
                if(cnt == 2){
                    ans += n - j + 1;
                }
                dp[j] = mi + 1;
            }
            cout << ans << "\n";
            continue;
        }
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++)dp[j] = 0;
            for(int j = i + 1;j <= n;j++){
                int p = j - 1, cnt = 1;
                ll mi = inf;
                while(p >= i && x[j] - x[p] <= d){
                    if(mi > dp[p]){
                        mi = dp[p];
                        cnt = 1;
                    }else if(mi == dp[p])cnt++;
                    p--;
                }
                if(mi == inf)break;
                if(cnt == 2)ans++;
                dp[j] = mi + 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
