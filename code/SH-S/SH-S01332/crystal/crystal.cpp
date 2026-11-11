#include <iostream>
#include <algorithm>
using namespace std;

using LL = long long;

const LL N = 5e5 + 10;
LL a[N], s[N];
LL n, m;

bool is_valid(LL len) {
    for (LL r = len; r <= n; r++) {
        LL l = r - len + 1;
        LL cost = (len * a[r]) - (s[r] - s[l - 1]);
        if (cost <= m) {
            return true;
        }
    }
    return false;
}

LL _lower_bound(LL l, LL r) {
    if (l >= r) {
        return l;
    }
    LL mid = l + (r - l) / 2;
    if (is_valid(mid)) {
        return _lower_bound(mid + 1, r);
    } else {
        return _lower_bound(l, mid);
    }
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (LL i = 1; i <= n; i++) {
        LL x;
        cin >> x;
        a[i] = x;
    }
    sort(a + 1, a + 1 + n);
    s[0] = 0;
    for (LL i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    cout << _lower_bound(0, n + 1) - 1 << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
