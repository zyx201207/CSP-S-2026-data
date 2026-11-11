#include <bits/stdc++.H>
using namespace std;

long long zhuan(long long x) {
	long long y = 0;
	while (x) {
		int i = 1;
		y += x % 2 * i;
		x /= 2;
	}
	return y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long s[100005];
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		long long a;
		cin >> a;
		s[i] = zhuan(a);
	}
	long long ans;
	sort(s + 1, s + 1 + n);
	ans = s[n];
	while (--m) {
		n--;
		ans = ans && s[n];
	}
	int a = 1, sum = 0;
	while (ans) {
		sum = ans % 10 * a;
		a *= 2;
		ans /= 10;
	}
	cout << sum;
	return 0;
}