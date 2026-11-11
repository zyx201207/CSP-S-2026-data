#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 50;
vector<int> v[N + 5];
int ji[N + 5], dis[N + 5];
int vis[N + 5];
queue<int> q;
int c, T, n, k;

void init() {
	for (int i = 1; i <= n; i++) {
		v[i].clear();
	}
}

void sinit() {
	for (int i = 1; i <= n; i++) {
		ji[i] = 0;
		vis[i] = 0;
		dis[i] = 1e9;
	}
}

void tag1(int start) {
	while (!q.empty()) {
		q.pop();
	}
	vis[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto i : v[cur]) {
			if (vis[i] == 0 && ji[i] == 1) {
				vis[i] = 1;
				q.push(i);
			}
		}
	}
}

bool check(int num) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if ((num & (1 << i)) > 0) {
			ji[i + 1] = 1;
			cnt++;
		}
	}
	if (cnt != k) {
		return 0;
	}
	int kuai = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0 && ji[i] == 1) {
			kuai++;
			tag1(i);
		}
	}
	if (kuai > 2) {
		return 0;
	}
	return 1;
}

int bfs() {
	while (!q.empty()) {
		q.pop();
	}
	for (int i = 1; i <= n; i++) {
		if (ji[i] == 1) {
			q.push(i);
			dis[i] = 0;
		}
	}
	int maxx = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto i : v[cur]) {
			if (vis[i] == 0) {
				vis[i] = 1;
				dis[i] = dis[cur] + 1;
				maxx = max(maxx, dis[i]);
				q.push(i);
			}
		}
	}
	return maxx;
}

void solve() {
	int MAX = (1 << n), minn = 1e9;
	for (int i = 0; i < MAX; i++) {
		sinit();
		if (check(i) == 1) {
			minn = min(minn, bfs());
		}
	}
	cout << minn << endl;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int x, y;
	scanf("%d%d", &c, &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		init();
		for (int i = 1; i < n; i++) {
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}