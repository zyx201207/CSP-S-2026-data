#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	string ans = 0;
	string a;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a;
		a += ans;
	}

	cout << ans;
	return 0;
}