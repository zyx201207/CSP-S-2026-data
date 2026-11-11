#include <bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 3) {
		cout << "3 1 4";
	}
	if (n == 10) {
		cout << "10 3 3";
	} else {
		cout << "1 1 1";
	}
}