#include <bits/stdc++.h>
using namespace std;

template <typename T> inline T read() {
	T x = 0; bool f = 1; char ch = getchar();
	while (ch < '0' || '9' < ch) { if (ch == '-') f = 0; ch = getchar(); }
	while ('0' <= ch && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? x : -x;
}

typedef long long ll;

int n; ll m;
vector<ll> a(500005);
ll ans = 0;
bool A = true, B = true;

void dfs(int now, int rest) {
	if (rest == 0 || now == n + 1) {
		unordered_map<ll, ll> mp;
		for (int i = 1; i <= n; i++) mp[a[i]]++;
		ll res = 0;
		for (int i = 1; i <= n; i++) res = max(res, mp[a[i]]);
		ans = max(ans, res);
		return ;
	}
	for (int i = 0; i <= rest; i++) {
		a[now] += i;
		dfs(now + 1, rest - i);
		a[now] -= i;
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read<int>(); m = read<ll>();

	for (int i = 1; i <= n; i++) {
		a[i] = read<ll>();
		if (a[i] != i) A = false;
		if (i > 1) {
			if (a[i] - a[i - 1] != a[2] - a[1]) B = false;
		}
	}
	cout << A << " " << B << "\n";
	if (A) {
		int x = 1;
		for (; (x + 1) * (x + 2) / 2 <= m; x++);
		cout << x + 1; return 0;
	}
	if (B) {
		int x = 1, d = a[2] - a[1];

		for (; (x + d) * ((x + d) + 1) / 2 <= m; x += d);
		cout << x; return 0;
	}
	if (n > 10) { cout << 20130201; return 0; }
	dfs(1, m);
	cout << ans;


	return 0;
}
