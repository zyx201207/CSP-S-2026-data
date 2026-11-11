#include <bits/stdc++.h>
using namespace std;
long long n, m, a[1000000], s = 0, t = 0;
int q = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++) {
		t = 0;
		for (int j = 1; j <= i; j++) {
			t += a[i] - a[j];
			if (t > m) {
				s = i - 1;
				q = 1;
				break;
			} else if (i > s)
				s = i;
		}
		if (q == 1)
			break;
	}
	cout << s;
	return 0;
}
