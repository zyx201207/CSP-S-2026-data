#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n;
    long long m;
    cin >> n >> m;

    vector<long long> a(n);
    for (long long& i : a) {
        cin >> i;
    }

    sort(a.begin(), a.end());
    
    vector<long long> sum(n);
    for (int i = 0; i < n; i++) {
        if (i) {
            sum[i] = sum[i - 1];
        }
        sum[i] += a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = i;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (a[i] * (i - mid + 1) - (sum[i] - (mid ? sum[mid - 1] : 0)) > m) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        ans = max(ans, i - l + 1);
    }

    cout << ans;

    return 0;
}
