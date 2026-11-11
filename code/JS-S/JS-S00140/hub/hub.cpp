#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std ;
const int N = 1e5+5 ;

signed main(){
    freopen("hub.in" , "r" , stdin) ;
    freopen("hub.out" , "w" , stdout) ;

    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ; cout.tie(NULL) ;

    int c , t ;
    cin >> c >> t ;
    while(t--){
        int n , k ;
        cin >> n >> k ;
        cout << (n+k)%2 << endl ;
    }
    return 0 ;
}
