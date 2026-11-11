#include <bits/stdc++.h>
using namespace std;
long long n, m, a[202020], mx;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		long long w = m, ls = 1;
		for (int j = i - 1; j > 0; j--) {
			if (w < a[i] - a[j])
				break;
			w -= a[i] - a[j];
			ls++;
		}
		mx = max(mx, ls);
	}
	cout << mx;
	
	return 0;
}