#include <bits/stdc++.h>
using namespace std;
int n,m;
long long dp[2050][2050],a[200050],pre[200050];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    if(n <= 2e4+50){
        for(int i=1;i<=n;i++){cin >> a[i];dp[i][1] = a[i];}
        for(int k=2;k<=m;k++){
            for(int i=1;i<=n;i++){
                dp[i][k] = max(dp[i-1][k],dp[i-1][k-1] & a[i]);
            }
        }
        cout << dp[n][m];
        return 0;
    }
    if(m == n-1){
        for(int i=1;i<=n;i++)cin >> a[i];
        sort(a+1,a+n+1,greater<long long>());
        long long ans = a[n];
        for(int i=n;i>=2;i--)ans &= a[i];
        cout << ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1,greater<long long>());
    long long ans = a[n];
    for(int i=n;i>=n-m+1;i--){
        ans &= a[i];
    }
    cout << ans;
}