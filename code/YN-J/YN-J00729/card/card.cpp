#include <bits/stdc++.h>
using namespace std;
long long n, m;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	if (m <= 5) {
		for (int i = 1; i <= m; i++)
			cout << i << ' ';
	} else {
		for (int i = 1; i <= m; i++)
			cout << n << ' ';
	}
	return 0;
}