#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5 ;
int c , t , n , k , dep[N] , maxn , s ;
vector<int> a[N] ;
void dfs( int u , int fa ){
    dep[u] = dep[fa] + 1 ;
    for ( auto v : a[u] ){
        if ( v != fa ){
            dfs(v,u) ;
        }
    }
    if ( dep[u] > maxn ){
        maxn = dep[u] ;
        s = u ;
    }
}
int main(){
    freopen("hub.in","r",stdin) ;
    freopen("hub.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    cin >> c >> t ;
    while ( t -- ){
        cin >> n >> k ;
        for ( int i = 1 , u , v ; i < n ; i ++ ){
            cin >> u >> v ;
            a[u].push_back(v) ;
            a[v].push_back(u) ;
        }
        dfs(1,0) ;
        memset(dep,0,sizeof(dep)) ;
        maxn = 0 ;
        dfs(s,0) ;
        cout << s ;
        maxn = 0 ;
    }
    return 0;
}
