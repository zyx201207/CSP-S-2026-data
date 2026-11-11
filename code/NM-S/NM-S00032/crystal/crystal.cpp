#include <bits/stdc++.h>
using namespace std;
long long n;
long long m, arr[500005], d[500005] = {0};
long long sumd(long long s, long long t) {
    return (d[t] - d[s - 1]) - s * (arr[t] - arr[s - 1]);
}
long long bs(long long idx) {
    long long l = 1, r = idx, mid, ans = idx;
    while (l <= r) {
        mid = l + (r - l) / 2;
        long long res = sumd(mid, idx);
        if (res > m) {
            l = mid + 1;
            // cout << "l " << mid << endl;

        }
        else {
            r = mid - 1;
            ans = min(ans, mid);
            // cout << "r " << ans << " " << mid << endl;
        }
    }
    return ans;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
        cin >> arr[i];
	}
	sort(arr + 1, arr + 1 + n);
	for (int i = 1; i <= n; i++) {
        d[i] = (arr[i] - arr[i - 1]) * (i) + d[i - 1];
	}
	long long ans = 1;
	for (int i = 2; i <= n; i++) {
        ans = max(i - bs(i) + 1, ans);
	}
	cout << ans;
	return 0;
}
