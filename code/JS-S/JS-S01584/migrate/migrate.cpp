#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
int n;
ll d;
ll pl[N];
pair<int, int> dp[5005][5005];
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--){
        scanf("%d%lld", &n, &d);
        int num;
        for(int i = 1;i <= n;i++){
            scanf("%lld", &pl[i]);
            if(i > 1 && pl[i]-pl[1] > d && pl[i-1]-pl[1] <= d) num = i-1;
        }
        if(c == 13 || c == 14){
            int l2, l1, r1, r2;
            l2 = num-2;
            l1 = num-1;
            r1 = num+1;
            r2 = num+2;
            int r3, r4;
            for(int i = n;i >= num;i--){
                if(pl[i]-pl[l1] <= d){
                    r4 = i;
                    break;
                }
            }
            for(int i = n;i >= num;i--){
                if(pl[i]-pl[l2] <= d){
                    r3 = i+1;
                    break;
                }
            }
            ll num1 = max(0, (r4-r3)+1);
            int l3, l4;
            for(int i = 1;i <= num;i++){
                if(pl[r1]-pl[i] <= d){
                    l4 = i;
                    break;
                }
            }
            for(int i = 1;i <= num;i++){
                if(pl[r2]-pl[i] <= d){
                    l3 = i-1;
                    break;
                }
            }
            ll num2 = max(0, (l3-l4)+1);
            //cout << r3 << " " << r4 << endl;
            //cout << l4 << " " << l3 << endl;
            printf("%lld\n", num1*num2);
            break;
        }
        ll ans(0);
        for(int i = 1;i <= n;i++){
            dp[i][i] = {0, 1};
            for(int j = i+1;j <= n;j++){
                if(pl[j]-pl[j-1] > d) break;
                dp[i][j] = dp[i][j-1];
                dp[i][j].first++;
                //cout << i << " " << j << ": " << dp[i][j].first << " " << dp[i][j].second << endl;
                for(int k = j-2;k >= i;k--){
                    if(pl[j]-pl[k] > d) break;
                    //cout << dp[i][k].first+1 << endl;
                    if(dp[i][k].first+1 < dp[i][j].first) dp[i][j] = {dp[i][k].first+1, 1};
                    else if(dp[i][k].first+1 == dp[i][j].first) dp[i][j].second++;
                }
                if(dp[i][j].second == 2) ans++;
                //cout << i << " " << j << ": " << dp[i][j].first << " " << dp[i][j].second << endl << endl;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
13 1
7 6
-6 -5 -3 0 3 4 6
*/

