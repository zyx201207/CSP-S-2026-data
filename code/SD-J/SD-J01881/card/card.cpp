#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 5;
int cnt[N], n, m, cd[N], arr[N];
bool flag_A = true;

struct BIT {
	int tree[N];

	int lowbit(int x) {
		return x & -x;
	}

	void add(int x, int pos) {
		for (; pos; pos += lowbit(pos)) {
			tree[pos] += x;
		}
	}
	
	int query(int pos) {
		int ans = 0;
		for (; pos; pos -= lowbit(pos)) {
			ans += tree[pos];
		}
		return ans;
	}
} bit;

void solve_BF() {
	for (int i = 1; i <= n; ++i) {
		vector<int> card;
		for (int k = i; k <= n; ++k) {
			bool ok = false;
			int q = 0;
			for (const auto p : card) {
				if (p == arr[k]) {
					ok = true;
					break;
				}
				++q;
			}

			if (ok) {
				card.erase(card.begin() + q, card.end());
			}

			card.push_back(arr[k]);
		}

		for (const auto& k : card) {
			++cnt[k];
		}
	}

	for (int i = 1; i <= m; ++i) {
		cout << cnt[i];
		if (i != m) cout << " ";
	}
}

void solve_A() {
	for (int i = n; i >= 1; --i) {
		if (arr[i] != arr[i + 1])
			cnt[arr[i]] += i;
	}

	for (int i = 1; i <= m; ++i) {
		cout << cnt[i];
		if (i != m) cout << " ";
	}
}

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		if (arr[i] < arr[i - 1]) flag_A = false;
	}

	if (n <= 500) {
		solve_BF();
	} else if (flag_A) {
		solve_A();
	} else if (m <= 2) {
		solve_BF();
	} else {
		solve_BF();
	}

	return 0;
}
