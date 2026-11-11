#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
using pi = pair<int, int>;
const int N = 5e5 + 10;
ll n, m, a[N], f[N];

bool check(int D) {
    for(int i = 1; i <= n - D + 1; i++) {
        int l = i, r = i + D - 1;
        ll res = 1ll * (r - l + 1) * a[r] - (f[r] - f[l - 1]);
        if(res <= m) return 1;
    }
    return 0;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + a[i];
    }
    int l = 1, r = n, mid;
    while(l < r) {
        mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l;
    return 0;
}