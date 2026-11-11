#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 10;
long long n, m, arr[N], sum[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cout << arr[m - 1];

	return 0;
}