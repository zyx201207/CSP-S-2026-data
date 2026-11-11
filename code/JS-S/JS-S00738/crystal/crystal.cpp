#include<bits/stdc++.h>
using namespace std ;
#define ll long long
ll a[500005] , m , n , cnt , arr , ans ;
int main(){
    freopen("crystal.in" , "r" , stdin) ;
    freopen("crystal.out" , "w" , stdout) ;
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    sort(a + 1 , a + n + 1) ;
    cnt = 0 ;
    for(int i = 2 ; i <= n ; i++){
        cnt += (i - 1) * (a[i] - a[i - 1]) ;
        if(cnt > m){
            arr = i ; // [1,arr) is okay
            cnt -= (i - 1) * (a[i] - a[i - 1]) ;
            break ;
        }
        if(i == n){
            cout << n ;
            return 0 ;
        }
    }
    ll l = 1 ;
    ans = arr - 1 ;
    for(int i = arr ; i <= n ; i++){
        cnt += (i - l) * (a[i] - a[i - 1]) ;
        while(cnt > m){
            cnt -= (a[i] - a[l]) ;
            l++ ;
        }
        ans = max(ans, i - l + 1) ;
    }
    cout << ans ;
    return 0 ;
}
