#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 9;
int T, n;
ll d;
int num[N];
ll a[N];

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T >> T;
    while (T--) {
        ll ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i], num[i] = 0;
        int l = 1, r = 2, id = 1;
        while (l <= n) {
            if (a[r] - a[l] <= d && r <= n) num[l] = r - l, ++r;
            else num[l] = max(num[l], num[l - 1] - 1), ++l;
            if (l == r) ++r;
        }
        ll dif = a[2] - a[1];
        bool fl = 1;
        for (int i = 3; i <= n; i++)
            if (a[i] - a[i - 1] != dif) fl = 0;
        if (fl) {
            ll m = num[1] * 2 - 1;
            ans = max(0, n - m);
            if (dif >= d) ans = 0;
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
graph agian?
gong xi _Memory ke yi cheng di le!
eee no, smells like math.
never mind.

these sea birds might migrate for potato chips.(^ ^

I'm your MIRRORED INSANITY!!!
*/
