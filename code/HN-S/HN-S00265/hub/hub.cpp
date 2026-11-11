#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5 , inf = 1e9 ;
int n , K ;
vector < int > a[N] ;

// class{
// public:
//     int len , dp[4005][4005][2][3] , siz[N] ;
//     void init() ;
//     void dfs( int x , int last )
//     {
//         siz[x] += 1 ;
//         for( int i = 0 ; i < (int)a[x].size() ; i ++ )
//         {
//             int v = a[x][i] ;
//             if( v == last ) continue ;
//             dfs( v , x ) ;
//             for( int j = 0 ; j <= min(siz[x],K) ; j ++ )
//             {
//                 for( int k = 0 ; k <= min(siz[v],K-j) ; k ++ )
//                 {
//                     int maxd0 = 0 , maxd1 = 0 ;
//                     for( int stau = 0 ; stau < 3 ; stau ++ )
//                     {
//                         for( int stav = 0 ; stav < 3-stau ; stav ++ )
//                         {
//                             //正常转移，类似秋直径
//                             maxd0 = max( maxd0 , dp[x][j][0][stau]+dp[v][k][0][stav]+1 ) ;
//                             dp[x][j+k][0][stau+stav] = max( dp[x][j+k][0][stau+stav] , dp[v][k][0][stav]+1 ) ;
//                             dp[x][j+k][0][stau+stav] = max( dp[x][j+k][0][stau+stav] , dp[v][k][1][stav]+1 ) ;
                            
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     void work()
//     {
//         for( int i = 1 ; i <= n ; i ++ ) ;
//     }
// }wenzai;

class sub13{
public:
    int f[N] , sign[N] ;
    int find( int x )
    {
        if( x == f[x] ) return x ;
        return f[x] = find( f[x] ) ; 
    }
    void merge( int x , int y )
    {
        x = find( x ) , y = find( y ) ;
        if( x == y ) return ;
        f[x] = y ;
        return ;
    }
    int dis[N] ;
    void init()
    {
        for( int i = 1 ; i <= n ; i ++ ) dis[i] = inf ;
    }
    void work()
    {
        int ans = inf ;
        for( int i = 0 ; i < (1<<n) ; i ++ )
        {
            if( __builtin_popcount( i ) != K ) continue ;
            for( int j = 1 ; j <= n ; j ++ ) f[j] = j , sign[j] = ( ((1<<(j-1))&i) > 0 ) ;
            for( int j = 1 ; j <= n ; j ++ )
            {
                for( int k = 0 ; k < (int)a[j].size() ; k ++ )
                {
                    int v = a[j][k] ;
                    if( sign[j] && sign[v] ) merge( j , v ) ;
                }
            }
            int cnt = 0 ;
            for( int j = 1 ; j <= n ; j ++ ) cnt += ( sign[j] && find(j) == j ) ;
            if( cnt <= 2 )
            {
                init() ;
                queue < int > q ;
                for( int j = 1 ; j <= n ; j ++ )
                {
                    if( sign[j] )
                    {
                        q.push( j ) ;
                        dis[j] = 0 ;
                    }
                }
                int maxd = 0 ;
                while( !q.empty() )
                {
                    int x = q.front() ;
                    q.pop() ;
                    maxd = max( maxd , dis[x] ) ;
                    for( int i = 0 ; i < (int)a[x].size() ; i ++ )
                    {
                        int v = a[x][i] ;
                        if( dis[v] <= dis[x]+1 ) continue ;
                        dis[v] = dis[x]+1 ;
                        q.push( v ) ;
                    }
                }
                // cout << i << " " << maxd << "\n" ;
                // if( maxd == 1 )
                // {
                //     for( int j = 1 ; j <= n ; j ++ ) if( sign[j] ) cout << f[j] << " " ;
                //     cout << "\n" ;
                // }
                ans = min( ans , maxd ) ;
            }
        }
        cout << ans << "\n" ;
    }
}jiaming;

signed main(){
    freopen( "hub.in" , "r" , stdin ) ;
    freopen( "hub.out" , "w" , stdout ) ;
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c , T ;
    cin >> c >> T ;
    while( T -- )
    {
        cin >> n >> K ;
        for( int i = 1 ; i <= n ; i ++ ) a[i].clear() ;
        for( int i = 1 ; i < n ; i ++ )
        {
            int u , v ;
            cin >> u >> v ;
            a[u].push_back( v ) ;
            a[v].push_back( u ) ;
        }
        jiaming.work() ;
        // if( c <= 8 ) wenzai.work() ;
    }
    return 0;
}
/*
17:15

显然不需要龙龙

提议就是用k个点把树砍成若干部分，求各部分的直径的最大值最小
                                    ^
                                    这是错的

尝试设计一个n^2的dp
设dp[i][j][0/1][0/1/2]，表示i节点永乐j个点，i是否被选，产生了几个连通块
号几把男鞋阿，怎么防AK体怎（4声）么能防AK阿
放弃50分，我还是打15吧

看来我不配300

得分[0,15] 
*/