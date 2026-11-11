#include <bits/stdc++.h>
using namespace std;
int n, m;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int mx = -1;
	for (int i = 0; i < n; i++) {
		b[i] = a[i + 1] & a[i];
		mx = max(mx, b[i]);
	}
	cout << mx;
	return 0;
}

