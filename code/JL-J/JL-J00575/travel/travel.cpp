#include <bits/stdc++.h>
using namespace std ;

long long n , m ;
string a , b ;
int main()
{
    freopen("travel.in","r",stdin) ;
    freopen("travel.out","w",stdout) ;
    cin >> n >> a >> m >> b ;
    if (n == m) cout << 1 ;
    else
    {
        cout << 0 << 0 << 0 << 0;
        return 0 ;
    }

    if (a[0] == b[0] && a[1] == b[1]) cout << 1; // tyl
    else
    {
        cout << 0 << 0 << 0 ;
        return 0 ;
    }

    if (a[2] <= 'C' && b[2] <= 'C') cout << 1 ;
    else if (a[2] >= 'D' && a[2] >= 'D') cout << 1 ;
    else
    {
        cout << 0 << 0 ;
        return 0 ;
    }

    if (a[2] != 'D' && a[2] + 1 == b[2]) cout << 1 ;
    else if (a[2] != 'D' && a[2] - 1 == b[2]) cout <<1 ;
    else if (a[2] == 'D' && b[2] == 'F') cout << 1 ;
    else if (a[2] == 'F' && a[2] == 'D') cout << 1 ;
    else cout << 0 ;
    return 0 ;
}
