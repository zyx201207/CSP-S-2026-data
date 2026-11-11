#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

constexpr int N = 5e5 + 5;

ll a[N], s[N];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = a[i] + s[i - 1];

        int l = 1, r = i;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        ans = max(ans, i - l + 1);
    }

    cout << ans << "\n";

    return 0;
}