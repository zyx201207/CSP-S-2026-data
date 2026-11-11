#include <bits/stdc++.h>
using namespace std;
long long m, a[500005], s[500005], ans;
int n;

int main() {
	freopen("ctystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		s[i] = a[i] - a[i - 1];
		//	cout << s[i] << endl;
	}
	for (int i = 2; i <= n; i++) {
		if (m < s[i])
			break;
		m -= s[i] * i;
		ans = i;
	}
	for (int i = ans + 1; i <= n; i++) {
		if (a[i] == a[ans])
			ans++;
	}
	cout << ans;
	return 0;
}