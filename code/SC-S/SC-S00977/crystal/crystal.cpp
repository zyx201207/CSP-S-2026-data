#include<bits/stdc++.h>
using namespace std;
long long Read() {
	long long x = 0, f = 1;
	char c;
	c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x*f;
}
const int N = 5e5+5;
long long n, m, a[N], ans = 1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = Read();
	m = Read();
	for (int i = 1; i <= n; i++) {
		a[i] = Read();
	}
	sort(a + 1, a + n + 1);
	long long l = 1, sum = 0;
	for (int i = 2; i <= n; i++) {
		sum += (i - l) * (a[i] - a[i - 1]);
		while (sum > m && l <= i) {
			sum -= (a[i] - a[l]);
			l++;
		}
		if (i >= l)
			ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}