#include <bits/stdc++.h>
using namespace std;
int a[200010];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	int ans, maxi = INT_MIN;
	while (n--) {
		for (int i = 1; i <= m; i++) {
			ans = a[i] & a[i];
		}
		if (ans > maxi) {
			maxi = ans;
		}
	}
	cout << maxi;
	return 0;
}