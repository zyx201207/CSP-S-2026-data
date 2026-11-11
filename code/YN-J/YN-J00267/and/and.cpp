#include <bits/stdc++.h>
using namespace std;
int a[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, ma = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > ma)
			ma = a[i];
	}
	int yy = a[1];
	for (int i = 2; i <= n; i++) {
		yy = yy & a[i];
	}
	if (m == 1)
		cout << ma;
	else if (m == n)
		cout << yy;
	else if (m == 2) {
		int am = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)
					continue;
				if ((a[i] & a[j]) > am)
					am = a[i] & a[j];
			}
		}
		cout << am;
	} else
		cout << (a[1] & a[2]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}