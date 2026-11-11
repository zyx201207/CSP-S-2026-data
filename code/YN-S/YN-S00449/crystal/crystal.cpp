#include <bits/stdc++.h>
using namespace std;
float z, b[50005], c;
int n, m, a[50005], sum = 0;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		z += a[i];
	}

	z = z / n;

	for (int i = 0; i <= n + 1; i++) {

		b[i] = a[i] - z;

		if (b[i] < 0) {
			b[i] = b[i] * -1;

		}

		if (b[i] < b[i - 1]) {
			c = b[i] + z;
		}
	}
	while (m == 0) {
		int i;

		if (a[i] - c < 0) {
			m = -1 * (a[i] - c);
			sum += 1;
		} else {
			m = a[i] - c;
			sum += 1;
		}

		i++;
	}

	cout << sum;
	return 0;
}