#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int a[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int y;
		cin >> y;
		if (k == y) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}