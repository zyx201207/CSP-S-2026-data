#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
int c, n, m, d, q, ai, t, k, x, y;
int a[N][N], dis[N], z[N];
bool vis[N];

void di(int x, int y){
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[x] = 0;
	vis[x] = 1;
	int u = x; 
	for(int i = 1; i <= n + m; i ++){
		if(i > 1) u = 0;
		for(int j = 1; j <= n + m; j ++){
			if(!vis[j] && dis[j] < dis[u]){
				u = j;
			}
		}
		vis[u] = 1;
		for(int j = 1; j <= m + n; j ++){
			if(a[u][j] != 0 && dis[j] > dis[u] + a[u][j]){
				dis[j] = dis[u] + a[u][j];
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i ++){
		scanf("%d", &z[i]);
	}
	for(int i = 1; i <= n; i ++){
		scanf("%d", &k);
		for(int j = 1; j <= k; j ++){
			scanf("%d %d", &ai, &t);
			a[m+i][ai] = t;
			a[ai][m+i] = t;
		}
	}
	while(q --){
		scanf("%d %d", &x, &y);
		di(x, y);
		printf("%d\n", dis[y] + z[x] + z[y]);
	}
	return 0;
}
