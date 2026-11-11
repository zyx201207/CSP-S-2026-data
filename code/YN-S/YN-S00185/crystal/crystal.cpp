#include <bits/stdc++.h>
using namespace std;
int a[10000];

int main() {
	freopen("stytal.in", "r", stdin);
	freopen("stytal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i <= m; i++) {

		if (a[i] <= m) {

			a[i]++;
		}
		cout << a[i] + m - n << endl;

	}

	return 0;
}