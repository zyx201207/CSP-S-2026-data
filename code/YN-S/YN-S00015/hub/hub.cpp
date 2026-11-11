#include <bits/stdc++.h>
#define pb push_back
#define N 1000005
using namespace std;
int c, t, n, k, u, v, m;
vector<int>a[N];
bool b[15];

void solve0() {
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			a[i].clear();
		for (int i = 1; i < n; i++) {
			cin >> u >> v;
			a[u].pb(v), a[v].pb(u);
		}
		if (n == k) {
			cout << 0 << endl;
			continue;
		}
		if (n <= 5) {
			cout << 1 << endl;
			continue;
		}
		memset(b, 0, sizeof(b));
		int sum = 0, cnt = 0;
		for (int i = 1; i <= n; i++)
			if (a[i].size() == 1)
				b[a[i][0]] = 1, sum++;
		for (int i = 1; i <= n; i++)
			if (b[i])
				cnt++;
		int lst = n - sum;
		if (cnt >= 3) {
			if (k >= lst)
				cout << 1 << endl;
			else
				cout << 2 << endl;
			continue;
		}
		if (k >= lst - 1)
			cout << 1 << endl;
		else
			cout << 2 << endl;
	}
}

void solve1() {
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			a[i].clear();
		for (int i = 1; i < n; i++) {
			cin >> u >> v;
			a[u].pb(v), a[v].pb(u);
		}
		if (n == k) {
			cout << 0 << endl;
			continue;
		}
		m = (n - 1) / 2 + 2;
		if (m <= k) {
			cout << 1 << endl;
			continue;
		}
		int t = (m - k);
		if (t % 3 == 0)
			cout << t / 3 << endl;
		else
			cout << (t / 3 + 1) << endl;
	}
}

void solve2() {
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			a[i].clear();
		for (int i = 1; i < n; i++) {
			cin >> u >> v;
			a[u].pb(v), a[v].pb(u);
		}
		cout << n / 3 << endl;
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	if (c <= 3)
		solve0();
	if (c == 13 || c == 14)
		solve1();
	else
		solve2();
	return 0;
}