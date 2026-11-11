#include <bits/stdc++.h>
using namespace std;

struct zm {
	char z;
	long long gs;
};
zm a[200005];
long long sum = 0, f, suml = 0, sum_gs = 0, z;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].gs >> a[i].z;
		sum += a[i].gs;
	}
	for (int i = 1; i <= n; i++) {
		suml += a[i].gs;
		if (suml > sum / 2) {
			f = i;
			break;
		}
	}
	int r = n;
	int l = 0;
	while (l < f && r >= f) {
		while (z > a[r].gs) {
			if (r < f)
				break;
			if (a[l].z != a[r].z) {
				sum_gs += a[r].gs;
			}
			z -= a[r].gs;
			r--;
		}
		if (a[l].z != a[r].z) {
			sum_gs += z;
		}
		a[r].gs -= z;
		l++;
		z = a[l].gs;
	}
	cout << sum_gs ;
	return 0;
}