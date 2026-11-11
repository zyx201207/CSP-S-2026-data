#include <iostream>
using namespace std;
int n, m, c, d[210000], e[210000], g[210000];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}
	for (int i = 1; i <= n; i++) {
		c = m - i;
		for (int j = i; j <= c; j++) {
			e[j] = a[j];
		}
	}
	long long ff = and (all_sort(e));
	cout << sort(ff);
	return 0;
}