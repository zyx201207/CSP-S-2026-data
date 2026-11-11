#include <bits/stdc++.h>
using namespace std ;
long long a[10000001] ;
bool cmp (int a , int b){
    return a > b ;
}
int main (){
    freopen("and.in","r",stdin) ;
    freopen("and.out","w",stdout) ;
    int n , m ;
    cin >> n >> m ;
    for (int i = 0 ; i < n ; i ++){
        cin >> a[i] ;
    }
    sort (a,a+n+1,cmp);
    long long maxn = 0 ;
    int i = 0 ;
    int j = 0 ;
    while (j != m){
        if (a[i] != a[i]+1) j ++ ;
        i ++ ;
    }
    maxn = a[i-1];
    cout << maxn ;
    return 0 ;
}
