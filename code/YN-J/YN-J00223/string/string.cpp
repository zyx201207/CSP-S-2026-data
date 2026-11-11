#include <bits/stdc++.h>
using namespace std;

char c;
int test, n;
long long ans;
vector<pair<int, char>> s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> test >> c;
		s.push_back({test, c});
	}
	int l = 0, r = s.size() - 1;
	while (l <= r) {
		int mi = min(s[l].first, s[r].first);
		if (s[l].second != s[r].second)
			ans += mi;
		s[l].first -= mi;
		s[r].first -= mi;
		if (s[l].first <= 0)
			l++;
		if (s[r].first <= 0)
			r--;
	}
	cout << ans << endl;
	return 0;
}