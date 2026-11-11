#include <iostream>
#include <algorithm>
using namespace std;
int a[200005];
bool cmp(int x, int y) {
	return x > y;
}
int ans = -1;
bool is_used[200005];
int n, m;
void dfs(int step) {
	int value, first = 1;
	if (step == m + 1) {
		for (int i = 0; i < n; i++) {
			if (is_used[i]) {
				if (first == 1) {
					value = a[i];
					first = 0;
				}
				value = value & a[i];
			}
		}
		ans = max(ans, value);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!is_used[i]) {
			is_used[i] = 1;
			dfs(step + 1);
			is_used[i] = 0;
		}
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	bool is_B = true;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] >= 4) is_B = false;
	}
	
	if (m == 1) {
		sort(a, a + n, cmp);
		cout << a[0];
		return 0;
	}
	if (m == 2) {
		int out = -1;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int value = a[i] & a[j];
				out = max(out, value);
			}
		}
		cout << out;
		return 0;
	}
	if (m == n) {
		int out = 0x7fffffff;
		for (int i = 0; i < n; i++) {
			out = out & a[i];
		}
		cout << out;
		return 0;
	}
	if ((n & (n - 1)) == 0) {
		int out = 0x7fffffff;
		if (m <= n / 2) {
			for (int i = 0; i < m; i++) {
				out = out & a[i];
			}
			cout << out;
			return 0;
		}
		cout << 0;
		return 0;
	}
	if (is_B) {
		int cnt[4] = {};
		for (int i = 0; i < n; i++) {
			cnt[a[i]]++;
		}
		if (m <= cnt[3]) {
			cout << 3;
			return 0;
		}
		if (m <= (cnt[3] + cnt[2])) {
			cout << 2;
			return 0;
		}
		if (m <= (cnt[3] + cnt[1])) {
			cout << 1;
			return 0;
		}
		cout << 0;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}