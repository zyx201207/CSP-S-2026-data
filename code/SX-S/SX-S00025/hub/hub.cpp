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

//
mt19937 rng(random_device{}());

void solve() {
	int x = rng() % 10;
	cout << x << endl;
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t = 1;
	cin >> t;
	while (t --)
		solve();
}
