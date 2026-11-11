#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e6+78;
int x[N];
vector <int> G[N];
int dep[N];

void dfs(int u,int f) {
	for (int v = 0;v <= G[u].size();v++) {
		if (v == f) {
			
			return;
		}
		dfs(v,u);
		dep[u] = dep[v] - 1;
	}
}

int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while (t--) {
		int n,d;
		scanf("%d%d",&n,&d);
		for (int i = 1;i <= n;i++) {
			G[i].clear();
			dep[i] = 0;
		}
		for (int i = 1;i <= n;i++) {
			scanf("%d",&x[i]);
			for (int j = (i - d > 0) ? (i - d) : 0;j <= (i + d <= n) ? (i + d) : n;j++) {
				G[x[i]].push_back(x[j]);
				G[x[j]].push_back(x[i]);
			}
		}
		dfs(1,0);
		int cnt = 0;
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				for (int i1 = 1;i1 <= n;i1++) {
					for (int j1 = 1;j1 <= n;j1++) {
						if (dep[i1] - dep[i] == dep[j1] - dep[i] && dep[j] - dep[i1] == dep[j] - dep[j1]) {
							cnt++;
						}
					}
				}
			} 
		}
		printf("%d\n",cnt);
	}
	
	return 0;
}
