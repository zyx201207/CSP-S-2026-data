#include <bits/stdc++.h>
using namespace std;
#define in cin
#define out cout
#define int long long
const int N = 5e5 + 5;
int n, m, a[N], cnt[N];
bool has[N];
vector <int> stk;
void solve(int l, int r) {
	stk.clear();
	for (int i = 1; i <= m; i++) has[i] = false;
	for (int i = l; i <= r; i++)
		if (!has[a[i]]) has[a[i]] = true, stk.push_back(a[i]);
		else while (stk.back() != a[i]) has[stk.back()] = false, stk.pop_back();
	for (int i : stk) cnt[i]++;
}
signed main() {
//	freopen("card1.in", "r", stdin);
	freopen("card.in", "r", stdin), freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false), in.tie(nullptr), out.tie(nullptr);
	in >> n >> m;
	if (m == 1) { out << n; return 0; }
	for (int i = 1; i <= n; i++) {
		in >> a[i];
		if (m == 2) cnt[a[i]]++;
	}
	if (m > 2) for (int i = 1; i <= n; i++) solve(i, n);
	for (int i = 1; i <= m; i++)
		if (i == a[n]) out << n << ' ';
		else out << cnt[i] << ' ';
	return 0;
}