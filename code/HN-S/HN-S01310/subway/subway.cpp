#include<bits/stdc++.h>
#define int long long 
using namespace std ;
const int N = 5e5 + 5 ;
bool cmp(pair<int ,int> a , pair<int,int> b){
    return a.first < b.first ;
}
int c , n , m , d , q ;
int w[N] ,k[N] , x , y ;
int a[500][N] , t[500][N] ;
int d[N] ;
vector<pair<int , int>> g[N] ;
priority_queue<pair<int, int> , cmp> pq ;
bool v[N] ;

int dijkstra(int xx , int yy){
    memset(d , 0x3f , sizeof(d)) ;
    memset(v , 0 , sizeof(v)) ;
    d[xx] = 0 ;
    v[xx] = 1 ;
    pq.push({1 , 0}) ;
    while(!pq.empty()){
        int k = pq.top().second , kw = - pq.top().first ; pq.pop() ;
        v[k] = 0 ;
        for(auto & [i , w] : g[k]){
            if(d[i] > d[k] + w + kw){
                d[i] = d[k] + w + kw ;
                pq.push({-d[i] , i})  ;
                v[i] = 1 ;
            }
        }
    }
    return w[xx] + t[xx][xx] + d[yy] + t[yy][yy] ;
}

signed main(){
    freopen("subway.in" , "r" , stdin) ;
    freopen("subway.out" , "w" , stdout) ;

    cin >> c >> n >> m >> d >> q ;
    for(int i = 1 ; i <= m ; i ++ ){
        cin >> w[i] ;
    }
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> k[i] ;
        for(int j = 1 ;j <= k[i] ; j ++ ){
            cin >> a[i][j] >> t[i][j] ;
            g[a[i][j - 1]].push_back({a[i][j] , t[i][j]}) ;
        }
    }
    while(q -- ){
        cin >> x >> y ;
        cout << dijkstra(x , y) << "\n" ;
    }
    return 0 ;
}