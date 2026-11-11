#include<bits/stdc++.h>
#include<iostream>
#include<vector>

int c, t;
int n;
long long d;
int e[5010][5010];
int dp[5010][5010];
long long x[2000010];

int main()
{
    freopen( "migrate.in", "r", stdin );
    freopen( "migrate.out", "w", stdout );
    std::ios::sync_with_stdio( false );
    std::cin.tie( 0 );
    std::cout.tie( 0 );
    std::cin >> c >> t;
    if( c == 11 || c == 12 )
    {
        while( t-- )
        {
            std::cin >> n >> d;
            for( int i = 1; i <= n; i++ ) std::cin >> x[i];
            long long p = d / ( x[2] - x[1] );
            if( p < 2 || p * 2 - 1 > n || n == 1 ) std::cout << "0\n";
            else std::cout << n - 2 * p + 1 << "\n";
        }
    }
    else
    {
        while( t-- )
        {
            int ans = 0;
            std::cin >> n >> d;
            for( int i = 1; i <= n; i++ ) std::cin >> x[i];
            for( int i = 1; i <= n; i++ )
            {
                e[i][i] = 0;
                int j = i + 1;
                while( j <= n && x[j] - x[i] <= d )
                {
                    e[i][j] = 1;
                    dp[i][j] = 1;
                    j++;
                }
                for( ; j <= n; j++ )
                {
                    e[i][j] = 1e9;
                    dp[i][j] = 0;
                }
            }
            for( int k = 1; k <= n; k++ )
            {
                for( int i = 1; i <= n; i++ )
                {
                    if( i == k ) continue;
                    for( int j = 1; j <= n; j++ )
                    {
                        if( i == j || j == k ) continue;
                        if( e[i][k] + e[k][j] < e[i][j] )
                        {
                            e[i][j] = e[i][k] + e[k][j];
                            dp[i][j] = dp[i][k] * dp[k][j];
                        }
                        else if( e[i][k] + e[k][j] == e[i][j] )
                        {
                            dp[i][j] += dp[i][k] * dp[k][j];
                        }
                    }
                }
            }
            for( int i = 1; i <= n; i++ )
            {
                for( int j = 1; j <= n; j++ )
                {
                    if( dp[i][j] == 2 ) ans++;
                }
            }
            std::cout << ans << "\n";
        }
    }
    return 0;
}