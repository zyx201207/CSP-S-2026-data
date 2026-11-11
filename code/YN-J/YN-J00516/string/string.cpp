#include <bits/stdc++.h>
using namespace std;
int n, x, t = 0;
char a;
string q, p;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> a;
		for (int j = 1; j <= x; j++) {
			q += a;
		}
	}
	for (int i = int(q.size()) - 1; i >= 0; i--) {
		p += q[i];
	}
	if (p == q)
		cout << '0';
	else {
		for (int i = 0; i < int(q.size()) / 2; i++) {
			if (p[n - i - 1] != q[i]) {
				p[n - i - 1] = q[i];
				t++;
			}
		}
		cout << t;
	}
	return 0;
}