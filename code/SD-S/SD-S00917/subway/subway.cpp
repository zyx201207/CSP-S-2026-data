#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5;
const int inf = 1e18;

struct Node {
	int v,w;
};

int c,n,m,d,q;
int w[maxn + 100];
int ww[600];
vector<Node> e[maxn + 100];
set<int> belong[600];
int f[600][600];
//int belong[maxn + 100][30];
//int tot[maxn + 100];
signed main() {

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

//	freopen("subway7.in","r",stdin);
//	freopen("subway7.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++) {
		cin >> w[i];
	}
	
	for(int i = 1;i <= n;i ++) {
		int k;
		cin >> k;
		int u,t;
		while(k --) {
			cin >> u >> t;
			
			e[u].push_back({i,t});
			belong[i].insert(u);
		}
	}
	
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= n;j ++) {
			f[i][j] = (i == j ? 0 : inf);
		}
	}
	
	for(int i = 1;i <= m;i ++) {
		for(int j = 0;j < e[i].size();j ++) {
			for(int k = j + 1;k < e[i].size();k ++) {
				int u = e[i][j].v,v = e[i][k].v,wa = e[i][j].w,wb = e[i][k].w;
				f[u][v] = min(f[u][v],wa + wb);
				f[v][u] = min(f[v][u],wa + wb);
			}
		}
	}


	
	for(int k = 1;k <= n;k ++) {
		for(int i = 1;i <= n;i ++) {
			for(int j = 1;j <= n;j ++) {
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}

	while(q --) {
		int u,v;
		cin >> u >> v;
		int ans = inf;
		for(Node i : e[u]) {
			for(Node j : e[v]) {
				int x = i.v,y = j.v;
				ans = min(ans,f[x][y] + i.w + j.w);
			}
		}
		cout << ans + w[u] + w[v] << '\n';
	}


	return 0;
}
/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/

/*

16:30

*/
