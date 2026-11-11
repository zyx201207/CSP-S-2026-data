#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()

const int inf = LONG_LONG_MAX;
int n, m;

void work() {
	cin >> n >> m;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(all(a));
	int cur = 0, ans = 0;
	queue<int>q;
	q.push(0);
	for (int i = 1; i < n; i++) {
		int dif = a[i] - a[i - 1];
		if (cur + dif * q.size() <= m)
			cur += dif * q.size();
		else {
			while (cur + dif * q.size() > m) {
				cur -= a[i - 1] - a[q.front()];
				q.pop();
			}
			cur += dif*q.size();
		}
		q.push(i);
		int v = q.size();
		ans = max(ans, v);
	}
	cout << ans;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--)	work();
	return 0;
}