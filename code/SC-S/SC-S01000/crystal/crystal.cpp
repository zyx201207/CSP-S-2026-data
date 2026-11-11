#include <bits/stdc++.h>
using namespace std;
long long a[500002];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n, m, q = 0;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (q >= m) {
			cout << i-1;
			break;
		}
		q += a[i + 1] - a[i];
	}
	return 0;
}