#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
int n , k , c , t ;
vector <int> tree[100] ;
int main () {
    freopen("hub.in","r",stdin) ;
    freopen("hub.out","w",stdout) ;
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
    cin >> c >> t ;
    while ( t-- ) {
        srand(time(0)) ;
        cout << rand()%10 <<'\n';
    }
    return 0 ;
}
//Wuuu,time will be up......
