#include <iostream>
using namespace std;

const int MAXN = 2e6 + 5;
int c, t;
int n, ans;
long long d, x[MAXN];

int find(long long a) {
	int l = 0, r = n + 1, mid = 0;
	while (l < r) {
		mid = (l + r) >> 1;
		if (x[mid] > a) r = mid;
		else l = mid + 1;
	}
	return r - 1;
}

long long read() {
	long long res = 0;
	bool st = false;
	char c;
	
	c = getchar();
	while (c != '-' && c < '0' && c > '9') c = getchar();
	if (c == '-') st = true, c = getchar();
	while (c >= '0' && c <= '9') res = res * 10 + c - '0', c = getchar();
	
	if (st) return -res;
	return res;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	c = read(), t = read();
	while (t--) {
		ans = 0;
		n = read(), d = read();
		for (int i = 1; i <= n; i++) x[i] = read();
		x[0] = -0x7fffffffffffffff, x[n+1] = 0x7fffffffffffffff;
		
		for (int i = 1; i <= n - 3; i++) {
			int k1 = min(n, find(x[i] + d)); // 只能 i -> k1-1 & k1 -> (k3+1 ~ k2)，不能 i -> k1-2 -> k3
			if (k1 >= i + 2) {
				int k2 = min(n, find(x[k1 - 1] + d)), k3 = min(n, find(x[k1 - 2] + d));
				ans += max(0, (k2 - max(k1, k3)));
			}
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}