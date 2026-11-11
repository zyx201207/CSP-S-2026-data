#include <bits/stdc++.h>
using namespace std;
int n, m, a[100000], mn[100000], con = 0;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while (n--) {
		con++;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i, j++) {
				if (a[i] != mn[j]) {
					mn[i] = a[i];
				} else {
					mn[]
				}
			}
		}
	}
	return 0;
}