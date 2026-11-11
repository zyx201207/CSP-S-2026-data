#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans, x, y;
struct len{
    int l;
    char s;
} a[200100];
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%lld", &n);
    for ( int i = 1; i <= n; i++ )
        scanf("%lld %c", &a[i].l, &a[i].s);
    x = n;
    for ( int i = 1; i <= n; i++ ){
        bool t = false;
        for ( int j = x; j >= 1 && !t; j-- )
            if ( a[i].l == a[j].l - y && a[i].s == a[j].s ) t = true, x++, y = 0;
            else if ( a[i].l != a[j].l - y && a[i].s == a[j].s ){ t = true;
                if ( a[i].l > a[j].l - y ) x++, y = 0;
                else y += a[i].l;
            }
            else if ( a[i].l == a[j].l - y ) ans += a[i].l, t = true, x++, y = 0;
            else if ( a[i].l > a[j].l - y ) x++, y = 0;
            else ans += a[i].l, y += a[i].l;
    }
    printf("%lld\n", ans);
    return 0;
}
