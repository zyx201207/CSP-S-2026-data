#include<bits/stdc++.h>
using namespace std;

int n,m,dp[2010][2010],a[2000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i <= n ; i++){
        dp[i][0] = a[i+1];
    }
    for(int j = 1 ; j <= m ; j++){
        for(int i = 1 ; i <= n ; i++){
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]&a[i]);
        }
    }
    cout << dp[n][m];
    return 0;
}
