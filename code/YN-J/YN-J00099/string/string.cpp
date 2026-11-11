#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a[i] >> c[i];
	}

	int i = 1, j = n;
	long long summ = 0;

	while (i < j) {
		if (a[i] > a[j]) {
			a[i] -= a[j];

			if (c[i] != c[j])
				summ += a[j];
			j--;
		} else if (a[i] == a[j]) {
			if (c[i] != c[j])
				summ += a[i];
			i++, j--;
		} else {
			a[j] -= a[i];

			if (c[i] != c[j])
				summ += a[i];
			i++;
		}
	}

	cout << summ << endl;
	return 0;
}