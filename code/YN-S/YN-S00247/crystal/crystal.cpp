#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
long long n, m, a[maxn], midnum, type;
long long b[maxn], c[maxn];
long long sum, ans, num, cnt = 1, n1, n2;

bool cmp(long long a, long long b) {
	return a > b;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	double mid = (double)sum / n;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] <= mid && a[i + 1] >= mid) {
			midnum = a[i];
			type = i;
			break;
		}
	}
	long long numm = 1;
	long long cnt = 0;
	for (int i = 1; i <= n; i++) {
		if ((a[i] - midnum) >= 0) {
			numm++;
			b[numm] = a[i] - midnum;
		} else {
			cnt++;
			c[cnt] = a[i] - midnum;
		}
	}
	n1 = cnt;
	n2 = numm;
	sort(c + 1, c + cnt + 1, cmp);
	sort(b + 1, b + numm + 1);
	cnt = 1;
	numm = 1;
	while (num < m) {
		if (b[numm] > abs(c[cnt])) {
			type++;
			cnt++;
			num += (type - 1) * (a[type] - midnum) ;
			midnum = a[type];
			ans++;
		} else {
			num += b[numm];
			ans++;
			numm++;
		}
	}
	cout << ans;
	return 0;
}