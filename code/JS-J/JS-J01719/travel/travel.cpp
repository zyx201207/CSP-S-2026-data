#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    int a , b , c , d;
    char n , m;
    cin >> a >> b >> n >> c >> d >> m;
    int B , D;
    if (n == 'A' || n == 'B' || n == 'C') B = 1;
    else B = 0;
    if (m == 'A' || m == 'B' || m == 'C') D = 1;
    else D = 0;
    if (a == c) cout << '1';
    else cout << '0';
    if (a == c && b == d) cout << '1';
    else cout << '0';
    if (a == c && b == d && B == D) cout << '1';
    else cout << '0';
    if (a == c && b == d && B == D && (abs(n - m) == 1)) cout << '1';
    else cout << '0';
    return 0;
}
