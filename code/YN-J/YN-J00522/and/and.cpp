#include <bits/stdc++.h>
using namespace std;
int n, m, b, u = 0;
vector<int>a;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	cin >> n >> m;
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	for (int i = 0; i < n; i++) {
		cin >> b;
		a.push_back(b);

	}
	sort(a.begin(), a.end(), cmp);
	int c = a[0];
	for (int i = 1; i < m; i++) {
		c = c & a[i];
	}
	if (m == 2) {
		for (int i = 1; i < a.size(); i++) {
			if (a[i] == a[i - 1]) {
				u = a[i] & a[i];
				break;
			}
		}
	}

	cout << max(u, c);
	return 0;
}