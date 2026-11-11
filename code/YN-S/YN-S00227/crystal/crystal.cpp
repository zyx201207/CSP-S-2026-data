#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 5E5 + 10;
ll n;
ll m, a[MAXN], s[MAXN], answer, l, r;

ll* find_l(ll *first, ll *last, ll k, ll r) {
    ll a = 0, b = last - first;
    ll result = last - first;
    while (a < b) {
        ll mid = (a + b) >> 1;
        if (first[r] * (r - mid) - (s[r] - s[mid]) <= k) {
            result = mid;
            b = mid;
        } else {
            a = mid + 1;
        }
    }
    return first + result;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    ll flag = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        flag = min(flag, a[i]);
    }
    for (ll i = 1; i <= n; i++) {
        a[i] += flag;
    }
    sort(a + 1, a + 1 + n);
    for (ll i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    for (r = n; r; --r) {
        l = find_l(a, a + r, m, r) - a;
        if (l == r) {
            answer = max(answer, r);
        }
        answer = max(answer, r - l);
    }
    cout << answer << endl;
    return 0;
}
