#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int MAXN = 2e5+10;
ll n, m, a[MAXN];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    ll ans = a[n-1];
    for (int i = n-2; i >= n - m; i--) ans = (ans & a[i]);
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
