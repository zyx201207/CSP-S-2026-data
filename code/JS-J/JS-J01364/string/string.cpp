#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5 +10 ;
int n ;
int a[N] ;
char c[N] ;
int main(){
    freopen("string.in","r",stdin) ;
    freopen("string.out","w",stdout) ;
    scanf("%d",&n) ;
    for(int i  = 1 ; i <= n ; i++){
            char d ;
        scanf("%d",&a[i]) ;
        cin >> c[i] ;
    }
    string s;
    int l = 0 ;
    s = " " ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= a[i] ; j++){
            s = s + c[i] ;
        }
        l+=a[i] ;
    }
    int cnt = 0 ;
    for(int i = 1 ;i < (l+1)/2 ; i++ ){
        if(s[i] != s[l+1-i]){
            cnt++ ;
        }
    }
    printf("%d",cnt) ;
    return 0 ;
}
