#include <bits/stdc++.h>
using namespace std;

int shu[200005];
int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, maxn = 0;
	cin >> n, m;
	for (int i = 1; i <= n + 1; i++) {
		cin >> shu[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			maxn = max(shu[i] & shu[j], maxn);
		}
	}
	cout << maxn;
	return 0;
}