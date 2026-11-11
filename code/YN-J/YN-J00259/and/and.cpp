#include <bits/stdc++.h>
using namespace std;
int n, m;
map<int, string>mp;
int sum;
int a[200005];

void dfs(int x, int y) {
	if (x > m) {
		string s = "";
		int ans = 0;
		for (int i = 0; i <= 30; i++) {
			for (int j = 1; j <= m; j++) {
				if (mp[a[j]][i] != '1' && mp[a[j]][i] != '0') {
					break;
				}
				if (mp[a[j]][i] == '0') {
					s += '0';
					break;
				}
				if (j == m) {
					s += '1';
				}
			}
		}
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == '1') {
				ans = ans * 2 + 1;
			} else {
				ans *= 2;
			}
		}
		sum = max(sum, ans);
	}
	if (y == n) {
		return ;
	}
	for (int i = y + 1; i <= n; i++) {
		a[x] = i;
		dfs(x + 1, i);
		a[x] = 0;
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x;
		string s = "";
		cin >> x;
		while (x) {
			s += (x % 2) + '0';
			x /= 2;
		}
		mp[i] = s;
	}
	dfs(1, 0);
	cout << sum;
	return 0;
}