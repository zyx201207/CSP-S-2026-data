#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, m, nums[MAXN], ans;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	for (int j = 29; j >= 0; j--) {
		sort(nums + 1, nums + n + 1, greater<int>());
		if (nums[m] & (1 << j)) {
			for (n = m + 1; ; n++) {
				if (!(nums[n] & (1 << j))) {
					break;
				}
			}
			n--;
			ans |= (1 << j);
		} else {
			for (int i = 1; i <= n; i++) {
				nums[i] &= ((1 << j) - 1);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
