#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[100001];

int main() {
	int c = -1;
	int b;
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; i++) {

		cout << "opp" << endl;

		for (int j = i + 1; j <= n; j++) {

			b = a[i] & a[j];
			c = max(b, c);
			cout << a[i] << ' ' << a[j] << ' ' << c << endl;

		}
	}


	cout << c;

	return 0;
}