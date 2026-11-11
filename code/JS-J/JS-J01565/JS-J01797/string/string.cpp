#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string s;
vector<char> c;
vector<ll> a;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    c.push_back(' ');
    a.push_back(0);
    bool check = true;
    for (ll i = 1; i <= n; i++) {
        ll t;
        char t2;
        cin >> t >> t2;
        ll len = c.size() - 1;
        if (t2 != c[len]) {
            c.push_back(t2);
            a.push_back(t);
        } else {
            a[len] += t;
        }
    }
    for (ll l = 1, r = n; l < r; l++, r--) {
        if (a[l] != a[r] || c[l] != c[r]) {
            check = false;
        }
    }
    if (check) {
        cout << 0;
        return 0;
    }
    for (ll i = 1; i <= n; i++) {
        while (a[i]--) {
            s += c[i];
        }
    }
    ll ans = 0;
    for (ll l = 0, r = s.size() - 1; l < r; l++, r--) {
        if (s[l] != s[r]) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
