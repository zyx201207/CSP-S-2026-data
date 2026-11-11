#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std ;
const int N = 5e5+5 ;
int a[N] ;
signed main(){
    freopen("crystal.in" , "r" , stdin) ;
    freopen("crystal.out" , "w" , stdout) ;

    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ; cout.tie(NULL) ;

    int n , m ;
    cin >> n >> m ;
    int tot = 0 ;
    bool flag = 0 ;
    int B = 0 ;
    for(int i = 1 ; i <= n ; i ++){
       cin >> a[i] ;
       tot += a[i] ;
       if(i >= 2 && a[i] < a[i-1])
            flag = 1 ;
        if(i >= 3 && a[i]-a[i-1] != a[i-1]-a[i-2])
            B = 1 ;
    }
    if(flag)
        sort(a+1 , a+n+1) ;
    int p = a[n] ;
    if(tot+m >= p*n){
        cout << n << endl ;
        return 0 ;
    }
    int ans = 0 ;
    if(B == 0){
        int c = a[2]-a[1] ;
        int x = 0 , t = 0 ;
        while(x <= m){
            t ++ ;
            x = t*(t+1)*c/2 ;
        }
        cout << t << endl ;
        return 0 ;
    }
    for(int i = 1 ; i <= n ; i ++){
        int k = 0 ;
        for(int j = 1 ; j < i ; j ++){
            if(a[j] < a[i])
                k += a[i]-a[j] ;
        }
//        cout << i << ' ' << k << endl ;
        if(k > m)
            break ;
        ans = i ;
    }
    cout << ans << endl ;

    return 0 ;
}
//80
