#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int a[N];
map<int, int> mp;

struct d {
	int val, cnt;
	friend bool operator<(d a, d b) {
		return a.val > b.val;
	}
};

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	set<int >s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]]++;
		s.insert(a[i]);
	}
	sort(a + 1, a + 1 + n);
	int ans = 1;
	for (auto x : s) {
		//cout << x << "\n";
		int sum = mp[x];
		priority_queue<d> q;
		for (auto v : s) {
			if (v >= x)
				continue;
			q.push({abs(v - x), mp[v]});
		}
		int now = m;
		while (now > 0 && !q.empty()) {
			if (q.size() == 0)
				break;
			auto u = q.top();
			q.pop();
			int val = u.val;
			int cnt = u.cnt;
			//	cout << val << " " << cnt << endl;
			if (now >= val * cnt) {
				now -= val * cnt;
				sum += cnt;
			} else {
				sum += now / val;
				now = 0;
			}
			if (now <= 0)
				break;
		}
		//cout << sum << endl;
		ans = max(ans, sum);
	}

	cout << ans << endl;
	return 0;
}