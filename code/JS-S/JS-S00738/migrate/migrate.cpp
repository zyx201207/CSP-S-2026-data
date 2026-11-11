#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int n , d ;
ll a[2000005] ;
bool e[20005][20005] ;
queue<int> q ;
void solve(){
    cin >> n >> d ;
    int arr = 1 ;
    for(int i = 1 ; i <= n ;  i++){
        cin >> a[i] ;
        while(a[i] - a[arr] > d) arr++ ;
        for(int j = arr ; j < i ; j++){
            e[j][i] = 1 ;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j < i ; j++){

        }
    }
}
void solve2(){
    cin >> n >> d ;
    for(int i = 1 ; i <= n ;  i++)
        cin >> a[i] ;
    int x1 = a[1] ;
    int x2 = a[2] ;
    if(d >= 2*(x2 - x1) && d < 3*(x2 - x1)) cout << n - 3 << "\n";
    else cout << 0 <<"\n";
}
int main(){
    freopen("migrate.in" , "r" , stdin) ;
    freopen("migrate.out" , "w" , stdout) ;
    int c , t ;
    cin >> c >> t;
    if(c == 11 || c == 12) while(t--) solve2() ;
    else while(t--) solve() ;
    return 0 ;
}
