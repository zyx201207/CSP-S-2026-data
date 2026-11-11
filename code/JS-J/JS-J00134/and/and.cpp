#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10010;
int n , m , a[MAXN] , dp[MAXN][MAXN];
int main() {
    //freopen("and.in" , "r" , stdin);
    //freopen("and.out" , "w" , stdout);
    scanf("%d%d" , &n , &m);
    for (int i = 1 ; i <= n ; i++) {
        scanf("%d" , &a[i]);
    }
    for (int i = 1 ; i <= n ; i++) {
        dp[i][1] = max(dp[i - 1][1] , a[i]);
        for (int j = 1 ; j <= min(i , m) ; j++) {
            dp[i][j] = max(max(dp[i][j] , dp[i - 1][j]) , dp[i - 1][j - 1] & a[i]);
        }
    }
    cout << dp[n][m];
    return 0;
}
