#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio (0) , cin.tie (0) , cout.tie (0);
#define ll long long
#define endl '\n'
const int N = 1e6 + 10;
ll n , m , l = 1 , ans = 1 , sum , last;
ll a[N];
ll b[N];
int main () {
    IOS
    freopen ("crystal.in" , "r" , stdin);
    freopen ("crystal.out" , "w" , stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i ++ ) cin >> a[i];
    sort (a + 1 , a + 1 + n);
    for (int i = 2 ; i <= n ; i ++ ) b[i] = a[i] - a[i - 1];
    for (int r = 1 ; r <= n ; r ++ ) {
        sum += (r - l) * b[r];
        last += b[r];
        while (sum > m && l <= r) {
            sum -= last;
            last -= b[l + 1];
            l += 1;
        }
        ans = max (ans , r - l + 1);
    }
    cout << ans;
    return 0;
}
