#include <bits/stdc++.h>
using namespace std;
int n, ans;
int a;
char b;
string x;

int d(string a) {
	long long e = x.size(), s = 0;
	for (long long i = 0; i < e / 2; i++) {
		if (a[i] != a[e - 1 - i])
			s++;
	}
	return s;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		for (int j = 1; j <= a; j++) {
			x += b;
		}
	}
	ans = d(x);
	cout << ans;
	return 0;
}