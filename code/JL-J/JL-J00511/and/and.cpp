#include<bits/stdc++.h>
using namespace std ;

int a[200010] ;
int dp[200010][2] ;

int main()
{
    freopen("and.in", "r", stdin) ;
    freopen("and.out", "w", stdout) ;
    int n, m, maxn = -1 ;
    scanf("%d%d", &n, &m) ;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]) ;
        dp[i][0] = a[i] ;
        dp[i][1] = 1 ;
    }
    dp[0][0] = a[0] ;
    dp[0][1] = 1 ;
    for(int i=0; i<n; i++)
    {
        int sum = 0 ;
        for(int j=0; j<i; j++)
        {
            if(dp[j][1] + 1 <= m && dp[i][0] < dp[j][0] && a[i])
            {
               dp[i][0] = dp[j][0] & a[i];
               dp[i][1] = dp[j][1] + 1 ;
               //cout << dp[j][0] << " " << a[i] << " " <<  dp[i][0]  << " " << dp[i][1]<< endl ;
            }
        }
        if(dp[i][1] == m)maxn = max(maxn, dp[i][0]) ;
    }
    //for(int i=0; i<n; i++) cout << dp[i][0] << " " ;
    printf("%d", maxn) ;
    return 0 ;
}
