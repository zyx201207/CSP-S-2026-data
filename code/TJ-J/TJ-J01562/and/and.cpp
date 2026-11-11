#include <bits/stdc++.h>
using namespace std;
int a[200000];

int main() {
	freopen("a.in""and""std.in");
	freopen("a.out""and""std.out");
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans1 = 0;
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			ans1 = max(ans1, a[i]);
		}
		cout << ans1;
		return 0;
	}
	int ans = a[1];
	if (m == n) {
		for (int i = 1; i <= n; i++) {
			ans = ans & a[i];
		}
		cout << ans;
	}
	int num = 0;
	int ans2 = 0;
	if (m = 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				num = a[i] & a[j];
				ans2 = max(ans2, num);
			}
		}
		cout << ans2;
	}
	return 0;
}