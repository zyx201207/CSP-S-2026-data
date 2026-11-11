#include <bits/stdc++.h>
using namespace std;
int a[500005];
int t[500005];
bool vis[1000005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int k = 0; k < n; k++) {
		memset(vis, false, sizeof vis);
		s = {""};
		for (int i = k; i < n; i++) {
			for (int j = 0; j < s.size(); j++) {
				if (s[j] == a[i]) {
					s.erase(j, s.size() - 1);
					break;
				}
			}
			s += (char)(a[i] + '0');
		}
		for (int j = 0; j < s.size(); j++) {
			if (!vis[s[j] - '0']) {
				t[s[j] - '0']++;
				vis[s[j] - '0'] = true;
			}
		}
	}
	for (int i = 2; i < m; i++)
		t[i]--;
	for (int i = 1; i <= m; i++)
		cout << t[i] << ' ';
	return 0;
}