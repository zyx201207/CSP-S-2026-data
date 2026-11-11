#include <bits/stdc++.h>

using namespace std;

int c[50];
int n, m, ans, a[200011];
bool ok[200011];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		int x = a[i];
		int b = 0;
		while (x) {
			if (x & 1) 
				c[b]++;
			x /= 2;
			++b;
		}
	}
	for (int i = 31; i >= 0; i--) {
		//cout << c[i] << endl;
		if (c[i] >= m) {
			for (int j = 1; j <= n; j++) {
				if (ok[j])
					continue;
				if (!(a[j] & (1 << i)))
					ok[j] = true;
			}
			ans += 1 << i;
		}
		memset(c, 0, sizeof(c));
		for (int j = 1; j <= n; j++) {
			if (ok[j])
				continue;
			int x = a[j];
			int b = 0;
			while (x) {
				if (x & 1) 
					c[b]++;
				x /= 2;
				++b;
			}
		}
	}
	printf("%d\n", ans);
}