#include <bits/stdc++.h>
using namespace std;
int s[200005];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	sort(s + 1, s + 1 + n, cmp);
	int ans = s[1];
	for (int i = 2; i <= m; i++) {
		ans &= s[i];
	}
	cout << ans;
}