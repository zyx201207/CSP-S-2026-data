#include <bits/stdc++.h>
using namespace std;
int n, m, a[210000], ans;

bool cmp(int n, int m) {
	return n > m;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a, a + n + 1, cmp);
	int tot = a[1];

	for (int i = 2; i <= m; i++) {

		tot = tot & a[i];
	}

	cout << tot;

}
