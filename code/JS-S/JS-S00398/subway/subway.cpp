#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500010];
int a[510][30], t[510][30];
int vis[500010];
vector<int> z[500010];
int c, n, m, d, qq, x, y, minn, k;
signed main()
{
    freopen( "subway.in", "r", stdin );
    freopen( "subway.out", "w", stdout );
    ios::sync_with_stdio( false );
    cin.tie( 0 ), cout.tie( 0 );
    cin >> c >> n >> m >> d >> qq;
    for( int i = 1; i <= m; i++ )
    {
        cin >> w[i];
    }
    for( int i = 1; i <= n; i++ )
    {
        cin >> k;
        for( int j = 1; j <= k; j++ )
        {
            cin >> a[i][j] >> t[i][j];
            z[a[i][j]].push_back( i );
        }
    }
    while( qq-- )
    {
        cin >> x >> y;
        minn = 1e18;
        memset( vis, -1, sizeof vis );
        queue<pair<int,int>> q;    
        q.push( { x, w[x] + w[y] } );
        vis[x] = w[x] + w[y];
        while( !q.empty() )
        {
            int u = q.front().first;
            int ti = q.front().second;
            q.pop();
            if( u == y ) 
            {
                minn = min( minn, ti );
                continue;
            }
            for( int v:z[u] )
            {
                for( int i:a[v] )
                {
                    if( i == u ) continue;
                    int titi = ti + t[v][u] + t[v][i];
                    if( vis[i] != -1 && vis[i] <= titi) continue;
                    vis[i] = titi;
                    q.push( { i, titi } );
                }
            }
        }
        cout << minn << endl;
    }
    return 0;
}