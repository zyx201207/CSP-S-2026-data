#include <bits/stdc++.h>
using namespace std;
int n, m, cnt[500003];
char a[500003];
int main () {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		string s;
		for (int j = i + idx; j <= n; j++) {
			if (s.find (a[j]) != string::npos) {
				while (s.size() > 0) {
					if (s[s.size() - 1] == a[j]) {
						s.erase();
						break;
					}
					s.erase();
				}
			}
			s += a[j];
		}
		for (int i = 0; i < s.size(); i++) {
			cnt[s[i] - '0']++;
		}
		++idx;
	}
	for (int i = 1; i <= m; i++) {
	 	cout << cnt[i] << ' ';
	}
	return 0;
} 
