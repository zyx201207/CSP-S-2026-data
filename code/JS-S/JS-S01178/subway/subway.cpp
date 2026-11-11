#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5 ;
const long long inf = 1e18 ;
int c , n , m , d , q , tot ;
long long dis[N*2] , w[N] ;
vector<pair<int,int> > a[N*2] ;
void dijkstra( int h ){
    for ( int i = 1 ; i <= tot ; i ++ ){
        dis[i] = inf ;
    }
    priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q ;
    q.push({0,h}) ;
    dis[h] = 0 ;
    while ( !q.empty() ){
        int u = q.top().second ;
        q.pop() ;
        for ( auto x : a[u] ){
            int v = x.first , y = x.second ;
            if ( dis[u] + y < dis[v] ){
                dis[v] = dis[u] + y ;
                q.push({dis[v],v}) ;
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin) ;
    freopen("subway.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    cin >> c >> n >> m >> d >> q ;
    for ( int i = 1 ; i <= m ; i ++ ){
        cin >> w[i] ;
    }
    tot = m ;
    for ( int i = 1 ; i <= n ; i ++ ){
        int k , l = 0 ;
        cin >> k ;
        for ( int j = 1 ; j <= k ; j ++ ){
            int x , t ;
            cin >> x >> t ;
            tot ++ ;
            a[x].push_back({tot,t}) ;
            a[tot].push_back({x,t}) ;
            if ( l ){
                a[l].push_back({tot,0}) ;
                a[tot].push_back({l,0}) ;
            }
            l = tot ;
        }
    }
    for ( int i = 1 ; i <= q ; i ++ ){
        int x , y ;
        cin >> x >> y ;
        dijkstra(x) ;
        cout << w[x] + w[y] + dis[y] << endl;
    }
    return 0;
}
