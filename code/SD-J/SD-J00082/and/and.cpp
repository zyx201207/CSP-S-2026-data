#include <bits/stdc++.h>
#define ll long long
#define N 300010
using namespace std;
struct Node {
	int id, x;
};
int n, m, maxx;
int a[N];
int vis[50][N];
int cnt[50];
int ans;
int er_mi[50];
vector<Node> now, arr;
void init() {
	er_mi[0] = 1;
	for (int i = 1; i <= 40; ++i) {
		er_mi[i] = er_mi[i - 1] * 2;
	}
}
void go(int id) {
	int x = a[id];
	int ws = 0;
	for (int i = 0; i <= 40; ++i) {
		if (er_mi[i] & x) {
			vis[i][id] = 1;
			cnt[i]++;
		}
	}
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m; init();
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
		go(i);
		now.push_back({i, a[i]});
	}
	int max_log = log2(maxx) + 1;
	for (int k = max_log; k >= 0; --k) {
		int now_cnt = 0;
		for (int i = 0; i < (int)now.size(); ++i) {
			if (now[i].x & er_mi[k]) {
				now_cnt++;
			}
		}
		if (now_cnt >= m) {
			ans += er_mi[k];
			arr.clear();
			for (int i = 0; i < (int)now.size(); ++i) {
				if (now[i].x & er_mi[k]) {
					arr.push_back(now[i]);
				}
			}
			now = arr;
		}
	}
	cout << ans;
	return 0;
}
