/*
аЁУЈЕігуЃП
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void fre() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
}
int n, m;
deque<int>e;
int a[(int)5e5 + 2];
int f[(int)3e5 + 2];
bool cx[(int)3e5 + 2];

signed main() {
	fre();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (!cx[a[j]]) {
				e.push_back(a[j]);
				cx[a[j]] = 1;
			} else {
				while (1) {
					if (e.back() == a[j]) {
						break;
					}
					cx[e.back()] = 0;
					e.pop_back();
				}
			}
		}
		while (1) {
			f[e.front()]++;
			cx[e.front()] = 0;
			e.pop_front();
			if (e.size() == 0) {
				break;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << f[i] << " ";
	}
	return 0;
}
