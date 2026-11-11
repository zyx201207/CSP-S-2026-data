#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5 ;
int n , m , a[N] , sum[N] ;
bool check( int l , int r )
{
    return sum[r]-sum[l-1]+m >= (r-l+1)*a[r] ;
}
signed main(){
    freopen( "crystal.in" , "r" , stdin ) ;
    freopen( "crystal.out" , "w" , stdout ) ;
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m ;
    for( int i = 1 ; i <= n ; i ++ ) cin >> a[i] ;
    sort( a+1 , a+n+1 ) ;
    for( int i = 1 ; i <= n ; i ++ ) sum[i] = sum[i-1]+a[i] ;
    int ans = 1 ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        int l = 1 , r = i ;
        while( l < r ) 
        {
            int mid = (l+r)>>1 ;
            if( check( mid , i ) ) r = mid ;
            else l = mid+1 ;
        }
        ans = max( ans , i-l+1 ) ;
    }
    cout << ans << "\n" ;
    return 0;
}
/*
Oct31==Dec25?

我好像昨天作了一个好类似的，还比这个难

怎么又不给long long的点，跟candy一样

显然可以钦定

14:42 大洋里全国

long long是完全够用的

得分[0,100]/[rand()%100+1,100]
*/