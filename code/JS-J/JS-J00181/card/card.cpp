#include<bits/stdc++.h>
using namespace std;
bool vis[300010];
int ans[300010];
int a[500010];
int n, m;
int main()
{
    freopen( "card.in", "r", stdin );
    freopen( "card.out", "w", stdout );
    ios::sync_with_stdio( false );
    cin.tie( 0 ), cout.tie( 0 );
    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
    {
        cin >> a[i];
    }
    for( int x = 1; x <= n; x++ )
    {
        stack<int> s;
        memset( vis, false, sizeof vis );
        for( int i = x; i <= n; i++ )
        {
            if( vis[a[i]] ) 
            {
                while( s.top() != a[i] ) 
                {
                    vis[s.top()] = false;
                    s.pop();
                }
            }
            else
            {
                s.push( a[i] );
                vis[a[i]] = true;
            }
        }
        while( !s.empty() )
        {
            ans[s.top()]++;
            s.pop();
        }
    }
    for( int i = 1; i <= m; i++ )
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}