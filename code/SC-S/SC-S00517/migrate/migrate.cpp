#include <cstdio>

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

void write(unsigned long long x) {
	char buf[20], len = 0;
	while (x || !len) {
		buf[len ++] = x % 10, x = x / 10;
	}
	while (len --) {
		putchar(buf[len] | 48); 
	}
	putchar('\n');
	return;
}

int n, lft[2000000], rgt[2000000], lft_cnt[2000000], rgt_cnt[2000000];
long long a[2000000], K;

void init() {
	n = read(), K = lread();
	for (int i = 0; i < n; i ++) {
		a[i] = lread();
	}
	int ind = 0;
	for (int i = 0; i < n; i ++) {
		while (ind < n && a[ind] - a[i] <= K) {
			ind ++;
		}
		rgt[i] = ind - 1;
	}
	ind = n - 1;
	for (int i = n - 1; ~i; i --) {
		while ((~ind) && a[i] - a[ind] <= K) {
			ind --;
		}
		lft[i] = ind + 1;
	}
	for (int i = 0; i < n; i ++) {
		lft_cnt[i] = rgt_cnt[i] = 1;
	}
	for (int i = 0; i < n; i ++) {
		if ((rgt[i] ^ i) && lft[rgt[i]] < i) {
			lft_cnt[rgt[i]] ++;
		}
		if ((lft[i] ^ i) && rgt[lft[i]] > i) {
			rgt_cnt[lft[i]] ++;
		}
	}
	for (int i = 0; i < n; i ++) {
		if ((lft[i] ^ i) && rgt[lft[i]] == i) {
			lft_cnt[i] += lft_cnt[lft[i]];
		}
	}
	for (int i = n - 1; ~i; i --) {
		if ((rgt[i] ^ i) && lft[rgt[i]] == i) {
			rgt_cnt[i] += rgt_cnt[rgt[i]];
		}
	}
	return;
}

void calculate() {
	unsigned long long ans = 0;
	for (int i = 2; i < n - 1; i ++) {
		if (lft[i] >= i - 1 || rgt[i - 1] <= i) {
			continue;
		}
		bool p = (rgt[lft[i - 1]] == i), q = (lft[rgt[i]] == i - 1);
		int a = lft_cnt[lft[i - 1]], b = rgt_cnt[rgt[i]], c = lft[i + 1] - lft[i] - p, d = rgt[i - 1] - rgt[i - 2] - q;
		if (p && q) {
			ans += 1llu * a * b;
		}
		if (p) {
			ans += 1llu * a * d;
		}
		if (q) {
			ans += 1llu * c * b;
		}
		ans += 1llu * c * d;
	}
	write(ans);
	return;
}

void solve() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	read();
	int T = read();
	while (T --) {
		init(), calculate();
	}
	return;
}

int main() {
	solve();
	return 0;
}