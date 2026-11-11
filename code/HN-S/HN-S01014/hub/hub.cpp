#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 4005;

int c, t, n, k, ans;
int fa[N], dis[N][N];
bool vis[N];
vector < int > g[N];

int find ( int x ) {
    if ( fa[x] == x ) {
        return x;
    }
    return fa[x] = find ( fa[x] );
}

inline void unionn ( int x, int y ) {
    x = find ( x ), y = find ( y );
    if ( x != y ) {
        fa[x] = y;
    }
}

int check () {
    int cnt = 0;
    for ( int i = 1; i <= n; i ++ ) {
        cnt += vis[i];
    }
    if ( cnt != k ) {
        return 1e9;
    }
    for ( int i = 1; i <= n; i ++ ) {
        fa[i] = i;
    }
    for ( int i = 1; i <= n; i ++ ) {
        if ( vis[i] ) {
            for ( int v : g[i] ) {
                if ( vis[v] ) {
                    unionn ( i, v );
                }
            }
        }
    }
    vector < int > tmp;
    for ( int i = 1; i <= n; i ++ ) {
        if ( vis[i] ) {
            tmp.push_back ( find ( i ) );
        }
    }
    sort ( tmp.begin (), tmp.end () );
    int pcnt = 0;
    for ( int i = 0; i < tmp.size () - 1; i ++ ) {
        pcnt += tmp[i] != tmp[i + 1];
    }
    if ( pcnt > 1 ) {
        return 1e9;
    }
    int maxi = 0;
    for ( int i = 1; i <= n; i ++ ) {
        int mini = n + 1;
        for ( int j = 1; j <= n; j ++ ) {
            if ( vis[j] ) {
                mini = min ( mini, dis[i][j] );
            }
        }
        maxi = max ( maxi, mini );
    }
    return maxi;
}

void dfs ( int x ) {
    if ( x == n + 1 ) {
        ans = min ( ans, check () );
        return ;
    }
    vis[x] = 1;
    dfs ( x + 1 );
    vis[x] = 0;
    dfs ( x + 1 );
}

void init ( int x, int fa, int rt ) {
    for ( int v : g[x] ) {
        if ( v != fa ) {
            dis[rt][v] = dis[rt][x] + 1;
            init ( v, x, rt );
        }
    }
}

signed main () {
    freopen ( "hub.in", "r", stdin );
    freopen ( "hub.out", "w", stdout );
    ios :: sync_with_stdio ( false );
    cin.tie ( 0 ), cout.tie ( 0 );
    cin >> c >> t;
    while ( t -- ) {
        cin >> n >> k;
        for ( int i = 1; i <= n; i ++ ) {
            g[i].clear ();
        }
        for ( int i = 1; i < n; i ++ ) {
            int u, v;
            cin >> u >> v;
            g[u].push_back ( v ), g[v].push_back ( u );
        }
        if ( n <= 10 ) {
            for ( int i = 1; i <= n; i ++ ) {
                init ( i, 0, i );
            }
            ans = 1e9;
            dfs ( 1 );
            cout << ans << '\n';
        }
        else {
            if ( k == n ) {
                cout << 0 << '\n';
                continue;
            }
            deque < int > q;
            q.push_back ( 2 ), q.push_back ( 2 );
            q.push_back ( 1 ), q.push_back ( 1 ), q.push_back ( 1 ), q.push_back ( 1 ), q.push_back ( 1 );
            int cnt = 1;
            for ( int i = 11; i <= n; i += 2 ) {
                q.push_back ( 1 );
                cnt ++;
                if ( cnt == 4 ) {
                    cnt = 1;
                    q.push_front ( q.front () + 1 );
                }
                else {
                    q.push_front ( q.front () );
                }
            }
            cout << q[k - 2] << '\n';
        }
    }
    return 0;
}

/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

7:
2 2 1 1 1 1
9:
3 2 2 1 1 1 1 1
11:
3 2 2 2 1 1 1 1 1 1
13:
4 2 2 2 2 1 1 1 1 1 1 1
15:
4 3 2 2 2 2 1 1 1 1 1 1 1 1
17:
4 3 3 2 2 2 2 1 1 1 1 1 1 1 1 1
*/