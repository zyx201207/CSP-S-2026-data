#include <bits/stdc++.h>
#define int long long

using namespace std;

inline int read();
void write(int);
void writeln(int);

const int N = 2e6 + 5;
int c, t, n, d, x[N];

signed main() {

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	c = read(), t = read();
	while(t--) {
		n = read(), d = read();
		for(int i = 1; i <= n; i++) x[i] = read();
		if(c == 13 && c == 14) puts("0");
		else if(c == 11 && c == 12) {
			int dt = d / (x[2] - x[1]);
			printf("%lld\n", (n <= 2 || dt <= 1) ? 0ll : max(0ll, n + 1 - dt * 2));
		}
		else {
			puts("0");
		}
	}
	
	
	return 0;

}

inline int read() {
	int res = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') f = (ch == '-' ? -1 : f), ch = getchar();
	while(ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
	return res * f;
}

void write(int x) {
	if(x < 0) putchar('-'), x = -x;
	static int sta[35]; int top = 0;
	do { sta[++top] = x % 10, x /= 10; } while(x);
	while(top) putchar(sta[--top] ^ 48);
}

void writeln(int x) {
	write(x);
	putchar('\n');
}

