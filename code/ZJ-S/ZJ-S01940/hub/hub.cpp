#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 5e5 + 11;

ll n, m;
ll a[MAXN];
ll d[MAXN];
ll ans = 1;

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    bool flagA = true;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        if (i >= 2)
            if (a[i] != a[i - 1])
                flagA = false;
    }
    if (flagA)
        cout << n << "\n";
    else {
        sort (a + 1, a + n + 1);
        for (ll i = 1; i <= n; i++)
            d[i] = a[i] - a[i - 1];
        ll ctb = 0, sum = 0, cnt = 1;
        for (ll l = 2, r = 2; l <= n; l++) {
            while (l == r && d[r] > m && r <= n) {
                l++, r++;
                ctb = 0, sum = 0, cnt = 1;
            }
            while (ctb + d[r] * cnt <= m && r <= n) {
                ctb += d[r] * cnt;
                sum += d[r];
                cnt++, r++;
            }
            ctb -= sum;
            sum -= d[l];
            ans = max(ans, cnt);
            cnt--;
        }
        cout << ans << "\n";
    }

    cout.flush();
    return 0;
}
