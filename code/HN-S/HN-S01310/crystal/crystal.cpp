#include<bits/stdc++.h>
#define int long long 
using namespace std ;
const int N = 5e5 + 5 ;
int n , m , d = 0 ;
int a[N] ;
int sum[N] , ans = 0 ;
bool pA = 1 , pB = 1 , p1 = 0 ; 
bool cmp(int a , int b ){
    return a > b ;
}
namespace sub{
    void sov1(){
        memset(sum , 0 , sizeof(sum)) ;
        for(int i = 1 ; i <= n ; i ++ ){
            for(int j = 1 ; j <= n ; j ++ ){
                int k = a[j] - a[i] ;
                sum[i] += k > 0 ? 0 : k ;
            }
        }
        sort(sum + 1 , sum + n + 1 , cmp) ;
        int l = 1 , r = n ;
        while(l < r){
            int mid = (l + r) >> 1 ;
            if(sum[mid] + m <= 0){
                r = mid ;
            }
            else l = mid  + 1 ;
        }
        if(sum[r] + m < 0)r -- ;
        int i = r ;
        while(1){
           if(sum[i] != sum[r]){
               break ;
           }
           else i ++ ;
        }
        i -- ;
        cout << i << "\n" ;
        return ;
    }
    void sovA(){
        memset(sum , 0 , sizeof(sum)) ;
        for(int i = 2 ; i <= n ; i ++ ){
            sum[i] = sum[i - 1] - i + 1 ;
        }
        int l = 1 , r = n ;
        while(l < r){
            int mid = (l + r) >> 1 ;
            if(sum[mid] + m <= 0){
                r = mid ;
            }
            else l = mid  + 1 ;
        }
        if(sum[r] + m < 0)r -- ;
        cout << r << "\n" ;
        return ;
    }
    void sov3(){
        memset(sum , 0 , sizeof(sum)) ;
        for(int i = 2 ; i <= n ; i ++ ){
            sum[i] = (sum[i - 1] - i + 1) ;
            
        }
        for(int i = 1 ; i <= n ; i ++ ){
            sum[i] *= d ;
            cout << "lyh " << sum[i] << "\n" ;
        }
        int l = 1 , r = n ;
        while(l < r){
            int mid = (l + r) >> 1 ;
            if(sum[mid] + m <= 0){
                r = mid ;
            }
            else l = mid  + 1 ;
        }
        if(sum[r] + m < 0)r -- ;
        cout << r << "\n" ;
        return ;
    }
}
signed main(){
    freopen("crystal.in" , "r" , stdin) ;
    freopen("crystal.out" , "w" , stdout) ;

    cin >> n >> m ;
    if(n <= 5000)p1 = 1 ;
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> a[i] ;
    }
    int pa = a[2] - a[1] , pb = pa ;
    for(int i = 3 ; i <= n ; i ++ ){
        if(a[i] - a[i - 1] != 1)pA = 0 ;
        else if((pb != a[i] - a[i - 1]) || (a[i] - a[i - 1] <= 1))pB = 0 ;
    }
    if(p1 && !pA){
        sub::sov1() ;
        return 0 ;
    }
    if(pA){
        sub::sovA() ;
        return 0 ;
    }
    if(pB){
        d = a[2] - a[1] ;
        sub::sov3() ;
    }
    return 0 ;
}