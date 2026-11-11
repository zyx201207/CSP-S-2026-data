#include <bits/stdc++.h>
using namespace std;

int n, m, a[500010], sum, b[300010];
string s;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (s.find(0, n - 1, (char)(a[j] + '0')) == -1) {
				s += (char)(a[j] + '0');
			} else {
				s.erase(s.find(0, n - 1, (char)(a[j] + '0')), n - 1 - s.find(0, n - 1, (char)(a[j] + '0')));
				s += (char)(a[j] + '0');
			}
		}
		for (int j = 0; j <= s.size() - 1; j++) {
			if (s[j] == (char)(i + '0')) {
				b[i]++;
			}
		}
	}
	for (int i =  1; i <= m; i++) {
		cout << b[i] << ' ';
	}
	return 0;
}