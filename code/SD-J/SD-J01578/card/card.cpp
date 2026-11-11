#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], g[500005], p = 0, t[300005], k = 0;
bool b;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i ++) {
		p = 0;
		for (int j = i; j < n; j ++) {
			b = false;
			for (k = 0; k < p; k ++) {
				if (g[k] == a[j]) {
					b = true;
					break;
				}
			}
			if (b) {
				p = k;		
			}
			g[p] = a[j];
			p ++;
//			cout << "p:" << p << endl;
//			for (int awa = 0; awa < p; awa ++) {
//				cout << g[awa] << ' ';
//			}
//			cout << endl;
		}
		for (int awa = 0; awa < p; awa ++) {
//			cout << g[awa] << ' ';
			t[g[awa]] ++;
		}
//		cout << endl;
	}
	for (int i = 1; i <= m; i ++) {
		cout << t[i] << ' ';
	}
	return 0;
}
