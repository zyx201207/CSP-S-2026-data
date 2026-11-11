#include <bits/stdc++.h>
using namespace std;
int n, m;
int ps[1000000 + 1];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		cin >> ps[i];
	}
	cout << n << ps[n] << m;
	return 0;
}