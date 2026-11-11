#include <bits/stdc++.h>
using namespace std;
int a[200002];
string c[2000002];
string b = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string zh2(int n) {
	string s;
	if (n == 0) {
		return "0";
	}
	while (n != 0) {
		s = b[n % 2] + s;
		n /= 2;
	}
	return s;
}

int zhs(string s, int jz) {
	int n = 0;
	int wq = 1;
	for (int i = 0; i < s.size(); i++) {
		n = n * 10 + (s[i] - 48) * wq;
	}
	wq *= jz;

	return n;
}

#define int long long
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		c[i] = zh2(a[i]);
	}
	int zd = 0;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			for (int j = 1; j <= c[i].size(); j++) {
				string t;
				if (c[i][j] == '1' && c[k][j] == '1') {
					t += '1';
				} else {
					t += '0';
				}
				int a = zhs(t, 2);
				if (a >= zd) {
					zd = a;
				}
			}
		}
	}
	cout << zd;




	return 0;
}
