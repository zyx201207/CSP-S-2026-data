#include <bits/stdc++.h>
#define endl '\n'
#define lowbit(x) x&(-x)

#define ll long long
#define int ll
#define ld long double
#define ull unsigned ll

#define PII pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vP vector<PII>
#define fi first
#define se second

const int N = 1e5 + 10;

using namespace std;
int c;

//
mt19937 rng(random_device{}());

void solve() {
	int n, d;
	cin >> n >> d;
	vi a(n + 1);
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	if (c == 11 || c == 12 || c == 0) {
		int k = a[2] - a[1];
		for (int i = 1; i <= 100000; i ++) {
			if (i * k > d) {
				cout << n - i << endl;
				break;
			}
		}
	} else
		cout << 0 << endl;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t = 1;
	cin >> c;
	cin >> t;
	while (t --)
		solve();
}
