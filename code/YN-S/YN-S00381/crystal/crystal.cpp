#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], b[500005];
long long zh = 0, pj = 0, js = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		zh += a[i];
	}
	while (zh - n > 0) {
		zh -= n;
		pj++;
	}
	int s = 0;
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (a[i] == a[i + 1]) {
			s++;
		} else {
			s = 1;
		}
	}
	int minn = a[0], minp = 0;
	if (a[0] >= pj) {
		minp = a[0] - pj;
	} else {
		minp = pj - a[0];
	}
	for (int i = 1; i < n; i++) {
		if (a[i] >= pj) {
			if (a[i] - pj < minp) {
				minp = a[i] - pj;
				minn = a[i];
			}
		} else {
			if (pj - a[i] < minp) {
				minp = pj - a[i];
				minn = a[i];
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		if (a[i] <= minn and m >= 0) {
			if (m - (minn - a[i]) >= 0) {
				js += 1;
				m -= minn - a[i];
			}
		}
	}
	printf("%d", js);

	return 0;
}