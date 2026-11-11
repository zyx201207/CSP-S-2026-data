#include <bits/stdc++.h>
using namespace std;
vector<pair<int, char> > v;
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		int t;
		char a;
		cin >> t >> a;
		v.push_back({t, a});
	}
	long long ans = 0;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	int left = 0, right = n - 1;
	while (left < right) {
		if (v[left].second == v[right].second) {
			if (v[left].first < v[right].first) {
				v[right].first -= v[left ++].first;
				
			} else if ((v[left].first > v[right].first)) {
				v[left].first -= v[right --].first;
			} else {
				left ++;
				right --;
			}
		} else {
			if (v[left].first < v[right].first) {
				ans += v[left].first;
				v[right].first -= v[left ++].first;
				
			} else if ((v[left].first > v[right].first)) {
				ans += v[right].first;
				v[left].first -= v[right --].first;
			} else {
				ans += v[left].first;
				left ++;
				right --;
			}
		}
	}
	cout << ans;
	return 0;
}