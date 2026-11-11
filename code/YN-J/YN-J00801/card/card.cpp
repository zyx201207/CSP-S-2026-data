#include <bits/stdc++.h>
using namespace std;
long long a[500050], n, m, b[500050], l, f[500050];
string s, s1;

int findb(int y, int z) {
	for (int i = y; i <= n; i++) {
		if (b[i] == z) {
			return i;
		}
	}
	return -1;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> l;
		f[l]++;
		b[i] = l;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (f[b[j]] != 1) {
				f[b[j]]--;
				j = findb(j + 1, b[j]) - 1;
			} else {
//				if (b[j] == 1) {
//					cout << i;
//				}
				a[b[j]]++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << a[i] << " ";
	}
	return 0;
}