#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505 , M = 5e5+5 ;
int c , n , m , d , q , W[M] ;
int ans[N][N] ;//换乘答案
vector < pair<int,int> > g[M] ;
signed main(){
    freopen( "subway.in" , "r" , stdin ) ;
    freopen( "subway.out" , "w" , stdout ) ;
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> n >> m >> d >> q ;
    for( int i = 1 ; i <= m ; i ++ ) cin >> W[i] ;
    memset( ans , 0x3f , sizeof( ans ) ) ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        int K ;
        cin >> K ;
        for( int j = 1 ; j <= K ; j ++ )
        {
            int v , w ;
            cin >> v >> w ;
            g[v].push_back( { i , w } ) ;
        }
    }
    // for( int i = 1 ; i <= m ; i ++ )
    // {
    //     for( int j = 0 ; j < g[i].size() ; j ++ )
    //     {
    //         cout << g[i][j].first << " " << g[i][j].second << "\n" ;
    //     }
    // }
    for( int i = 1 ; i <= m ; i ++ )
    {
        for( int j = 0 ; j < (int)g[i].size() ; j ++ )
        {
            int u = g[i][j].first , ww = g[i][j].second ;
            for( int k = j+1 ; k < (int)g[i].size() ; k ++ )
            {
                int v = g[i][k].first , www = g[i][k].second ;
                ans[u][v] = min( ans[u][v] , ww+www ) ;
                ans[v][u] = min( ans[v][u] , ww+www ) ;
            }
        }
    }
    for( int i = 1 ; i <= n ; i ++ ) 
    {
        ans[i][i] = 0 ;
    }
    for( int k = 1 ; k <= n ; k ++ )
    {
        for( int i = 1 ; i <= n ; i ++ )
        {
            for( int j = 1 ; j <= n ; j ++ )
            {
                ans[i][j] = min( ans[i][j] , ans[i][k]+ans[k][j] ) ;
            }
        }
    }
    for( int i = 1 ; i <= q ; i ++ )
    {
        int x , y , nans = 1e18 ;
        cin >> x >> y ;
        for( int j = 0 ; j < (int)g[x].size() ; j ++ )
        {
            int u = g[x][j].first , ww = g[x][j].second ;
            for( int k = 0 ; k < (int)g[y].size() ; k ++ )
            {
                int v = g[y][k].first , www = g[y][k].second ;
                nans = min( nans , ans[u][v]+ww+www ) ;
                // cout << u << " " << v << " " << ans[u][v] << " " << ww << " " << www << "\n" ;
            }
        }
        cout << nans+W[x]+W[y] << "\n" ;
    }
    return 0;
}
/*
首先当然可以直接建图，让每个线路的站点向站台连边
这样可以做到O(qmlogm)，貌似有32

考虑利用n,d的优良性质，感觉可以在n上跑floyd
d<=20,n<500,暴力对n连边，连边复杂度O(\sum d^2)

但是这样只能处理出两条线路之间的最短路，即换乘时间
需要处理换乘点的问题

md我唐了，坐地铁怎么不要时间
那就简单了，暴力枚举起始的地铁线和中止的地铁线就好了

单次询问复杂度是O(d^2)，就是1e5*400=4e7，能过

显然需要开龙龙

15:25测完大洋里，感觉会卡，早个数据
感觉不好早阿，那先不早了

得分[0,100]/[92,100]
*/