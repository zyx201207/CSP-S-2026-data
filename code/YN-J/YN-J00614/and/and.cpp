#include <bits/stdc++.h>
using namespace std;
#define int long long

int arr[200000] = {};

int arr1[200000] = {};

int fuc(int x) {
	int ans = 0, cnt = 0;
	while (x >= 2) {
		ans += x % 2 * pow(10, cnt);
		x = x / 2;
		cnt++;
	}
	if (x = 0)
		return ans;
	else
		return ans += pow(10, cnt);
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.ans", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
		arr[i] = fuc(arr[i]);
	for (int i = 0; i < n * n; i++) {

	}
	return 0;
}