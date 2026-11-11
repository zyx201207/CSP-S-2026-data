#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio (0) , cin.tie (0) , cout.tie (0);
#define ll long long
#define endl '\n'
const int N = 3e5 + 10;
ll n , l , r, sum;
struct node {
    ll num;
    char s;
} a[N];
int main () {
    IOS
    freopen ("string.in" , "r" , stdin);
    freopen ("string.out" , "w" , stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i ++ ) cin >> a[i].num >> a[i].s;
    l = 1 , r = n;
    while (l < r) {
        if (a[l].num == a[r].num) {
            if (a[l].s != a[r].s) sum += a[l].num;
            l += 1 , r -= 1;
        }
        else if (a[l].num > a[r].num) {
            if (a[l].s != a[r].s) sum += a[r].num;
            a[l].num -= a[r].num;
            r -= 1;
        } else {
            if (a[l].s != a[r].s) sum += a[l].num;
            a[r].num -= a[l].num;
            l += 1;
        }
    }
    cout << sum;
    return 0;
}
