#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int n, m, a[N], ans, b[N];

bool cmp(int x, int y){
	return x > y;
}

void dfs(int h, int now){
	if(now == m + 1 || h == n + 1){
		int c = b[1];
		for(int i = 2; i <= m; i++)
			c = (c & b[i]);
		ans = max(ans, c);
		return ;
	}
	if(h == n + 1) return ;
	b[now] = a[h];
	dfs(h + 1, now + 1);
	b[now] = 0;
	dfs(h + 1, now);
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	dfs(1, 1);
	printf("%d", ans);
	return 0;
}