#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 100005;
int m, n, m1[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> m1[i];
	}
	cout << m1[m - 1];
	return 0;
}