#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
long long a[N], ans;
vector<long long> v;

bool cmd(int q1, int q2) {
	return q1 > q2;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1, cmd);
	ans = a[1];

	for (int i = 2; i <= m; i++) {

		ans = ans & a[i];
	}

	cout << ans;
	return 0;
}
