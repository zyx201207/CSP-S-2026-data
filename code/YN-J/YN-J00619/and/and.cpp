#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, m, arr[1000000], maxn = -1e9, num;

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	while (next_permutation(arr, arr + n)) {
		num = arr[0];
		for (int i = 0; i < m; i++) {
			num &= arr[i];
		}
		maxn = max(maxn, num);
	}
	cout << maxn << endl;
	return 0;
}