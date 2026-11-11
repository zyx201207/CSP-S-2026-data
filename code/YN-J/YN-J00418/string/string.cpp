#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.string", "r", stdin);
	freopen("out.string", "w", stdout);
	int n, m;
	int a[n + 1];
	char b[n + 1];
	string q;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> b[i];
	}
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j <= a[i]; j++) {
			q = q + b[i];
		}
	}
	for (int i = 0; i <= q.size() / 2 - 1; i++) {
		if (q[0] != q[q.size() - 1 - i]) {
			m++;
		}
	}
	cout << m;
}