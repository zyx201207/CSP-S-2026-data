#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::min;
using std::max;
using std::vector;
using std::string;

#define int long long

#define fst first
#define scd second
#define pr std::pair<int,int>
#define ep emplace
#define eb emplace_back

static constexpr int MAXN = (int)(2e5) + 10;
static constexpr int D = 33, MAXD = 36;

int n, k, il[MAXN], ans;
vector<int> rem;

signed main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> il[i], rem.eb(il[i]);
	for (int i = D; i >= 0; i--) {
		static vector<int> tmp;
		tmp.clear();
		for (const int &x : rem)
			if (x >> i & 1)
				tmp.eb(x);
		if (tmp.size() < k)
			continue;
		ans += (1ll << i), rem.clear();
		for (const int &x : tmp)
			rem.eb(x);
	}
	cout << ans << '\n';

	return 0;
}