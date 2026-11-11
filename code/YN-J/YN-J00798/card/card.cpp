#include <bits/stdc++.h>
using namespace std;
#define int long long
const int arr = 5e5;
int a[arr], t[arr];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, m, k;
	string s, s1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += char(a[i]);
	}

	for (int i = 1; i <= n; i++) {
		t[a[i]]++;
	}
	t[a[n]] = n;
	for (int i = 1; i <= m; i++) {
		cout << t[i] << " ";
	}
	return 0;
}