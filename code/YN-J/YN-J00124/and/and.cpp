#include <bits/stdc++.h>
using namespace std;
long long a[200005];
bool n2[200005];
long long n, m, ans = -2147483648;

void choose(long long num) {
	if (num == m) {
		long long q = 1073741823;
		for (int i = 0; i <= n; i++) {
			if (!n2[i]) {
				q = (q & a[i]);
			}
			if (q == 0)
				return;
		}
		if (ans < q)
			ans = q;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (n2[i]) {
			n2[i] = false;
			choose(num + 1);
			n2[i] = true;
		}
	}
	return;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 0; i < 200005; i++)
		n2[i] = true;
	for (long long i = 1; i <= n; i++)
		cin >> a[i];
	choose(0);
	cout << ans;
	return 0;
}