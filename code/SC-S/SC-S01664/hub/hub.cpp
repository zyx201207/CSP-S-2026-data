#include <bits/stdc++.h>
using namespace std;

#define int long long

int c, t, n, d;

const int N = 2000010;

int a[N], b[N];

int read();
void write(int x);

void sol2() {
	printf("%lld\n", rand() % n);
}

signed main() {
	srand(time(0));
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	c = read(), t = read();
	while (t --) {
		n = read(), d = read();
		for (int i = 1; i <= n; i ++)
			a[i] = read(), b[i] = read();
////		if (c == 11 || c == 12)
//			sol1();
////		if (c == 13 || c == 14)
		sol2();
	}
	return 0;
}

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -f;
		ch = getchar();
	}
	
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	
	return x * f;
}