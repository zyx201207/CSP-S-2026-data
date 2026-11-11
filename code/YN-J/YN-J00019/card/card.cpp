#include <bits/stdc++.h>
using namespace std;

int n, m, z[300010] = {0};
string p;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char x;
		cin >> x;
		p += x;
	}
	for (int i = 0; i < n - 1; i++) {
		int d[300010] = {0};
		for (int j = i; j < n; j++) {
			int x = int(p[j] - '0');
			if (p.find(i, j - 1, p[j]) == -1) {
				d[x] = j;
			} else {
				p.erase(d[x], j - 1);
			}
			for (int j = i; j < p.size(); j++) {
				int x = int(p[j] - '0');
				z[x]++;
			}
		}
		for (int i = 1; i <= m; i++) {
			cout << z[i] << " ";
		}
	}
	return 0;
}