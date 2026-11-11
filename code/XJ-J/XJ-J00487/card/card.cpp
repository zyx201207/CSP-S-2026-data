#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, cnt[N];
char a[N];
map<char, int> ans;
int main () {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		string tmp = "";
		for (int j = i; j <= n; j++) {
			int t = tmp.find(a[j]);
			if (t <= n) {
				for (int k = t; k <= n; k++) {
					tmp[k] = '0';
				}
			}
		}
		for (int j = 0; j < tmp.size(); j++) {
			ans[tmp[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}