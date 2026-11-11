#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (b); i--)
#define Fo(i, a) for (auto i : a)
#define fi first
#define se second
#define pb push_back
#define sr cin
#define sw cout
#define endl '\n'

const int N = 500010;
i64 a[N], s[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	i64 m;
	sr >> n >> m;
	For(i, 1, n) sr >> a[i];
	sort(a + 1, a + n + 1);
	For(i, 1, n) s[i] = s[i - 1] + a[i];
	int ans = 0;
	For(i, 1, n) {
		int l = 1, r = i, tmp = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m)
				r = mid - 1, tmp = mid;
			else
				l = mid + 1;
		}
		ans = max(ans, i - tmp + 1);
	}
	sw << ans << endl;
	return 0;
}