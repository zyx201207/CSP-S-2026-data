#include <bits/stdc++.h>
using namespace std;
int n;
long long m, a[600000], b[600000], c = 0, d, e = 0, num = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	scanf("%d%lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &d);
		a[i] = d;
	}
	sort(a, a + n);
	d = 0;
	b[0] = 0;
	for (int i = 1; i < n; i++) {
		d++;
		num = max(d, num);
		b[i] = (a[i] - a[i - 1]) * (i - c);
		e += b[i];
		if (e > m) {
			d = 0;
			while (e > m) {
				e -= a[i] - a[c];
				c++;
			}
		}
	}
	printf("%lld", num);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
