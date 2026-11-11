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

static constexpr int MAXN = (int)(5e5) + 10;

int n, k, il[MAXN];
int cnt[MAXN];

signed main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> il[i];
	for (int l = 1; l <= n; l++) {
		static int stk[MAXN], pos[MAXN];
		int top = 0;
		for (int i = l; i <= n; i++) {
			if (pos[il[i]] == 0) {
				pos[il[i]] = ++top;
				stk[top] = il[i];
			} else {
				while (top > pos[il[i]])
					pos[stk[top--]] = 0;
			}
		}
		while (top > 0)
			cnt[stk[top]]++, pos[stk[top--]] = 0;
	}
	for (int i = 1; i <= k; i++)
		cout << cnt[i] << ' ';
	cout << '\n';

	return 0;
}