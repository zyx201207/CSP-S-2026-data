#include <bits/stdc++.h>
using namespace std;

long long m, su = 0, da = 0, num[2][500005] = {};
long long  a[500005] = {};
int main() {
	int n;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	a[0] = -1000000000001;
	cin >> n >> m;
	a[n + 2] = 1000000000001;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	num[0][1] = a[1];
	num[1][1] = 0;
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++) {
		num[0][i] = a[i] + num[0][i - 1];
		num[1][i] = i * a[i] - num[0][i];
		//cout << num[1][i] << " ";
	}

	for (int i = 1; i <= n; i++) {
		if (m < num[1][i]) {
			su = i - 1;
			break;
		}
	}
	//cout << su << " ";
	da = su;
	for (long long i = 1; i <= su; i++) {
		for (long long  j = su + 1; j <= n; j++) {
			//cout << num[1][j] - (i *a[j] - num[0][i]) << " " << i << " " << j << endl;
			if (num[1][j] - (i * a[j] - num[0][i]) <= m) {
				//cout << "ac" << num[1][j] - (i *a[j] - num[0][i]) << " " << i << " " << j << endl;
				da = max(j - i, da);
			}
		}
	}
	cout << da;
	return 0;
}
