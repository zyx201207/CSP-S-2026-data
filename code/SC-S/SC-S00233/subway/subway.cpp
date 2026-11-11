#include<bits/stdc++.h>
using namespace std;
const int N = 510, M = 500010;

int c, n, m, d, q, k, l, r, ans, ct, cn;  
int w[N], a[N][N], t[N][N], d1[5000][5000];
long long t1[N];

struct di{
	int len, g;
};
vector < di > ed[N][N];

void dfs(int x, int y, int ct){
	if (x == y){ t1[++cn] = ct; return;}
	for (int i = 1; i <= ed[x][y].size(); i++)
		dfs(ed[x][y][i].g, y, ct += ed[x][y][i].len);
	return;
}

int main(){
	cin.tie(0)->sync_with_stdio(false);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) 
		scanf("%d", &w[i]);
	for (int j = 1; j <= n; j++){
		scanf("%d", &k);
		for (int i = 1; i <= k; i++){
			scanf("%d%d", &a[j][i], &t[j][i]);
			ed[j][i].push_back({t[j][i], a[j][i]});
			ed[j][a[j][i]].push_back({t[j][i], i});
		}
	}
	
	for (int i = 1; i <= q; i++){
		scanf("%d%d", &l, &r);
		cn = 0, ct = 0;
		dfs(l, r, ans);
		sort(t1+1, t1+cn+1);
		printf("%lld\n", t1[1] + w[l] + w[r]);
	}
	return 0;
}