#include <bits/stdc++.h>
using namespace std;
int c, t, n, d;
const int N = 2e6 + 5;
int nums[N];
int cnt[N];

void solve(int idx) {
	if (idx >= n) return;
	cnt[idx]++;
	for (int i = 1; i <= d; ++i) {
		int a = i, b = 0;
		while (i + b < n && a > 0) {
			b++;
			a -= nums[idx + b] - nums[idx + b - 1];
		}
		solve(idx + b);
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 
	cin >> c >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n >> d;
		for (int j = 0; j < n; ++j) {
			cin >> nums[j];
		}
		solve(0);
		int cc = 0;
		for (int j = 0; j < n; ++j) {
			if (cnt[j] == 2) {
				cc++;
			}
		}
		cout << cc << endl;
	}
	return 0;
}
