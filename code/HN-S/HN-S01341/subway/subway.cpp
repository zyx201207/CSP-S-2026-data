#include<bits/stdc++.h>
#include<iostream>
#include<vector>

int c, d;
int n, m, q;
long long w[500010];
long long e[505][505];

struct edge
{
    int to;
    long long w;
};

std::vector < edge > e1[500010];

int main()
{
    freopen( "subway.in", "r", stdin );
    freopen( "subway.out", "w", stdout );
    std::ios::sync_with_stdio( false );
    std::cin.tie( 0 );
    std::cout.tie( 0 );
    std::cin >> c >> n >> m >> d >> q;
    for( int i = 1; i <= m; i++ ) std::cin >> w[i];
    for( int i = 1; i <= n; i++ )
    {
        int x;
        std::cin >> x;
        for( int j = 1; j <= x; j++ )
        {
            int v;
            long long ew;
            std::cin >> v >> ew;
            e1[v].push_back( { i, ew } );
        }
    }
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            e[i][j] = 1e18;
        }
        e[i][i] = 0;
    }
    for( int i = 1; i <= m; i++ )
    {
        for( auto to1 : e1[i] )
        {
            for( auto to2 : e1[i] )
            {
                e[ to1.to ][ to2.to ] = std::min( e[ to1.to ][ to2.to ], to1.w + to2.w );
            }
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
                e[i][j] = std::min( e[i][j], e[i][k] + e[k][j] );
            }
        }
    }
    while( q-- )
    {
        int u, v;
        long long ans = 1e18;
        std::cin >> u >> v;
        for( auto u1 : e1[u] )
        {
            for( auto v1 : e1[v] )
            {
                ans = std::min( ans, u1.w + v1.w + e[ u1.to ][ v1.to ] );
            }
        }
        ans += w[u] + w[v];
        std::cout << ans << '\n';
    }
    return 0;
}