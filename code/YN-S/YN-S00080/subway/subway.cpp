#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
struct node {
	int x;
	int y;
	long long st;
	int fm;
};


long long w[505] = {}, k[501] = {}; //口到厅，地铁站数
long long a[501][501];
long long t[501][501]; //地铁站
int x[105], y[105];
vector<long long> line[500001];
bool dist[500001];
queue<node> que;

long long BFS() {
	node xys = que.front();//来自
	int xp = xys.x;
	int yp = xys.y;
	long long st = xys.st + t[xys.fm][xp];//这一站进到站台
	que.pop();
	if (xp == yp) {
		return st;
	}
	dist[xp] = 1;
	for (auto i : line[xp]) {
		for (int j = 1; j <= k[i]; j++) {
			if (dist[j] == 0) {
				node xys2;
				xys2.x = j;
				xys2.y = yp;
				xys2.st = st + t[i][j];//下一站出到站厅
				xys2.fm = i;
				que.push(xys2);
				dist[xys2.x] = 1;
				return BFS();
			}
		}
	}
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			long long dtz;
			cin >> a[i][j] >> t[i][j];
			line[a[i][j]].push_back(i);
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= q; i++) {
		node xy;
		xy.x = x[i];
		xy.y = y[i];
		xy.st = 0;
		xy.fm = 1;
		que.push(xy);
		int ans = BFS() + w[x[i]] + w[y[i]];
		cout << ans<<endl;
		for (int i = 1; i <= m; i++) {
			dist[i] = 0;
		}
	}
	return 0;
}
