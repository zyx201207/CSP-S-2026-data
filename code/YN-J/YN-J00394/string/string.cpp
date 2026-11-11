#include <bits/stdc++.h>
using namespace std;

struct Node {
	int a;
	char b;
} f[1001];

int main() {
	freopen("string.in", "r", stdout);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int c = 0;
	for (int i = 1; i <= n; i++) {
		cin >> f[i].a >> f[i].b;
		c += (f[i].a % 2);
		c = c % 2;
	}
	int i = 1;
	int o = n;
	long long ans = 0;
	for (; 1;) {
		if (i >= n)
			break;
		if (f[i].b != f[o].b) {
			ans += min(f[i].a, f[o].a);
		}
		if (f[o].a >= f[i].a)
			i++;
		else
			o--;
	}
	if (c == 1 && ans != 0)
		ans--;
	cout << ans;
	return 0;
}
/*
3 1000000 a 1000000 a 1000000 b


*/