#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 50, M = 3e5 + 50;
int a[N], tong[M], ji[M];
int nm[N];


signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ii = 1;
	for (int i = 1; i <= n; i++) {
		memset(tong, 0, sizeof(tong));
		for (int j = i; j <= n; j++) {
			ii = 1;
			if (tong[a[j]] ==  0) {
				tong[a[j]]++;
				nm[ii] = a[j];
			} else {
				while (nm[ii] != a[j]) {
					nm[ii] = 0;
					ii--;

				}

			}
		}
		for (int j = 1; j <= ii; j++) {
			ji[nm[ii]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ji[i] << " ";
	}
	return 0;
}
