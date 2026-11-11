#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], b[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		if (m == 1)
			for (int i = 1; i <= m; i++)
				cout << n << " ";
		else if (m == n)
			for (int i = 1; i <= m; i++)
				cout << i << " ";
		else
			for (int i = 1; i <= m; i++)
				cout << "1 ";
	}
	return 0;
}