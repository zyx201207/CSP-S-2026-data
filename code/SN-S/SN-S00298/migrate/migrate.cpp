#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 305;

int c, t, n;
ll d, x[N], ans;
vector<int> e[N];
queue<pair<int, int>> dl;

struct Node{
	int tag, step, way;
} flag[N];

bool check(int s, int t) {
	while (!dl.empty()) dl.pop();
	for (int i = 1;i <= n;i++) {
		flag[i].tag = 0;
		flag[i].step = 0x3f3f3f3f;
		flag[i].way = 0;
	}
	int cnt = 0, now;
	dl.push({s, 0});
	flag[s].tag = 1;
	flag[s].step = 0;
	flag[s].way = 1;
	while (!dl.empty()) {
		now = dl.front().first;
		cnt = dl.front().second + 1;
			
		for (auto v : e[now]) {
			if (flag[v].tag == 0) {
				dl.push({v, cnt});
				flag[v].tag = 1;
				flag[v].step = cnt;
				flag[v].way = flag[now].way;
			}
			else if (cnt == flag[v].step)flag[v].way+=flag[now].way;
		}
		dl.pop();
	}
	return (flag[t].way == 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		ans = 0;
		
		cin >> n >> d;
		for (int i = 1;i <= n;i++) {
			cin >> x[i];
			e[i].clear();
		}
		for (int i = 1;i < n;i++) {
			for (int j = i + 1;j <= n;j++) {
				if (x[j] - x[i] <= d) {
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		for (int i = 1;i < n;i++) {
			for (int j = i + 1;j <= n;j++) {
				if (check(i, j)) {
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
