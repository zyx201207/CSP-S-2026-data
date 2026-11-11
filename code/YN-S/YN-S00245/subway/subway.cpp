#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d;
	cin >> n >> d;
	long long a[n], b[n];
	for (long long j = 1; j <= n; j++)
		cin >> a[j];
	sort(a + 1, a + n + 1);
	int h = 0;
	b[1] = h;
	for (int j = 2; j <= n; j++) {
		if (a[j] - a[j - 1] > d ) {
			h++;
			b[j] = h;
		} else if (a[j] - a[j - 1] <= d )
			b[j] = h;

	}

	for (long long j = 1; j <= n; j++)
		cout << b[j];
}