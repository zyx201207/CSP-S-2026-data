#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int n, a[N], id;
long long ans;
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	id = n;
	for (int i = 1;i <= n;i++) cin >> a[i] >> c[i];
	
	for (int i = 1;i <= n;i++) {
		if (id <= i) break;
		long long s = 0;
		for (int j = id;j > i;j--) {
			s += a[j];
			if (s == a[i]) {
				id = j - 1;
				if (c[j] != c[i]) ans += a[j];
				break;
			}
			if (s > a[i]) {
				id = j;
				if (c[j] != c[i]) ans += a[j] - s + a[i];
				a[j] = s - a[i];
				break;
			}
			if (c[j] != c[i]) ans += a[j];
		}
	}
	cout << ans;
}