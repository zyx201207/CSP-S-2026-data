#include <cstdio>
#include <algorithm>

int read() {
	int num = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		num = num * 10 + (c & 15), c = getchar();
	}
	return num;
}

long long lread() {
	long long num = 0;
	char f = 1, c = getchar();
	while (c < '0' || c > '9') {
		f = c ^ '-', c = getchar();
	}
	while (c >= '0' && c <= '9') {
		num = num * 10 + (c & 15), c = getchar();
	}
	return (f ? num : -num);
}

int n;
long long K, a[500000], pre[500001];

void init() {
	n = read(), K = lread();
	for (int i = 0; i < n; i ++) {
		a[i] = lread();
	}
	std::sort(a, a + n);
	for (int i = 0; i < n; i ++) {
		pre[i + 1] = pre[i] + a[i];
	}
	return;
}

void calculate() {
	int ans = 0, ind = 0;
	for (int i = 0; i < n; i ++) {
		while (1ll * (i - ind) * a[i] - pre[i] + pre[ind] > K) {
			ind ++;
		}
		if (ans < i - ind + 1) {
			ans = i - ind + 1;
		}
	}
	printf("%d\n", ans);
	return;
}

void solve() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	init(), calculate();
	return;
}

int main() {
	solve();
	return 0;
}