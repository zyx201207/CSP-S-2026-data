#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std ;
const int N = 2e6+5 ;
int x[N] ;
int ok[505][505] , dp[505][505];
signed main(){
    freopen("migrate.in" , "r" , stdin) ;
    freopen("migrate.out" , "w" , stdout) ;

    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ; cout.tie(NULL) ;

    int c , t ;
    cin >> c >> t ;
    while(t--){
            memset(dp , 0x3f , sizeof(dp)) ;
        int n , d ;
        cin >> n >> d ;
        for(int i = 1 ; i <= n ; i ++){
            cin >> x[i] ;
            dp[i][i] = 0 ;
        }
        sort(x+1 , x+1+n) ;
        int k = x[2]-x[1] ;
        if(c == 11 || c == 12){
            if(k >= d*2){
                cout << "0" << endl ;
            }
            else if(k < d){
                int p = d/k*2 ;
                cout << n-p+1 << endl ;
            }
        }
        else if(c == 13 || c == 14){
            cout << 0 << endl ;
        }
        else{
            for(int i = 1 ; i < n ; i ++){
                for(int j = i+1 ; j <= n ; j ++){
                    if(x[j] - x[i] <= d){
    //                    cout << x[i] << ' ' << x[j] << endl ;
                        ok[i][j] = 1 ;
                    }
    //                cout << ok[i][j] << ' ' ;
                }
    //            cout << endl ;
            }
            int ans = 0 ;
            for(int len = 2 ; len <= n ; len ++){
                for(int i = 1 ; i+len-1 <= n ; i ++){
                    int x1 = 0 , x2 = 0 ;
                    int k = i+len-1ll , cnt = 0;
  //                  cout << "@" << i << ' ' << k<< endl ;
                    for(int j = i+1 ; j < k ; j ++){
                        if(ok[i][j] == 0 && ok[j][k] == 0)
                            continue ;
                        int f = min(dp[i][k] , dp[i][j]+dp[j][k]+1) ;
                        if(dp[i][k] == f){
                      //      cout << "      " << i << ' ' << k << j << endl ;
                            cnt ++ ;
                        }
                        else{
                            dp[i][k] = f ;
                            cnt = 1 ;
                            x1 = i , x2 = k ;
                        //    cout << i << ' ' << k << endl ;
                        }
                    }
                    if(cnt == 2){
                        ans ++ ;
      //                  cout << x1 << ' ' << x2 << endl ;
                    }

                }
            }
            cout << ans << endl ;
        }
    }

    return 0 ;
}
