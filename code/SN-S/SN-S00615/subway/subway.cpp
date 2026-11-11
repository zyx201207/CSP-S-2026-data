#include <bits/stdc++.h>
using namespace std;

int c, n , m , d, q;
int w[6767];
int  v[6767];
vector<int> a[6767][2];

bool f(int x, int i) {
	bool flame = 0;
//	for (int i = 0; i <= n; i ++) {
		for (int j = 0; j <= a[i][0].size(); j ++) {
			if (a[i][0][j] ==x ) flame = 1;
		}
//	}
	return flame;
}

//qwq
//kdwddjdkd awa
//how bfs? awa let me use dfs! oh 
		int ans = 0;
		int top = 0;
void dfs(int i, int j, int y,int ns) {
	if (i == y) {
		ans = min(ans, ns);
		
		return;
	}
//			printf("GO! \n");
	
	if (i - 1 >= 0) {
		ns += a[j][1][i - 1];
		ns += w[i - 1];
		dfs(i - 1, j, y, ns);
	}
	if (i + 1 <= a[j][1].size()) {
		ns += a[j][1][i + 1];
		ns += w[i + 1];
		dfs(i - 1, j, y, ns);
	}
	if (j - 1 >= 0) {
		ns += a[j - 1][1][i];
		ns += w[j];
		dfs(i, j - 1, y, ns);
	}
	if (j + 1 <= m) {
		ns += a[j + 1][1][i];
		ns += w[j];
		dfs(i, j + 1, y, ns);
	}
	
	
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i ++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i ++) {
		int x;
		scanf("%d", &x);
		for (int j = 1; j <= x; j ++) {
			int k, d;
			scanf("%d %d", &k, &d);
			a[i][0].push_back(k);
			a[i][1].push_back(d);
			}
		}
	
	while(q--) {
		int x, y;
		scanf("%d %d", &x, &y);
		ans += w[x] + w[y];
		for (int j = 1; j <= n; j ++) {
//			printf("GO! \n");
			for (int k = 1; k <= a[j][0].size(); k ++){
			
//			printf("GO! \n");
				if (f(a[j][0][k],j)) {
//			printf("GO! \n");
					dfs(x, j, y , 0);
//			printf("GO! \n");
				}
			}
		}
		printf("0\n");
	}
	return 0;
}
