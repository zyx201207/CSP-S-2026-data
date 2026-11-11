#include <bits/stdc++.h>
using namespace std;
int n, m, a[100010], dp[100010];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    for(int i = 1; i <= 100000; i++){
        dp[i] = 1;
    }
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= 1; j--){
            dp[j] = max(dp[j], dp[j - 1] & a[i]);
        }
    }
    cout << dp[m];
    return 0;
}
