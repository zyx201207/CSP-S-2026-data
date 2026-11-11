#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w", stdout);
	int n, m;
	map<int, int> a;
	int qian[500001] = {0};
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> qian[i];
	}
	sort(qian + 1, qian + n + 1);
	for (int i = 1; i <= n; i++) {
		a[i] = qian[i];
	}
	for (int i = 1; i <= n; i++) {
		qian[i] = a[i] + qian[i - 1];
	}
	int l = 1, r = 1;
	int ans = 1; 
		while(l <= r && r < n) {
			if (a[r + 1] * (r - l + 1) - (qian[r] - qian[l - 1]) <= m) {
				
				r++;
				ans = max(ans, r - l + 1);
			} else {
				if (l + 1 <= r) {
					l++;
				} else {
					l++;
					r++;
				}
			}
		}
	cout << ans;
	return 0;
}