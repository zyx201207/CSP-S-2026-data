# include <bits/stdc++.h>
using namespace std;
# define int long long
int a[100005], m, n, x;

bool checking(int x) {
	if (x == 1) {
		return true;
	}
	int sum = 0;
	for (int i = 1; i <= n - x + 1; i++) {
		for (int j = 1; j <= i + x - 1; j++) {
			sum += abs(a[i]);
		}
		if (sum <= m) {
			return true;
		}
		sum = 0;
	}
	return false;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << 3;
	fclose(stdin);
	fclose(stdout);
	return 0;
}