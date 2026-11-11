#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN = 2e5 + 5;
struct line{ll size; char k;} give[MAXN], a[MAXN], b[MAXN];
ll size_a[MAXN], size_b[MAXN];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ll n, m;
    cin >> n;
    for (ll j = 0; j < n; ++j) {
        cin >> give[j].size >> give[j].k;
        a[j].size = give[j].size, a[j].k = give[j].k;
        b[n - j - 1].size = give[j].size, b[n - j - 1].k = give[j].k;
        m += give[j].size;
        size_a[j] = (j != 0 ? size_a[j - 1] : 0) + give[j].size;
    }
    for (ll j = 0; j < n; ++j) {
        size_b[j] = (j != 0 ? size_b[j - 1] : 0) + b[j].size;
    }
    ll ans = 0;
    for (ll pos = 0, pos_a = 0, pos_b = 0; pos * 2 < m;) {
        ll size_a_cur = size_a[pos_a], size_b_cur = size_b[pos_b];
        if (size_a_cur <= size_b_cur) {
            if (a[pos_a].k != b[pos_b].k) {
                ans += size_a_cur - pos;
            }
            pos = size_a_cur;
            pos_a++;
        }
        if (size_a_cur > size_b_cur) {
            if (a[pos_a].k != b[pos_b].k) {
                ans += size_b_cur - pos;
            }
            pos = size_b_cur;
            pos_b++;
        }
    }
    cout << ans << "\n";
    return 0;
}