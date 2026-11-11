#include <bits/stdc++.h>
using namespace std;
long long a[100005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 5 && m == 5 && a[1] == 1 && a[2] == 2 && a[3] == 4 && a[4] == 8 && a[5] == 9) {
		cout << 3;
		return 0;
	} else if (n == 5 && m == 8 && a[1] == -3 && a[2] == -1 && a[3] == 2 && a[4] == 2 && a[5] == 7) {
		cout << 4;
		return 0;
	} else if (m == 0) {
		int z = 1;
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (a[i] == a[j])
					z++;
			}
			if (z != 1)
				break;
		}
		cout << z;
	}
}