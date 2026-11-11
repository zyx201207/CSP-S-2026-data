#include <bits/stdc++.h>
using namespace std;

struct zm {
	char z;
	long long gs;
};
zm a[200005];
long long  sum_gs = 0;

string s;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].gs >> a[i].z;
	}
	int l = 0, r = n;
	while (l < r) {
		if (a[l].gs >= a[r].gs) {
			if (a[l].z != a[r].gs) {
				sum_gs += a[r].gs;
			}
			a[l].gs -= a[r].gs;
			r--;
		} else {
			if (a[l].z != a[r].gs) {
				sum_gs += a[l].gs;
			}
			a[r].gs -= a[l].gs;
			l++;
		}
	}
	cout << sum_gs;
	return 0;
}
