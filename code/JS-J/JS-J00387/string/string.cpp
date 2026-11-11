#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 9;
vector<pair<int, char>> a(N);
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, ans = 0; cin >> n;
	for(int i = 1, num; i <= n; ++i) {
		char ch; cin >> num >> ch;
		a[i] = make_pair(num, ch);
	}
	int l = 1, r = n;
	while(l < r) {
		if(a[l].first == 0) l++;
		if(a[r].first == 0) r--;
		if(a[l].second != a[r].second) {
			int minn = min(a[l].first, a[r].first);
			ans += minn;
			a[l].first -= minn, a[r].first -= minn;
		}
		else {
			int minn = min(a[l].first, a[r].first);
			a[l].first -= minn, a[r].first -= minn;
		}
	}
	cout << ans;
	return 0;
}
