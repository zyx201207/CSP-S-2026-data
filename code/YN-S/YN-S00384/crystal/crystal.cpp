#include <bits/stdc++.h>
using namespace std;
#define int long long

int arr[500001] = {};

//x,yÎªÖ¸Õë
int crystal(int m, int x, int y) {
	if (m < 0 || y < 0 || arr[x] - arr[y] > m)
		return 0;
	else
		return crystal(m - arr[x] + arr[y], x, y - 1) + 1;
}

signed main() {
	freopen("crystal4.in", "r", stdin);
	freopen("crystal.ans", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	int maxn = 0;
	for (int i = 1; i <= n - 1; i++) {
		if (crystal(m, i, i - 1) + 1 > maxn) {
			maxn = crystal(m, i, i - 1) + 1;
		}
	}
	cout << maxn;
	return 0;
}