#include <bits/stdc++.h>
using namespace std;
int a[500010];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n, m, maxx = INT_MIN;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {

		if (a[i] > maxx) {
			maxx = a[i];

			if (m > maxx) {
				cout << 4;
				break;
			} else {
				if ((a[2] - a[1]) + (a[2] - a[0]) <= m) {
					cout << 3;
					break;
				}
			}
		}
	}

	return 0;
}
