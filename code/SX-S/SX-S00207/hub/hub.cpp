#include <bits/stdc++.h>
using namespace std;

const int mxn = 505, mxm = 500005, mxq = 100005, mxv = mxn + mxm * 2, mxe = 3 * mxm, inf = 0x3f3f3f3f;
int c, n, m, d, q;
int head[mxv], to[mxe], nex[mxe], w[mxe], tot;
int tmpw[mxm], line[mxn][mxm], ques[mxq][2];
int zhanting[mxm], ditiekou[mxm], zhankou[mxn];
int dis[mxv], vis[mxv];

void init() {
	memset(head, -1, sizeof(head));
	tot = 0;
}

void add(int u, int v, int ww) {
	to[tot] = v;
	nex[tot] = head[u];
	head[u] = tot;
	w[tot] = ww;
	tot++;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	init();
	
	cin >> c >> n >> m >> d >> q;
//	cout << c << ' ' << n << ' ' << m << ' ' << d << ' ' << q << '\n';
	
	for (int i = 1; i <= m; i++) {
		cin >> tmpw[i];
	}
	
//	for (int i = 1; i <= m; i++) {
//		cout << tmpw[i] << ' ';
//	}
//	cout << '\n';
	
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		
		for (int j = 1; j <= k; j++) {
			int a, t;
			
			cin >> a >> t;
			
			line[i][a] = t;
		}
	}
	
//	for (int i = 1; i <= n; i++) {
//		for (int a = 1; a <= m; a++) {
//			cout << i << ", " << a << ", " << line[i][a] << '\n';
//		}
//	}	
	
	for (int i = 1; i <= q; i++) {
		cin >> ques[i][0] >> ques[i][1];
	}
	
	int cnt = 1;
	
	for (int i = 1; i <= m; i++) {
		ditiekou[i] = cnt;
		cnt++;
	}
	
	for (int i = 1; i <= m; i++) {
		zhanting[i] = cnt;
		cnt++;
	}
	
	for (int i = 1; i <= n; i++) {
		zhankou[i] = cnt;
		cnt++;
	}
	
	// 站厅与地铁口的通道
	for (int i = 1; i <= m; i++) {
		add(ditiekou[i], zhanting[i], tmpw[i]);
		add(zhanting[i], ditiekou[i], tmpw[i]);
	}

	// 每个地铁站的站厅到线路的站口的通道
	for (int i = 1; i <= n; i++) {
		for (int a = 1; a <= m; a++) {
			if (line[i][a] != 0) {
				add(zhankou[i], zhanting[a], line[i][a]);
				add(zhanting[a], zhankou[i], line[i][a]);
			}
		}
	}

//	for (int u = 1; u <= cnt; u++) {
//		cout << u << ": ";
//		
//		for (int i = head[u]; i != -1; i = nex[i]) {
//			cout << "{" << to[i] << ", " << w[i] << "}";
//		}
//		
//		cout << "\n";
//	}

	for (int i = 1; i <= q; i++) {
		for (int j = 1; j < cnt; j++) {
			dis[j] = inf;
		}
		
//		for (int i = 1; i <= cnt; i++) {
//			cout << dis[i] << '\n';
//		}
		
		memset(vis, 0, sizeof(vis));
		int start = ditiekou[ques[i][0]];
		int end = ditiekou[ques[i][1]];
		
		priority_queue<pair<int, int>> que;
		dis[start] = 0;
		que.push({0, start});
		
		while (!que.empty()) {
			int u = que.top().second;		
			que.pop();
			
			if (vis[u]) {
				continue;
			}
			
//			cout << "hello\n";
			
			vis[u] = 1;
			
			for (int j = head[u]; j != -1; j = nex[j]) {
				int v = to[j], ww = w[j];
				
//				cout << "hello\n";
				
				if (dis[v] > dis[u] + ww) {
					dis[v] = dis[u] + ww;
					
//					cout << "hello\n";
					
					que.push({-dis[v], v});
				}
			}
		}
		
		cout << dis[end] << '\n';
	}
	return 0;
}
