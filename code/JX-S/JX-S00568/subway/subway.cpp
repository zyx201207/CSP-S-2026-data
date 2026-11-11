#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
ll c , n , m , d , q ;
ll t[500010] ;
vector <pair<ll,ll> > node[500010] ;
ll w[510][510] ;
int main () {
    freopen("subway.in","r",stdin) ;
    freopen("subway.out","w",stdout) ;
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
    cin >> c >> n >> m >> d >> q ;
    for ( ll i = 1 ; i <= m ; i ++ ) cin >> t[i] ;
    for ( ll i = 1 ; i <= n ; i ++ ) {
        ll x ;
        cin >> x ;
        for ( ll j = 1 ; j <= x ; j ++ ) {
            ll num , time ;
            cin >> num >> time ;
            node[num].push_back({i,time}) ;
        }
    }
    memset(w,0x3f3f3f3f,sizeof w) ;
    for ( ll i = 1 ; i <= m ; i ++ ) {
        for ( auto x : node[i] ) {
            ll u = x.first , w1 = x.second ;
            for ( auto y : node[i] ) {
                ll v = y.first , w2 = y.second ;
                if ( u == v ) continue ;
                w[u][v]=min(w[u][v],w1+w2) ;
            }
        }
    }
    for ( ll k = 1 ; k <= n ; k ++ ) {
        for ( ll i = 1 ; i <= n ; i ++ ) {
            for ( ll j = 1 ; j <= n ; j ++ ) {
                w[i][j]=min(w[i][j],w[i][k]+w[k][j]) ;
            }
        }
    }
    for ( ll i = 1 ; i <= n ; i ++ ) {
        w[i][i] = 0 ;
    }
    for ( ll i = 1 , a , b ; i <= q ; i ++ ) {
        cin >> a >> b ;
        ll res = LONG_LONG_MAX ;
        for ( auto x : node[a] ) {
            ll u = x.first , w1 = x.second ;
            for ( auto y : node[b] ) {
                ll v = y.first , w2 = y.second ;
                res = min(res,w[u][v]+w1+w2) ;
            }
        }
        cout << res+t[a]+t[b] << '\n' ;
    }
    return 0 ;
}
