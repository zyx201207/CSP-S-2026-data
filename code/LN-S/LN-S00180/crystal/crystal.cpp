#include<bits/stdc++.h>
using namespace std ;
long long n ,a[500005] ;
long long b[500005] ;
long long m ;
long long p = 1 ;
long long l = 1 ;
bool is = false ;
bool is2 = false ;
bool is3 = false ;
int ta = 0 ;
int main(){
    freopen("a.in","r",stdin) ;
    freopen("a.out","w",stdout) ;
    scanf("%lld%lld" ,&n ,&m) ;
    for(long long i = 1 ; i <= n ; i++){
        scanf("%lld" ,&a[i]) ;
        b[i] = a[i] ;
        if(a[i-1]!=a[i] && i>=2){
            is = true ;
        }
        if(a[i] != i){
            is2 = true ;
        }
    }
    ta = a[2]-a[1] ;
    for(long long i = 1 ; i <= n-1 ; i++){
        if(a[i+1]-a[i] != ta){
           is3 = true ;
        }
    }
    if(is2==false){
        int ret = 0 ;
        int i = 1 ;
        while(m-i >= 0){
            ret++ ;
            i++ ;
        }
        cout << ret ;
    }else if(is3 == false){
        sort(a+1,a+1+n) ;
        long long i = 1 ;
        while(true){
            long long lin = (a[i]-2*a[1]+a[2])*(a[i]-a[1])/4 ;
            if(m>=lin){
               i++ ;
            }else{
                cout << i ;
            }
        }
    }else{
        sort(a+1,a+1+n) ;
    long long z = 0 ;
    long long ans = 1 ;
    long long m2 = m;
    if(is==false && m%n != 0){
        cout << n-1 ;
        return 0 ;
    }else if(is==false && m%n==0){
        cout << n ;
        return 0 ;
    }
    while(true && p+1 <= n){
        z = m-(p-l+1)*(a[p+1]-a[p]) ;
        if(z >= 0 && p+1 != n){
            m -= (p-l+1)*(a[p+1]-a[p]) ;
            for(long long i = l ; i <= p ; i++) a[i]=a[p+1] ;
        }else if(p+1 != n){
            m += a[l]-b[l] ;
            a[l]= b[l] ;
            l++ ;
        }
        if(p+1 == n || m== 0){
            break ;
        }
        p++ ;
    }
    long long maxn = -1000000005 ;
    for(long long i = 2 ; i <= n ; i++){
        if(a[i] == a[i-1]){
            ans++ ;
        }else{
            if(ans > maxn){
               maxn = ans ;
            }
            ans = 1 ;
        }
    }
    printf("%lld" ,maxn) ;
    }
    return 0 ;
}
