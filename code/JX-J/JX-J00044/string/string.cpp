#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;

struct Nod {
    ll l, r;
    char a;
} a[N];
ll sum[26][N];
map<ll, int> ls, rs;
int n;

int main() {
    ios::sync_with_stdio(false);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    ll m = 0;
    for (int i = 1; i <= n; i++) {
        ll sl;
        cin >> sl >> a[i].a;
        a[i].l = m + 1;
        a[i].r = m + sl;
        m = a[i].r;
        ls[a[i].l] = i;
        rs[a[i].r] = i;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i][j - 1] + (a[j].a != i + 'a' ? a[j].r - a[j].l + 1 : 0);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = rs.lower_bound(m - a[i].r + 1)->second, r = (--ls.upper_bound(m - a[i].l + 1))->second;
        if (l == r) {
            ans += (a[l].a != a[i].a ? (a[i].r - a[i].l + 1) : 0);
            continue;
        }
        ans += (a[l].a != a[i].a ? (a[l].r - (m - a[i].r + 1) + 1) : 0);
        ans += (a[r].a != a[i].a ? ((m - a[i].l + 1) - a[r].l + 1) : 0);
        ans += sum[a[i].a - 'a'][r - 1] - sum[a[i].a - 'a'][l];
    }
    cout << ans / 2 << '\n';
    return 0;
}
