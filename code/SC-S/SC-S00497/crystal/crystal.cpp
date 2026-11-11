#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 5e5 + 5;
int n, fnl = 1;
ll m, a[N], pref[N];

inline ll A (int l, int r) {
	return pref[r] - pref[l - 1];
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i) pref[i] = pref[i - 1] + a[i];
	for (int i = 1; i <= n; ++ i) {
		int l = 1, r = i, ans = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[i] * (i - mid + 1) - A(mid, i) <= m)
				ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		fnl = max(fnl, i - ans + 1);
	}
	cout << fnl;
	return 0;
}


/*
100 + 100 + [32, 40] + [25, 30]

这分有 gunmu % 的概率能打 WC 

终究还是输了吗，我真的不甘心啊。。。 
*/