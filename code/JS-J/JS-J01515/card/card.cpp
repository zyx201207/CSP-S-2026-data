#include <bits/stdc++.h>
using namespace std;
using uns = unsigned;

struct Np {
	uns num;
	uns cnt;
	Np(const uns& a): num(a), cnt(1) {}
};
uns t[3005], ans[3005];
bool is_sorted(vector<Np>& a) {
	for (uns i = 1; i < a.size(); ++i) if (a[i].num < a[i - 1].num) return 0;
	return 1; 
}
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	uns n, m, x;
	cin >> n >> m;
	vector<Np> a;
	vector<uns> desktop;
	desktop.reserve(a.size());
	for (uns i = 0; i < n; ++i) {
		cin >> x;
		if (a.empty() || a.back().num != x) a.emplace_back(x);
		else ++a.back().cnt;
	}
	
	if (is_sorted(a) && (a.size() > 5050 || m > 3050)) {
		uns prd = 0u;
		for (uns i = 0; i < a.size(); ++i) {
			ans[i] = (prd += a[i].cnt);
		}
		for (uns i = 1; i < m; ++i) cout << ans[i] << ' ';
		return 0;
	}
	
	for (uns i = 0; i < a.size(); ++i) {
		desktop.clear();
		for (uns j = 0; j <= m; ++j) t[j] = 0;
		for (uns j = i; j < a.size(); ++j) {
			if (t[a[j].num]) while (desktop.back() != a[j].num) --t[desktop.back()], desktop.pop_back();
			else desktop.emplace_back(a[j].num), ++t[a[j].num];
		}
		for (uns& k : desktop) ans[k] += a[i].cnt;
	}
	for (uns i = 1; i <= m; ++i) cout << ans[i] << ' ';
	
	return 0;
}
