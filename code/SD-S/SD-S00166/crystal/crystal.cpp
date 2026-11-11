#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using pii = pair<int, int>;

const int mod = 998244353;

void solve() {
	int n, ans = 0;
	i64 m;
	cin >> n >> m;
	
	vector<i64> a(n + 1), b(n + 1, 0);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a.begin() + 1, a.end());
	for (int i = 1; i <= n; i ++) {
		b[i] = b[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i ++) {
		int l = 1, r = i - 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			i64 now = (i - mid) * a[n] - (b[i - 1] - b[mid - 1]) - (i - mid) * (a[n] - a[i]);
//			cout << now << ' ';
			if (now <= m) r = mid - 1;
			else l = mid + 1;
			
		}
		if (!l) continue;
		ans = max(ans, i - l + 1);
	}
	cout << ans;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int T = 1;
//  cin >> T;
	while (T --) {
		  solve();
	}
	
	return 0;
}

/*
3
4
3845
315275
WO CAO WO ZEN ME WANG LE ER FEN ZA XIE
LUOGU ID: GreenMelon
*/
