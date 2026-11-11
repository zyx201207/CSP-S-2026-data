#include <bits/stdc++.h>
#define int long long
using namespace std;
deque<pair <int, char> > q;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		int a;
		char c;
		cin >> a >> c;
		q.push_back({a, c});
	}
	int ans = 0;
	while (!q.empty()) {	
		pair <int, int> t1 = q.front(), t2 = q.back();
		q.pop_front();
		if (q.empty()) break;
		q.pop_back();
		if (t1.first > t2.first) {
			q.push_front({t1.first - t2.first, t1.second});
		} else if (t1.first < t2.first){
			q.push_back({t2.first - t1.first, t2.second});
		}
		if (t1.second != t2.second) {
			ans += min (t1.first, t2.first);
		}
	}
	cout << ans;
	
	return 0;
}