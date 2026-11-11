#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e6 + 5;

int c, t, n, d, ans;
int a[N], r[N], l[N], siz[2][N];
vector < int > g[N];

inline int calc ( int x, int y, int val ) {
    if ( l[x] > val || l[y] < val ) {
        return 0;
    }
    int L = x - 1, R = y + 1;
    while ( L + 1 < R ) {
        int mid = L + R >> 1;
        if ( l[mid] < val ) {
            L = mid;
        }
        else {
            R = mid;
        }
    }
    if ( l[L + 1] != val ) {
        return 0;
    }
    int L2 = L, R2 = y + 1;
    while ( L2 + 1 < R2 ) {
        int mid = L2 + R2 >> 1;
        if ( l[mid] > val ) {
            R2 = mid;
        }
        else {
            L2 = mid;
        }
    }
    return max ( 0ll, R2 - L - 1 );
}

void dfs ( int x ) {
    siz[0][x] = siz[1][x] = 0;
    for ( int v : g[x] ) {
        dfs ( v );
        siz[0][x] += siz[0][v], siz[1][x] += siz[1][v];
    }
    if ( !g[x].size () ) {
        return ;
    }
    if ( r[x] ) {
        int res = calc ( x + 1, r[x], x ), res2 = calc ( x + 1, r[x], x - 1 );
        ans += siz[1][x] * res;
        for ( int v : g[x] ) {
            if ( l[x - 1] == v && l[r[x]] >= x - 1 ) {
                ans += siz[0][v] * res2;
            }
            if ( max ( v, l[x - 1] ) == v && l[r[x]] >= x - 1 ) {
                ans += res2;
            }
        }
        siz[0][x] = siz[1][x] = 0;
        for ( int v : g[x] ) {
            if ( l[r[x]] <= x - 2 ) {
                continue;
            }
            else if ( l[r[x]] == x - 1 && l[x - 1] < v ) {
                continue;
            }
            else if ( l[r[x]] == x - 1 && l[x - 1] == v ) {
                siz[1][x] += siz[0][v];
            }
            else {
                siz[0][x] += siz[0][v], siz[1][x] += siz[1][v];
            }
        }
        for ( int v : g[x] ) {
            if ( l[r[x]] <= x - 2 ) {
                continue;
            }
            else if ( l[r[x]] == x - 1 && max ( v, l[x - 1] ) < v ) {
                continue;
            }
            else if ( l[r[x]] == x - 1 && max ( v, l[x - 1] ) == v ) {
                siz[1][x] ++;
            }
            else {
                siz[0][x] ++;
            }
        }
    }
}

signed main () {
    freopen ( "migrate.in", "r", stdin );
    freopen ( "migrate.out", "w", stdout );
    ios :: sync_with_stdio ( false );
    cin.tie ( 0 ), cout.tie ( 0 );
    cin >> c >> t;
    while ( t -- ) {
        ans = 0;
        cin >> n >> d;
        g[0].clear ();
        for ( int i = 1; i <= n; i ++ ) {
            cin >> a[i];
            l[i] = r[i] = 0, g[i].clear ();
        }
        int pos = n;
        for ( int i = n; i >= 1; i -- ) {
            while ( pos >= 1 && a[pos] - a[i] > d ) {
                pos --;
            }
            r[i] = pos;
            if ( i == pos ) {
                r[i] = 0;
            }
            else {
                g[r[i]].push_back ( i );
            }
        }
        pos = 1;
        for ( int i = 1; i <= n; i ++ ) {
            while ( pos <= n && a[i] - a[pos] > d ) {
                pos ++;
            }
            l[i] = pos;
        }
        for ( int i = 1; i <= n; i ++ ) {
            if ( !r[i] ) {
                dfs ( i );
            }
        }
        cout << ans << '\n';
    }
    return 0;
}