#include <bits/stdc++.h>
#define int long long

using namespace std;

inline int read();
void write(int);
void writeln(int);

const int N = 5e5 + 5;
int n, m, a[N], l, r, s[N];
int check(int p) {
	for(int i = 1; i <= n - p + 1; i++) {
		int sum = s[i + p - 1] - s[i - 1];
		if(a[i + p - 1] * p - sum <= m) return 1;
	}
	return 0;
}

signed main() {
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	n = read(), m = read(), l = 1, r = n;
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	while(l <= r) {
		int mid = l + r >> 1;
		if(check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld\n", r);
	
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
