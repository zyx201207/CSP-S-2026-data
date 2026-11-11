#include<bits/stdc++.h>
#include<iostream>

int c, t;
int n, k;

struct edge
{
    int nxt, to;
}edges[2000010];

int head[2000010], cnt;

void add( int u, int v )
{
    edges[ ++cnt ].nxt = head[u];
    edges[cnt].to = v;
    head[u] = cnt;
}

int main()
{
    freopen( "hub.in", "r", stdin );
    freopen( "hub.out", "w", stdout );
    std::ios::sync_with_stdio( false );
    std::cin.tie( 0 );
    std::cout.tie( 0 );
    std::cin >> c >> t;
    if( c == 13 || c == 14 )
    {
        while( t-- )
        {
            std::cin >> n >> k;
            for( int i = 1; i < n; i++ )
            {
                int u, v;
                std::cin >> u >> v;
                add( u, v );
                add( v, u );
            }
            int m = ( n - 1 ) / 2;
            if( k == n ) std::cout << "0\n";
            else if( k == m ) std::cout << "1\n";
            else if( k >= m / 2 ) std::cout << "2\n";
            else std::cout << ( m - 1 ) / 2 + 2 - k << "\n";
        }
    }
    return 0;
}