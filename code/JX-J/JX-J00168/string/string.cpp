#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    cin >> n;

    vector<pair<int, char>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    int l = 0, r = n - 1;
    long long ans = 0;
    while (l < r) {
        int len = min(a[l].first, a[r].first);
        if (a[l].second != a[r].second) {
            ans += len;
        }
        a[l].first -= len, a[r].first -= len;
        
        if (!a[l].first) {
            l++;
        } if (!a[r].first) {
            r--;
        }
    }

    cout << ans;

    return 0;
}
