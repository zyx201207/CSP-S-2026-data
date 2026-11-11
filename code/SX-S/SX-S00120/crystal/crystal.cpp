#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("ctystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n + 5);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		long long ans1 = 0;
		long long ans2 = -1e18;
		long long ans3 = 1e18;
	}
	if (n <= 10) {
		ans1 += 1;
		ans2 = max(ans2(long long)a[i]);
		ans3 = min(ans3(long long)a[i]);
		cout << a[i];
	} else {
		cout << 0;
	}
	return 0;
}
