#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>

int n;
int ans;
long long m;
int a[500010];

int main()
{
    freopen( "crystal.in", "r", stdin );
    freopen( "crystal.out", "w", stdout );
    std::ios::sync_with_stdio( false );
    std::cin.tie( 0 );
    std::cout.tie( 0 );
    std::cin >> n >> m;
    for( int i = 1; i <= n; i++ ) std::cin >> a[i];
    std::sort( a + 1, a + n + 1 );
    int l = 1;
    for( int i = 1; i <= n; i++ )
    {
        if( a[ i - 1 ] == a[i] )
        {
            ans = std::max( ans, i - l + 1 );
            continue;
        }
        while( m < ( i - l ) * ( a[i] - a[ i - 1 ] ) )
        {
            m += a[ i - 1 ] - a[l];
            l++;
        }
        m -= ( i - l ) * ( a[i] - a[ i - 1 ] );
        ans = std::max( ans, i - l + 1 );
    }
    std::cout << ans;
    return 0;
}