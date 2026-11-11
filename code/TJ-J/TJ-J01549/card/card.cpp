#include <bits/stdc++.h>
using namespace std;
long live[400001];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long n, m;
	cin >> n >> m;
	long list[n], far[m + 1];
	for (long i = 0; i < n; i++) {
		cin >> list[i];
		far[list[i]] = i;
	}
	for (long i = 0; i < n; i++) {
		long j = i;
		while (j < n) {
			live[list[j]]++;
			j = far[list[j]] + 1;
		}
	}
	for (long i = 1; i <= m; i++) {
		cout << live[i] << ' ';
	}
	return 0;
}