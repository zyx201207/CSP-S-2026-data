#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500007;

int n;
ll m;
ll a[N];
ll l;
int cnt;
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << "\n";

    if (a[1] == a[n]) {
        cout << n << "\n";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        l = m;
        cnt = 1;
        while (l > 0) {
            if (i - cnt <= 0)  break;
            if (a[i] == a[i - cnt]) {
                cnt++;
                continue;
            }
            if (a[i] - a[i - cnt] <= l) {
                l -= ll(a[i] - a[i - cnt]);
                // cout << l << " " << cnt << "\n";
                cnt++;
            } else  break;
        }
        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}