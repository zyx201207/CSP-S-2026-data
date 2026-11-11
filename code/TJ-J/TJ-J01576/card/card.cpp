#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[10000001], b[1000001], c[10000001], jl[10000001], f = 1;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		fill(jl + 1, jl + 1 + m, 0);
		fill(c + 1, c + 2 + n, 0);
		f = 1;
		for (int j = i; j <= n; j++) {
			if (jl[a[j]] == 0) {
				jl[a[j]] = f;
				c[f] = a[j];
				f++;
			} else {
				f = jl[a[j]];
				for (int k = 1; k <= m; k++) {
					if (jl[k] > f) {
						jl[k] = 0;
					}
				}
				f++;
			}
		}
		for (int j = 1; j < f; j++) {
			b[c[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << b[i] << " ";
	}
	return 0;
}