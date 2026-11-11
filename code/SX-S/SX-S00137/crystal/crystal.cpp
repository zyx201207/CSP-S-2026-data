#include <bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500000], b[500000];
long long sum, ans, s;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i > 1; i--) {
		sum = 0;
		ans = 0;
		for (int j = i - 1; j > 0; j--) {
			sum += a[i] - a[j];
			ans++;
			//cout << a[i] << "-" << a[j] << "=" << a[i] - a[j] << " ";
			if (sum > m) {
				ans--;
				break;
			}
		}
		//cout << sum << " " << ans << '\n';
		b[i] = ans + 1;
	}
	//cout << '\n';
	for (int i = 1; i <= n; i++) {
		if (s <= b[i])
			s = b[i];
	}
	cout << s;
	return 0;
}
