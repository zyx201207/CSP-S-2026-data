#include <bits/stdc++.h>

using namespace std;

using lld = long long;

struct L {
    lld a;
    char c;

    bool operator<(const L& other) const {
        return a < other.a;
    }
};

char q(lld a, const vector<L>& ls) {
    return ls[lower_bound(ls.begin()+1, ls.end(), L{a, '/'}) - ls.begin()].c;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    lld n;
    cin >> n;

    vector<L> ls(n+1);

    lld t = 0;
    for (lld i = 1; i <= n; i++) {
        lld a;
        char c;
        cin >> a >> c;

        t += a;
        ls[i] = {t, c};
    }

    vector<lld> check;
    check.push_back(0);
    for (lld i = 1; i <= n; i++) {
        lld a = ls[i].a;

        if (a <= t/2) {
            check.push_back(a);
        } else {
            check.push_back(t-(ls[i-1].a + 1)+1);
        }
    }
    sort(check.begin() + 1, check.end());

    lld cs = check.size()-1, ans = 0;
    for (lld i = 1; i <= cs; i++) {
        if (q(check[i], ls) == q(t - check[i] + 1, ls)) continue;
        ans += check[i] - check[i-1];
    }

    cout << ans << endl;
    
    return 0;
}