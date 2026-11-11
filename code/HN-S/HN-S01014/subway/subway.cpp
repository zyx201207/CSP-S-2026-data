#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 505;
const int M = 5e5 + 5;

int c, n, m, d, q;
int w[M];
vector < int > node[N], tim[N];
vector < pair < int, int > > g[M];
int dis[N][N];

signed main () {
    freopen ( "subway.in", "r", stdin );
    freopen ( "subway.out", "w", stdout );
    ios :: sync_with_stdio ( false );
    cin.tie ( 0 ), cout.tie ( 0 );
    cin >> c >> n >> m >> d >> q;
    for ( int i = 1; i <= m; i ++ ) {
        cin >> w[i];
    }
    for ( int i = 1; i <= n; i ++ ) {
        int siz;
        cin >> siz;
        while ( siz -- ) {
            int x, k;
            cin >> x >> k;
            node[i].push_back ( x ), tim[i].push_back ( x );
            g[x].push_back ( { i, k } );
        }
    }
    memset ( dis, 0x3f, sizeof ( dis ) );
    for ( int i = 1; i <= n; i ++ ) {
        dis[i][i] = 0;
    }
    for ( int i = 1; i <= m; i ++ ) {
        for ( int j = 0; j < g[i].size (); j ++ ) {
            for ( int k = j + 1; k < g[i].size (); k ++ ) {
                dis[g[i][j].first][g[i][k].first] = dis[g[i][k].first][g[i][j].first] = min ( dis[g[i][k].first][g[i][j].first], g[i][j].second + g[i][k].second );
            }
        }
    }
    for ( int k = 1; k <= n; k ++ ) {
        for ( int i = 1; i <= n; i ++ ) {
            for ( int j = 1; j <= n; j ++ ) {
                dis[i][j] = min ( dis[i][j], dis[i][k] + dis[k][j] );
            }
        }
    }
    while ( q -- ) {
        int s, t;
        cin >> s >> t;
        int ans = 1e18;
        for ( pair < int, int > x : g[s] ) {
            for ( pair < int, int > y : g[t] ) {
                ans = min ( ans, x.second + y.second + dis[x.first][y.first] + w[s] + w[t] );
            }
        }
        cout << ans << '\n';
    }
    return 0;
}