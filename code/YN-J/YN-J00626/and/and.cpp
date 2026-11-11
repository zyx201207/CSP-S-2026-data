#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int maxo = -1;
	int maxr = 0;
	long long b[n];
	for (int i  = 1; i <= n; i++) {
		int a;
		cin >> a;
		b[a]++;
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] > maxo) {
			maxo = b[i];
			maxr = i;
		}
	}
	cout << maxr;
	return 0;
}