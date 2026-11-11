#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 50;
int c, n, m, d, q;
int a[N];
long long dis[N];
struct Node {
	long long to, w;
};
vector<Node> e[N];

void Dij(int s) {
	queue<Node> q;
	dis[s] = 0;
	q.push({s, dis[s]});
	while(!q.empty()) {
		int x = q.front().to, w = q.front().w;
		q.pop();
		for(auto nx : e[x]) {
			if(w + nx.w <= dis[nx.to]) {
				q.push({nx.to, w + nx.w});
				dis[nx.to] = w + nx.w;
			}
		}
	}
	return ;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) {
		int k = 0, aa = 0, tt = 0;
		scanf("%d", &k);
		for(int j = 1; j <= k; j++) {
			scanf("%d%d", &aa, &tt);
			e[m + i].push_back({aa, tt});
			e[aa].push_back({m + i, tt});
		}
	}
	while(q--) {
		int s, t;
		scanf("%d%d", &s, &t);
		memset(dis, 0x3f, sizeof dis);
		Dij(s);
//		for(int i = 1; i <= n; i++) printf("%d ", dis[i]);
		printf("%lld\n", dis[t] + a[s] + a[t]);
	}
	return 0;
}