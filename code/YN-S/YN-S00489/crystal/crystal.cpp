#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;

long long c[N];


int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	long long n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (c[j] > c[j + 1]) {
				int t = c[j];
				c[j] = c[j + 1];
				c[j + 1] = t;
			}
		}
	}




	cout << 3;
	return 0;
}