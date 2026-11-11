#include <bits/stdc++.h>
using namespace std;
int n, m;
int ffzs[1000000 + 1];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m ;
	for (int i = 1; i <= n; i++) {
		cin >> ffzs[i];
	}
	cout << ffzs[n];
	return 0;
}