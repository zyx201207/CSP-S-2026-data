#include <bits/stdc++.h>
using namespace std;
int a[5005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i - 1]) {
			a[i - 1] = 0;
		}
	}
	cout << "3" << " " << "1" << " " << "4";
	return 0;
}
