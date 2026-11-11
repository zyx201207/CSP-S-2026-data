#include <bits/stdc++.h>
using namespace std;
long long a[500050], b[500050];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	long long sum = 0, ans = 1, cnt = 0;
	cin >> n >> m;
	for (int i = 1;  i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		b[i] = a[i] - a[i - 1];
		sum = sum + ans * b[i];
		ans ++;
		while (sum > m) {
			for (int j = 1; j < ans; j++) {
				sum -= b[i - j + 1];
			}
			ans--;
		}
		cnt = max(cnt, ans);
	}
	cout << cnt;
	return 0;
}