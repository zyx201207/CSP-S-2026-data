#include <bits/stdc++.h>
using namespace std;
int m, n;
int a[300010], c[500010];
vector<int>b;

int main() {
	cin >> n >> m;
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int t = 0; t < b.size(); t++) {
				if (b[t] == a[j]) {
					int l = b.size() - t + 1;
					for (int jj = t; jj <= b.size(); jj++) {
						b[i] = 0;
					}
					break;
				}

			}
			b.push_back(a[j]);

		}
		for (int gg = 0; gg < b.size(); gg++) {
			c[b[gg]] += 1;
		}
	}
	for (int h = 1; h <= 500010; h++) {
		cout << c[h] << ' ';
	}
	return 0;
}