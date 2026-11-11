#include<bits/stdc++.h>
using namespace std;
int a[500010];
int n, m, maxn;
int main()
{
    freopen( "crystal.in", "r", stdin );
    freopen( "crystal.out", "w", stdout );
    ios::sync_with_stdio( false );
    cin.tie( 0 ), cout.tie( 0 );
    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
    {
        cin >> a[i];
    }
    sort( a + 1, a + n + 1 );
    for( int i = 2; i <= n; i++ )
    {
        if( i < n && a[i + 1] == a[i] ) continue;
        int x = i - 1, w = m, ans = 1;
        while( x )
        {
            if( a[i] - a[x] <= w )
            {
                w -= a[i] - a[x];
                ans++;
                x--;
            }
            else break;
        }
        maxn = max( ans, maxn );
    }
    cout << maxn << endl;
    return 0;
}