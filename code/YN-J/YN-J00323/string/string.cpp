#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 2E5 + 10;
ll s1[MAXN], s2[MAXN];
ll a[MAXN], n, l;
char c[MAXN];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        s1[i] = s1[i - 1] + a[i];
        l += a[i];
    }
    for (ll i = n; i; i--) {
        s2[i] = s2[i + 1] + a[i];
    }
    ll mid = l >> 1, x = 1, y = n, answer = 0;
    for (ll i = 1; i <= mid; ) {
        while (x < n && s1[x] < i) {
            x++;
        }
        while (y > 1 && s2[y] < i) {
            --y;
        }
        if (c[x] != c[y]) {
            answer += min(a[x], a[y]);
        }
        i += min(a[x], a[y]);
    }
    cout << answer << endl;
    return 0;
}
