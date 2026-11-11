#include <bits/stdc++.H>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	int a[200005];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans[10005] = {};
	for (int i = 1; i <= n; i++) {
		int s[200005] = {};
		for (int j = i; j <= n; j++) {
			s[j] = a[j];
			for (int t = i; t <= j - 1; t++) {
				if (s[t] == s[j]) {
					for (int d = t; d < j; d++) {
						s[d] = 0;
					}
				}
			}
		}
		for (int j = i; j <= n; j++) {
			ans[s[j]]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 0) {
			continue;
		}
		cout << ans[i] << " ";
	}
	return 0;
}