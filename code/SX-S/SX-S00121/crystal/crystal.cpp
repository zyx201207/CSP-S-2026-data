#include <bits/stdc++.h>
#define p_q priority_queue
#define int long long
#define endl "\n"
using namespace std;
int num[500005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	sort(num + 1, num + n + 1, greater<int>());
	deque<int> q;
	int ans = 1, p1 = 1, p2 = 1 ;
	__int128 sum = 0;
	while (p1 <= n) {
		q.push_back(num[p1]);
		sum += num[p2] - num[p1];
		p1++;
		if (sum > m) {
			ans = max(ans, p2 - p1 + 1);
			while (sum > m) {
				sum -= (q.size() - 1 ) * (num[p2] - num[p2 + 1]);
				q.pop_front();
				p2++;
			}
		}
		ans = max(ans, (int)q.size());
	}
	cout << ans;
	return 0;
}