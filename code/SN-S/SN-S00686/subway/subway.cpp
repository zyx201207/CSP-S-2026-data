#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int M = 5e5 + 10;
int c, n, m, d, q;
int w[M];
vector<int> sta[21000];
int ra[505][21000];
ll ret = 0x3f3f3f3f;
int vis[21000];

void dfs(int now, int r, ll va) {
	if (now == r) {
		ret = min(ret, va);
		return;
	}
	int len = sta[now].size();
//	cout << len << "   ";
	for (int i = 1; i <= len; i++) {
		for (int j = 1; j <= m; j++) {
			if (ra[i][j] != 0 && vis[j] == 0) {
//				cout << j << "   ";
				vis[j] = 1;
				dfs(j, r, va + 1ll*ra[i][now]);
				vis[j] = 0;
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
	}
	if (n < 20005) {
		for (int i = 1; i <= n; i++) {
			int k;
			scanf("%d", &k);
			for (int j = 1; j <= k; j++) {
				int s, t;
				scanf("%d%d", &s, &t);
				sta[s].push_back(i);
				ra[i][s] = t;
			}
		}
		
		while (q--)	 {
			int l, r;
			scanf("%d%d", &l, &r);
			memset(vis, 0, sizeof(vis));
			dfs(l, r, 0);
			printf("%lld\n", ret + 1LL*w[l] + 1LL*w[r]);
		}
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

