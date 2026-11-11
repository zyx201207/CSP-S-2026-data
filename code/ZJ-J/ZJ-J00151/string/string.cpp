#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int a[200005];
ll f[200005];
char c[200005];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        sum += a[i];
    }

    ll pos = (sum + 1) / 2;
    ll cnt = a[1];
    int idx = -1;

    for (int i = 1; i <= n; cnt += a[++i]) {
        if (cnt >= pos) {
            idx = i;
            break;
        }
    }
    ll l, r;
    if (sum & 1) {
        l = pos;
        r = pos;
    } else {
        l = pos;
        r = pos + 1;
    }

    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + a[i];
    }

    ll ans = 0;
    int idxl = idx, idxr = idx;
    while (l >= 1 && r <= sum) {
        int fl = l - f[idxl - 1];
        int fr = f[idxr] - r + 1;

        int go = min(fl, fr);
        l -= go;
        r += go;
        if (c[idxl] != c[idxr]) {
            ans += go - 1;
        }

        if (fl <= fr) {
            idxl--;
        }
        if (fl >= fr) {
            idxr++;
        }

        if (c[idxl] != c[idxr]) {
            ans++;
        }

    }

    cout << ans << '\n';

}
