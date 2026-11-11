#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pr pair<ull,int>
using namespace std;

const int N = 2e5 + 50;

ull n, m, p = pow(2, 30), x, e[N][50], ans, ai, cnt;
pr a[N];

bool cmp(pr a, pr b) {
	if (a.second == b.second)
		return a.first > b.first;
	else
		return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first;
	}
	for (int i = 1; i <= n; i++) {
		x = p, ai = a[i].first, cnt = 0;
		for (int j = 30; j >= 0; j--) {
			if (ai >= x) {
				ai -= x, cnt++, e[i][j] = 1;
			}
		}
		a[i].second = cnt;
	}
//	for (int i = 1; i <= n; i++) {
//		b[a[i].second].second++, b[a[i].second].first = a[i].first;
//	}
	sort(a + 1, a + n + 1, cmp);
	ans = a[1].first;
	for (int i = 2; i <= m; i++) {
		ans &= a[i].first;
	}
	cout << ans;

	return 0;
}
