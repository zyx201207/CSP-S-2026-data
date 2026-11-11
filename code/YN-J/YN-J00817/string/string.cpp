#include <bits/stdc++.h>
#define int long long
using namespace std;
int s[100005];
char zm[100005];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n, v, t, js = 0;
	cin >> n;
	v = 1;
	t = n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> zm[i];
	}
	while (t != n / 2) {
		if (zm[v] != zm[t]) {
			js += min(s[v], s[t]);
		}
		v++;
		t--;
	}
	cout << js;
	return 0;
}
