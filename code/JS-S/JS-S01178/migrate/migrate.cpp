#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5 ;
int c , t , n ;
long long d , x[N] , ans ;
vector<int> a ;
int main(){
    freopen("migrate.in","r",stdin) ;
    freopen("migrate.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    cin >> c >> t ;
    while ( t -- ){
        cin >> n >> d ;
        for ( int i = 1 ; i <= n ; i ++ ){
            cin >> x[i] ;
            if ( i >= 4 ){
                if ( x[i] - x[i-3] > d && x[i] - x[i-2] <= d && x[i-1] - x[i-3] <= d ){
                    ans ++ ;
                    a.push_back(i) ;
                    int j = i - 4 ;
                    while ( j > 1 && x[i-1] - x[j] <= d ){
                        ans ++ ;
                        j -- ;
                    }
                }
            }
        }
        for ( auto y : a ){
            int j = y + 1 ;
            while ( j < n && x[j] - x[y] <= d ){
                ans ++ ;
                j ++ ;
            }
        }
        cout << ans << endl;
        ans = 0 ;
    }
    return 0;
}
