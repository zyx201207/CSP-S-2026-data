#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
ll c , t ;
ll n , d ;
ll a[5010] ;
vector <ll> g[5010] ;
bool vis[5010] ;
ll dis[5010] , num[5010] ;
priority_queue <pair<ll,ll> > q ;
void Dijkstra ( ll s ) {
    for ( ll i = 1 ; i <= n ; i ++ ) vis[i] = 0 , dis[i] = n+1 , num[i] = 0 ;
    while ( q.size() ) q.pop() ;
    dis[s] = 0 , num[s] = 1 , q.push({0,s}) ;
    while ( q.size() ) {
        ll u = q.top().second ;
        q.pop() ;
        if ( vis[u] ) continue ;
        vis[u] = 1 ;
        for ( auto v : g[u] ) {
            if ( dis[v] > dis[u]+1 ) {
                dis[v] = dis[u]+1 ;
                num[v] = num[u] ;
                q.push({-dis[v],v}) ;
            } else if ( dis[v] == dis[u]+1 ) {
                num[v] += num[u] ;
                q.push({-dis[v],v}) ;
            }
        }
    }
}
int main () {
    freopen("migrate.in","r",stdin) ;
    freopen("migrate.out","w",stdout) ;
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
    cin >> c >> t ;
    while ( t-- ) {
        ll ans = 0 ;
        cin >> n >> d ;
        for ( ll i = 1 ; i <= n ; i ++ ) cin >> a[i] , g[i].clear() ;
        for ( ll i = 1 ; i <= n ; i ++ ) {
            for ( ll j = i+1 ; j <= n ; j ++ ) {
                if ( a[j]-a[i] <= d ) g[i].push_back(j) ;
                else break ;
            }
        }
        for ( ll i = 1 ; i <= n ; i ++ ) {
            Dijkstra(i) ;
            for ( ll j = 1 ; j <= n ; j ++ ) {
                ans += (num[j]==2)?1:0 ;
            }
        }
        cout << ans << '\n' ;
    }
    return 0 ;
}

