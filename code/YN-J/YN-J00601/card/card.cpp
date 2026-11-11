#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long a[1000001];
long long sum;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		sum += a[i];

		if (a[i] == k) {
			cout << sum;
			sum = 0;
		}

		cout << a[i] << " ";
	}

	return 0;
}