#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	for (int b = 29; b >= 0; b--) {
		int mask = ans | (1 << b), cnt = 0;
		for (int x : a)
			if ((x & mask) == mask)
				cnt++;
		if (cnt >= m)
			ans = mask;
	}
	cout << ans << "\n";
	return 0;
}