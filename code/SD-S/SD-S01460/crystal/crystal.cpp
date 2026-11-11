#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;
typedef unsigned long long ull;

const int N = 5e5 + 5;
int n, m;
int arr[N];
ull diff[N];

struct BIT {
	ull tree[N];

	int lowbit(int x) {
		return x & -x;
	}

	int query(int x) {
		int ans = 0;
		for (; x; x -= lowbit(x)) {
			ans += tree[x];
		}
		return ans;
	}

	void add(int pos, int y) {
		for (; pos <= n; pos += lowbit(pos)) {
			tree[pos] += y;
		}
	}
} bit;

ull Find(int pos) {
	int l = pos, r = n, mid;
	while (l <= r) {
		mid = (r - l) / 2 + l;
		ull val = (bit.query(mid) - bit.query(pos - 1)
		           - (mid - pos + 1) * diff[mid]);

		if (val > m) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	return r - pos + 1;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	sort(arr + 1, arr + 1 + n);

	for (int i = 1; i <= n; ++i) {
		diff[i] = arr[n] - arr[i];
		bit.add(i, diff[i]);
	}

	ull ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = max(Find(i), ans);
	}

	cout << ans;

	return 0;
}
