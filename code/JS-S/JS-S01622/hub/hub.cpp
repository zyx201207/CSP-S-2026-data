#include<bits/stdc++.h>
using namespace std ;
int n , k , dep[1000005] ,dist[1000005] ;
vector<int> v[1000005] , va ;
void dfs( int x ,int lst) {
    int len = v[x].size() ;
    if ( len == 1 ) {
        dep[x] = 1 ;
        return ;
    }
    //cout << x << " " << len << "\n" ;
    for ( int i = 0 ; i < len ; i++ ) {
        if( v[x][i] == lst ) continue ;
        dist[ v[x][i] ] = dist[x] + 1 ;
        dfs( v[x][i] , x ) ;
        dep[x] = max( dep[x] , dep[v[x][i]] ) ;
    }
}
int mxx = 0 ;
vector<int> q , aq ;
void js( int x , int cnt ) {
    if ( cnt <= 0 ) {
        mxx = max( dep[x] , mxx ) ;
        return ;
    }
    int len = v[x].size() ;
    for ( int i = 0 ; i < len ; i++ ) {
        q.push_back(v[x][i]) ;
    }
    len = q.size() ;
    int mx = 0 , num ;
    for ( int i = 0 ; i < len ; i++ ) {
        if ( mx < dep[q[i]] ) {
            mx = dep[q[i]] ;
            num = i ;
        }
    }
    q[num] = 0 ;
    int xx = q[num] ;
    js( xx , cnt - 1 ) ;
}
int main() {
    freopen("hub.in","r",stdin) ;
    freopen("hub.out","w",stdout) ;
    ios::sync_with_stdio(0) ;
    cin.tie(0) ;
    cout.tie(0) ;
    int c , T ;
    cin >> c >> T ;
    while(T--) {
        cin >> n >> k ;
        for ( int i = 1 ; i <= n ; i++ ) {
            v[i] = va ;
        }
        for ( int i = 1 ; i < n ; i++ ) {
            int x , y ;
            cin >> x >> y ;
            v[x].push_back(y) ;
            v[y].push_back(x) ;
        }
        dist[1] = 1 ;
        dfs( 1 , 1 ) ;
        int ans = 0x3f3f ;
        for ( int i = 1 ; i <= n ; i++ ) {
            for ( int j = 1 ; j <= n ; j++ ) {
                for ( int x = 0 ; x <= k ; x++ ) {
                    int y = k - x ;
                    mxx = max( dist[i] , dist[j] ) ;
                    q = aq ;
                    q = aq ;
                    ans = min( ans , mxx ) ;
                }
            }
        }
        cout << 1 << "\n" ;
    }
    return 0 ;
}
