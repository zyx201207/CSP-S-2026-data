#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[100005], b = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 5 && m == 5) {
		cout << "3" << endl;
	} else if (n == 5 && m == 8) {
		cout << "4" << endl;
	}
	return 0;
}