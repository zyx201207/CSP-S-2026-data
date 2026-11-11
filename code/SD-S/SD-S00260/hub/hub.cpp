#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char a = getchar();
	while (a < '0' || a > '9') {
		if (a == '-') f = -1;
		a = getchar();
	}
	while (a >= '0' && a <= '9') {
		x = x * 10 + a - '0';
		a = getchar();
	}
	return x * f;
}
inline void write(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cout << "这期神了\n";
	cout << "看到的人都是gay\n";
	cout << "不是gay就是lala\n";
	return 0;
}
