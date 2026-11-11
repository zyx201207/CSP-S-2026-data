#include <bits/stdc++.h>
using namespace std ;
string c1 , s1 , c2 , s2 ;
int main()
{
    freopen("travel.in","r",stdin) ;
    freopen("travel.out","w",stdout) ;
    cin >> c1 >> s1 >> c2 >> s2 ;
    int num1 = 0 , num2 = 0 ;
    num1 = ( c1[0] - '0' ) * 10 + ( c1[1] - '0' ) ;
    num2 = ( c2[0] - '0' ) * 10 + ( c2[1] - '0' ) ;
    if ( num1 == num2 ) cout << 1 ;
    else {
        cout << 0 << 0 << 0 << 0 ;
        return 0 ;
    }
    int k1 = 0 , k2 = 0 ;
    k1 = ( s1[0] - '0' ) * 10 + ( s1[1] - '0' ) ;
    k2 = ( s2[0] - '0' ) * 10 + ( s2[1] - '0' ) ;
    char a = s1[2] , b = s2[2] ;
    if ( k1 == k2 ) cout << 1 ;
    else{
        cout << 0 << 0 << 0 ;
        return 0 ;
    }
    if (( a <= 'C' && b <= 'C' ) || ( a > 'C' && b > 'C' ))
        cout << 1 ;
    else {
        cout << 0 << 0 ;
        return 0 ;
    }
    if ( abs( a - b ) == 1 ) cout << 1 ;
    else cout << 0 ;
    return 0 ;
}
