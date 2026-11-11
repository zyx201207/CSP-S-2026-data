#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll m, a[500050], cj[500005], sum1[500005], sum2[500005], gd, ans;
int n;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	ans = m + 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++) {
		cj[i] = a[i + 1] - a[i];
	}
	for (int i = 1; i < n; i++) {
		sum1[i] = i * cj[i] + sum1[i - 1];
		sum2[i] = cj[i] + sum2[i - 1];
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= n - 1 - i; j++) {
			gd = sum1[j + i - 1] - sum1[j - 1] - (j - 1) * (sum2[j + i - 1] - sum2[j - 1]);
			ans = min(ans, gd);
		}
		if (ans <= m) {
			cout << i + 1;
			return 0;
		}
	}
}