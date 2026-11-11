#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;
int n, arr[N], ans = 0;
char ch[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i] >> ch[i];
	}

	int l = 1, r = n;
	while (l < r) {
		if (arr[l] > arr[r]) {
			if (ch[l] != ch[r]) {
				ans += arr[r];
			}
			arr[l] -= arr[r--];
		} else if (arr[l] < arr[r]) {
			if (ch[l] != ch[r]) {
				ans += arr[l];
			}
			arr[r] -= arr[l++];
		} else {
			if (ch[l] != ch[r]) {
				ans += arr[l];
			}
			++l, --r;
		}
	}
	
	cout << ans;

	return 0;
}
