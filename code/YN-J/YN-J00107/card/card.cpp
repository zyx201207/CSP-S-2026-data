#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 1;
int c[N];
bool b[200000 + 1][N];
bool d[200000 + 1][N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n + 1];
	int r[m + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= i; j--) {
			if (!b[i][a[j]]) {
				b[i][a[j]] = 1;
				if (i == 1)
					c[a[j]] = 1;
				else
					c[a[j]]++;
				r[a[j]] = j;
			} else {
				for (int w = j + 1; w < r[a[j]]; w++) {
					if (!d[i][j]) {
						c[a[w]]--;
						if (c[a[w]] == 0)
							b[i][a[w]] = 0;
						d[i][j] = 1;
					}
				}
			}
		}
	}
	for (int i = 1; i < m; i++)
		cout << c[i] << " ";
	cout << c[m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}