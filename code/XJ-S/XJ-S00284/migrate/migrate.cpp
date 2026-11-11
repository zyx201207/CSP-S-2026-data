#include <iostream>
#include <climits>
#include <queue>
using namespace std;
const int MAXN = 2e6 + 5;
int x[MAXN], minn[MAXN], sum[MAXN];
queue<pair<int, int>>q;
int main(void) {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d, ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; ++i)
			cin >> x[i];
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				sum[j] = 0;
				minn[j] = INT_MAX;
			}
			q.push({i, 0});
			while (!q.empty()) {
				pair<int, int>now = q.front();
				q.pop();
				if (minn[now.first] == now.second)
					++sum[now.first];
				if (minn[now.first] > now.second) {
					sum[now.first] = 1;
					minn[now.first] = now.second;
				}
				int head = now.first + 1;
				while (head <= n && x[head] - x[now.first] <= d) {
					q.push({head, now.second + 1});
					++head;
				}
			}
			for (int j = i + 1; j <= n; ++j)
				if (sum[j] == 2)
					++ans;
		}
		cout << ans << '\n';
	}
	return 0;
} 
