#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+5 , inf = 1e18 ;
int n , d , a[N] ;

class pts40{
public:
    int dp[N] , dis[N] , cnt[N] ;
    void work()
    {
        int ans = 0 ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            dp[i] = 1 , dis[i] = 0 ;
            for( int j = 1 ; j <= n-i+1 ; j ++ ) cnt[j] = 0 ;
            cnt[0] = 1 ;
            int l = i ;
            for( int j = i+1 ; j <= n ; j ++ )
            {
                while( a[j]-a[l] > d )
                {
                    cnt[dis[l]] -= dp[l] ;
                    l ++ ;
                }
                if( l == j ) break ;
                else 
                {
                    dis[j] = dis[l]+1 , dp[j] = cnt[dis[l]] ;
                    cnt[dis[j]] += dp[j] ;
                }
                if( dp[j] == 2 ) ans ++ ;
            }
            // cout << "\n" ;
        }
        cout << ans << "\n" ;
    }
}jiaming;

class A{
public:
    void work()
    {
        if( n <= 1 )
        {
            cout << "0\n" ;
            return ;
        }
        int D = a[2]-a[1] , ans = 0 ;
        if( D == 0 ) { cout << "0\n" ; return ; }
        int step = d/D ;
        if( step <= 1 ) { cout << "0\n" ; return ; }
        int num = n-step*2+1 ;
        ans = max( num , ans ) ;
        cout << ans << "\n" ;
    }
}wenzai;

class B{
public:
    int r[N] ;
    void work()
    {
        for( int i = 1 ; i <= n ; i ++ )
        {
            r[i] = upper_bound( a+1 , a+n+1 , a[i]+d )-a-1 ;
        }
        int ans = 0 ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            int pl = r[i]-1 ;
            ans += max( r[pl]-r[pl-1] , 0ll ) ;
        }
        cout << ans << "\n" ;
    }
}lanyan;

signed main(){
    freopen( "migrate.in" , "r" , stdin ) ;
    freopen( "migrate.out" , "w" , stdout ) ;
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c , T ;
    cin >> c >> T ;
    while( T -- ) 
    {
        cin >> n >> d ;
        for( int i = 1 ; i <= n ; i ++ ) cin >> a[i] ;
        if( c <= 10 ) { jiaming.work() ; continue ; }
        if( c <= 12 ) { wenzai.work() ; continue ; }
        if( c <= 18 ) { lanyan.work() ; continue ; }
        jiaming.work() ;
    }
    return 0;
}
/*
7 3
-4 -2 0 1 2 3 5
md这个怎么过不了
*/
/*
有t测

什么时候最段路只有两条？

先打n^3，枚举起点DP就好 24pts

考虑优化n^3，发现每次O(n)转移太费时
对于最段路，越靠前的点肯定越优
尝试维护与最左转移点dis值相同的DP值之和，双指针维护失效位置 40pts

16:00，抬头一看，大家怎么都在migrate了
16:06，获得了40pts

显然40pts没有用到dp[i]==2的性质
考虑这个性质，发现考虑不出来

看看特殊性质
B:
设那个特殊位置为P，显然所有(i,P)都不合法，因为dis=1
一对点要可行，必然dis=2，因为i->P->j，因此i<P<j
所以要求(i,j)之中有一个点满足k!=P且i->k->j，还只能有一个，这个点必须是P-1或P+1
若第二个转移点是P-1，那么：
i要满足x[P-1]-x[i]<=d&&x[P+1]-x[i]>d，这个枚举完成
j要满足x[j]-x[P-1]<=d&&x[j]-x[P-2]>d，也可以枚举完成
两个数字分别为num1,num2，答案就是num1*num2
若第二个转移点是P+1，同理

显然，我们发现性质，若最段路为K，i走d1步走到的范围与j走K-d1不走到的范围交际为2
需要保证K为最段路

于是A，C可做
A:所有范围相同，且范围半径也是等差数列
r[i]=d/(x[1]-x[2]),若r[i]>=2，ans=\max n-r[i]*2+1
也就是找最小的r[i]>=2的r[i]
16:48 +8pts

B包含于C
我们发现一些别的性质：
对于固定i:
[r[i][k-1]+1,r[i][k]]就是满足到i的最段路是k的点
好像假了，开T4先

燃尽了，得分[0,56]/[48,56]
*/