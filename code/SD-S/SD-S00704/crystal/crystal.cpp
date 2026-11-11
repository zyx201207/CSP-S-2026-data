#include <bits/stdc++.h>
using namespace std;
long long n, m, arr[500005], s[500005];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	} 
	sort(arr + 1, arr + n + 1);
	for(int i = 1; i <= n; i++) {
		s[i] = (arr[i] - arr[i - 1]) * (i - 1) + s[i - 1];
	} 
	int l = 1, r = n;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(s[mid] <= m) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	if(s[l] <= m) {
		cout << l;
	} else {
		cout << l - 1;
	}
	return 0;
}
