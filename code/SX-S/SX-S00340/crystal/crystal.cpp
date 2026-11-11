#include <bits/stdc++.h>
using namespace std;
int s[500005];
int cnt;

bool cmp(int a, int b) {
	return a < b;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	sort(s, s + 1, cmp);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			s[i] = s[i] + j;
			if (s[i] = s[i + j]) {
				cnt++;
				s[i] = s[i] + 1;
				m--;
			} else {
				break;
			}
			ans = max(ans, cnt);
		}
		cout << ans;
		return 0;
	}
}