#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.in", "w", stdout);
    ll n, m, arr[100];
    ll max_i = INT_MIN, min_i = INT_MAX;
    cin >> n >> m;
    for (ll i = 0; i < n; i ++) {
        cin >> arr[i];
        max_i = max(arr[i], max_i);
        min_i = min(arr[i], min_i);
    }
    cout << max_i << " " << min_i << " " << n;
}
