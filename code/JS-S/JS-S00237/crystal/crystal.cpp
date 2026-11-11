#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 5;
int n, m, ans;
int arr[N];


signed main () {
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + 1 + n);
    int l = 1, r = 1;
    __int128 ned = 0;
    while (r <= n) {

        //cerr << l << ' ' << r << ' ' << ned << '\n';
        ans = max(ans, r - l + 1);
        r ++;
        __int128 N1 = 1;
        ned += N1 * (r - l) * (arr[r] - arr[r - 1]);
        while (ned > m) {
            ned -= arr[r] - arr[l];
            l ++;
        }
    }
    cout << ans;
    //cerr << ans;
    return 0;
}
