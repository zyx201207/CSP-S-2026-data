#include <bits/stdc++.h>

using namespace std;

const int N = 501000;

int n, q[N];
long long m, sum[N], a[N], maxn[N];

bool check(int x) {
	int head = 1, tail = 0;
	q[head] = 0;
	for (int i = 1; i <= n; i++) {
		while (head <= tail && i - q[head] + 1 > x) head++;
		while (head <= tail && a[i] >= a[q[tail]]) tail--;
		q[++tail] = i;
		if (i >= x) maxn[i] = a[q[head]];
	}
	long long minn = 1ll << 59;
	int p = 0;
	for (int i = x; i <= n; i++) {
		long long t = maxn[i] * 1ll * x - (sum[i] - sum[i - x]);
		if (minn > t) {
			minn = t;
		}
	}
	if (minn <= m) return true;
	return false;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int l = 1, r = n, ans = 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	printf("%d\n", ans);
	return 0;
} 
