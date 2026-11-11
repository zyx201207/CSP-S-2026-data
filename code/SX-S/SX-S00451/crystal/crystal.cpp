#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.in", "w", stdout);
	int n, a[50005] = {0}, b[50005] = {0};
	long long m;
	scanf("%d %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);

	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (a[i] - a[i - 1] < 0)
			b[i] =  a[i - 1] - a[i] ;
		else
			b[i] = a[i] - a[i - 1];
	}
	int mx = -1;
	for (int i = 1; i < n - 1; i++) {
		int j = 1, p = i;
		long long zong = 0;
		while (zong < m) {
			zong = zong + b[p] * j;
			p++;
			j++;
			if (zong == m) {
				int o = 1;
				while (1) {
					if (a[p + o - 1] == a[p - 1])
						o++;
					else
						break;

				}
				if (p - i + o > mx)
					mx = p - i + o ;
			}
			if (p == n)
				break;
		}
	}
	cout << mx ;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
