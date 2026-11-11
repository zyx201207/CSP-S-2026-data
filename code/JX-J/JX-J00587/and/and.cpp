#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
ll maxn = -1;


int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);


    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (m == 2) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = i + 1; j <= n; j++) {
                maxn = max(maxn, a[i] & a[j]);
            }
        }

        cout << maxn << "\n";
        return 0;
    }

    if (m == 1) {
        for (ll i = 1; i <= n; i++) {
            maxn = max(maxn, a[i]);
        }
        cout << maxn << "\n";
        return 0;
    }

    if (m == n) {
        for (ll i = 2; i <= n; i++) {
            a[i] = (a[i] & a[i-1]);
        }
        cout << a[n] << "\n";
        return 0;
    }
    return 0;
}
