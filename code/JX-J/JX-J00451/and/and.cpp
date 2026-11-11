#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ll n, a, b[1000], ans = 0;
    cin >> n >> a;
    ll max_n = 0;
    for (ll i = 0; i < n; i ++) {
        cin >> b[i];
        if(b[i] > max_n) {
            max_n = max(max_n, b[i]);
            ans = i;
        }
    }
    ll max2 = 0;
    for (ll i = 0; i < n; i ++) {
        if(b[i] > max2 && i != ans) max2 = b[i];
    }
    cout << max2;
    return 0;
}
