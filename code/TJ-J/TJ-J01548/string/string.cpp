#include <bits/stdc++.h>
using namespace std;
char x[200010];
long long n, a[200010], ans = 0;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> x[i];
	}
	long long num = n + 1;
	for (int i = 1; i <= n / 2; i++) {
		if (x[i] != x[num - i]) {
			ans += min(a[i], a[num - i]);
		}
		if (a[i] > a[num - i]) {
			a[i] -= a[num - i];
			i--, num--;
		} else if (a[i] < a[num - i]) {
			a[num - i] -= a[i];
			num++;
		}
	}
	cout << ans;
	return 0;
	//zmh
}