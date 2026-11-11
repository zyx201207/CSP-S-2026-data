#include<bits/stdc++.h>
using namespace std;
int a[200010];
int n, m, maxn, zzz = pow( 2, 31 ) - 1;
int ans = zzz;
void dfs( int x, int r, int c )
{
    if( r == 0 )
    {
        maxn = max( maxn, c );
        return;
    }
    if( x > n ) return;
    dfs( x + 1, r, c );
    dfs( x + 1, r - 1, c & a[x] );
}
int main()
{
    freopen( "and.in", "r", stdin );
    freopen( "and.out", "w", stdout );
    ios::sync_with_stdio( false );
    cin.tie( 0 ), cout.tie( 0 );
    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
    {
        cin >> a[i];
        maxn = max( maxn, a[i] );
        ans &= a[i];
    }
    if( m == n )
    {
        cout << ans << endl;
        return 0;
    }
    if( m == 1 )
    {
        cout << maxn << endl;
        return 0;
    }
    maxn = 0;
    if( m == 2 )
    {
        for( int i = 1; i < n; i++ )
        {
            for( int j = i + 1; j <= n; j++ )
            {
                maxn = max( maxn, a[i] & a[j] );
            }
        }
        cout << maxn << endl;
        return 0;
    }
    maxn = 0;
    dfs( 1, m, zzz );
    cout << maxn << endl;
    return 0;
}