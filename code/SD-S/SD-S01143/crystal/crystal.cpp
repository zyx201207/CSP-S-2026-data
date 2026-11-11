#include <cstdio>
#include <algorithm>

const int Maxn = 5e5 + 5;

int max(int x, int y) {
	return x > y ? x : y;
}

void Read(long long &num) {
	num = 0;
	char ch = getchar();
	long long lve = 1;
	while (ch < 48 || ch > 57) {
		if (ch == '-')
			lve = -1;
		ch = getchar();
	}
	while (ch >= 48 && ch <= 57) {
		num = (num << 3) + (num << 1) + (ch ^ 48);
		ch = getchar();
	}
	num *= lve;
}

int n;
long long m, a[Maxn];
long long pre[Maxn];

bool Check(int l, int r) {
	return (a[l] * (long long)(r - l + 1) - pre[r] + pre[l - 1]) <= m;
}

int l, r, mid, res;

int Count(int k) {
	res = l = k;
	r = n;
	while (l <= r) {
		mid = l + r >> 1;
		if (Check(k, mid)) {
			res = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}
	return res - k + 1;
}

int ans;

int main(void) {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d", &n);
	Read(m);
	for (int i = 1; i <= n; ++i)
		Read(a[i]);
	std::sort(a + 1, a + n + 1, [&] (long long x, long long y) {
		return x > y;
	});
	for (int i = 1; i <= n; ++i)
		pre[i] = pre[i - 1] + a[i];
	for (int i = 1; i <= n; ++i)
		ans = max(ans, Count(i));
	printf("%d", ans);
	return 0;
}
