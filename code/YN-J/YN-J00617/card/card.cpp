#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n, m;
int arr[1000000], ans[1000000];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int x = n;
	while (n--) {
		s.clear();
		for (int i = x - n ; i <= x; i++) {
			if (s.find(arr[i] + '0') <= s.size()) {
				s.erase(s.find(arr[i] + '0' ), s.size() );
			}
			s.push_back(arr[i] + '0');
		}
		for (int i = 1; i <= m; i++) {
			if (s.find(i + '0') < s.size())
				ans[i]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}