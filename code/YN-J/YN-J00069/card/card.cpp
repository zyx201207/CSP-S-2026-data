#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n] = {0};
	int b[n] = {0};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int j = 1; j <= n; j++) {
		b[i] = a[i];
		if (b[i] == b[i - 1] || b[i - 2]) {
			b[i] < 3;
		}
	}
}