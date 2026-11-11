#include <bits/stdc++.h>
using namespace std;
int a[20000001];

string  zh(int a, int n) {
	string t;
	for (int i = n; i >= 1; i++) {
		t = t + char(a % n);
		a = a / 10;
	}
	return t;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, c;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == a[i]) {
			c = a[i];
		}
	}
	cout << c;
	return 0;
}