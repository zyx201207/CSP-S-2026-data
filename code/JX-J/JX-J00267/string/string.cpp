#include <bits/stdc++.h>
using namespace std ;
long long r , l , maxn ;
struct sb {
    long long b ;
    char c ;
}a[100000000];
int main (){
    freopen("string.in","r",stdin) ;
    freopen("string.out","w",stdout) ;
    int n ;
    scanf ("%d",&n) ;
    r = n-1 ;
    for (int i = 0 ; i < n ; i ++){
        cin >> a[i].b >> a[i].c ;
    }
    while (l != r){
        if (a[l].c != a[r].c){
            if (a[l].b > a[r].b){
                maxn += a[r].b ;
                a[l].b -= a[r].b ;
                r -- ;
            }else{
                maxn += a[l].b ;
                a[r].b -= a[l].b ;
                l ++ ;
            }
        }else{
            if (a[l].b > a[r].b){
                a[l].b -= a[r].b ;
                r -- ;
            }else if(a[l].b < a[r].b){
                a[r].b -= a[l].b ;
                l ++ ;
            }else{
                l ++ ;
                r -- ;
            }
        }
    }
    printf ("%d",maxn);
    return 0 ;
}
