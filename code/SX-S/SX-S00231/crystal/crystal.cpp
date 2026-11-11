#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5+10;
int a[N];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	cin >> n;
	int m;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		int s = 0;
		int mx = a[i];
		for (int j = i; j <= n; j++) {
			s += mx - a[j];
		}
		if (s <= m) {
			cout << n - i + 1;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
