#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {

		cin >> a[i];
	}

	if (n == 1) {
		cout << "1";
		return 0;
	}

	sort(a, a + n );
	int i = 1;

	while (s <= m) {
		s = s + (a[i] - a[i - 1]) * i;
		i++;
	}

	cout << i - 1;

	return 0;
}
