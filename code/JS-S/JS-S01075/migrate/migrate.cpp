#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000020],dp[2000020];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> c >> t;
    if (c == 11 || c == 12){
        while (t--){
            cin >> n >> d;
            long long dd,ans = 0;
            for (int i = 1;i <= n;i++) {cin >> a[i];}
            dd = a[2] - a[1];
            for (int i = 4;i <= n;i += 2){
                if (dd * ((i-1)/2+1) <= d && dd * ((i-1)/2+2) > d) ans += n - i + 1;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
