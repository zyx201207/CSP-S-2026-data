#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;
struct {
	int a;
	char c;
} m[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> m[i].a >> m[i].c;
	int l = 1, r = n;
	while (l < r) {
		if (m[l].c == m[r].c) {
			int x = m[l].a, y = m[r].a;
			m[l].a -= min(x, y);
			m[r].a -= min(x, y);
			if (m[l].a == 0)
				l++;
			if (m[r].a == 0)
				r--;
		} else {
			int x = m[l].a, y = m[r].a;
			ans += min(x, y);
			m[l].a -= min(x, y);
			m[r].a -= min(x, y);
			if (m[l].a == 0)
				l++;
			if (m[r].a == 0)
				r--;
		}
	}
	cout << ans;
	return 0;
}