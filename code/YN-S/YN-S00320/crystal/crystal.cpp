#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500010], c[500010], li[500010], cnt[500010];
bool flag = 0;

long long er(long long l, long long r) {

	if (l >= r) {
		return l + 1 ;
	}

	long long mid = (l + r) / 2;

	if (m >= li[mid]) {
		return er(mid + 1, r);
	} else {
		return er(l, mid);
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	for (int i = 1; i < n; i++) {

		c[i] = a[i + 1] - a[i];
		cnt[i] = cnt[i - 1] + c[i];
	}

	for (int i = 2; i < n; i++) {

		if (c[i] != c[i - 1]) {
			flag = 1;
			break;
		}
	}

	for (int i = 1; i < n; i++) {

		li[i] = li[i - 1] + c[i] * i;
	}

	long long maxx = 0;

	for (int i = 1; i <= n; i++) {

		maxx = max(er(i, n - 1) - i, maxx);

		if (flag == 0) {
			break;
		}


		for (int j = i + 1; j < n; j++) {

			li[j] = li[j] + cnt[i - 1] - cnt[j];
		}
	}

	cout << maxx;
	return 0;
}
