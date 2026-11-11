#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e5 + 5;

int n, ans;
long long m, a[N], pre[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i ++ ) {
		pre[i] = pre[i - 1] + a[i];
	}
	
	for (int i = 1; i <= n; i ++ ) {
		int l = 1, r = i - 1, pos = i;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (a[i] * (long long)(i - mid) - (pre[i - 1] - pre[mid - 1]) <= m) {
				r = mid - 1;
				pos = mid;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - pos + 1);
	}
	
	cout << ans << "\n";
	
	return 0;
}
