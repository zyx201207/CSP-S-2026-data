#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005], b[500005], ans[300005];

long long find(int k) {
	for (int i = 1; i <= n; i++) {
		if (b[i] == k)
			return i;
	}
	return -1;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (long long i = 1; i <= n; i++) {
		b[1] = a[i];
		for (long long j = i; j <= n; j++) {
			int x = 1;
			if (find(b[i]) > 0) {
				int k = find(b[i]);
				for (int d = k; d <= j; d++) {
					b[d] = b[d + (j - k) + 1];
				}
			}
			b[x] = a[j];
			x++;
		}
		for (int i = 1; i <= n; i++) {
			ans[b[i]]++;
			b[i] = 0;
		}
	}
	for (long long i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}