#include <bits/stdc++.h>
using namespace std;
const int N = 200007;
typedef long long ll;
int n;
ll a[N];
vector<ll> cnt;
char c[N];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        mx = max(mx, a[i]);
    }
    if (mx <= 500) {
        string s;
        ll tot = 0;
        for (int i = 1; i <= n; i++) {
            while (a[i]--) {
                s[++tot] = c[i];
            }
        }
        ll ans = 0;
        for (int i = 1; i * 2 <= tot; i++) {
            if (s[i] != s[tot - i + 1]) ans++;
        }
        cout << ans;
        return 0;
    }
    ll tot = 0;
    int p = 0;
    cnt.push_back(0);
    for (int i = 1; i <= n; i++) {
        tot += a[i];
        cnt.push_back(tot);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] * 2 > tot) {
            int mid = (tot + 1) / 2;
            if ((cnt[i] - mid) >= (mid - cnt[i - 1] - 1)) break;
        }
        ll l = lower_bound(cnt.begin(), cnt.end(), tot - cnt[i] + 1) - cnt.begin();
        ll r = lower_bound(cnt.begin(), cnt.end(), tot - cnt[i - 1]) - cnt.begin();
        //cout << l << ' ' << r << endl;
        for (int j = l; j <= r; j++) {
            if (c[j] != c[i]) {
                ans += min(cnt[j], tot - cnt[i - 1]) - max(tot - cnt[i], cnt[j - 1]);
            }
        }
    }
    cout << ans;
    return 0;
}
