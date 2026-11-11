#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e5 + 10;

int n;

ll a[N], m, pref[N];

bool check(int x) {
    for (int i = x; i <= n; i++) {
        if (1ll * x * a[i] - (pref[i] - pref[i - x]) <= m) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }
    int low = 1, high = n;
    int ans = -1;
    while (low < high) {
        //cout << low << ' ' << high << '\n';
        int mid = (low + high) >> 1;
        if (check(mid)) {
            low = mid + 1;
            ans = mid;
        } else {
            high = mid;
        }
    }
    cout << ans << '\n';
    return 0;
}
