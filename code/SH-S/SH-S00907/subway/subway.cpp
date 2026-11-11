#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;

struct Node {
	int sta;
	int gate;
};

struct Edge {
	int next;
	Node to;
	int ss;
}a[200005];

int w[200005];

int num[200005];

int b[505][505];
int t[505][505];

priority_queue< int , vector<pair<int, int> >, greater<pair<int, int> > > q;

int dis[200005];

bool vis[200005];

int head[200005];

void dij(int s) {
	q.push(make_pair(s,0));
	dis[s] = 0;
	while (!q.empty()) {
		int k = q.top().second;
		q.pop();
		if (vis[k]) {
			continue;
		}
		vis[k] = true;
		int tp = head[k];
		while (tp) {
			if (dis[k] + a[tp].ss < dis[a[tp].to]) {
				dis[a[tp].to] = dis[k] + a[tp].ss;
				q.push(make_pair(dis[k] + a[tp].ss,a[tp].to));
			}
			tp = a[tp].next;
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
		cin >> num[i];
		for (int j = 1; j <= num[i]; j++) {
			cin >> b[i][j] >> t[i][j];
		}
	}
	int cur = 0;
	for (int )
	return 0;
}
