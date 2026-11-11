#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5, M = 3e5+5;
struct node{
	int pos, val;
} b[M];
int a[N], cnt[M];
vector<int> g[N];
bool cmp(node x, node y){
	return x.pos > y.pos;
}
int ans[M];
void dfs(int u, int fa){
	int len = g[u].size();
	for(int i = 0; i < len; i++){
		int v = g[u][i];
		if(v == fa) continue;
		dfs(v, u);
		ans[u] += ans[v];
	}
	ans[u] += cnt[u];
	return;
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++) b[i].val = i;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		cnt[a[i]]++;
		b[a[i]].pos = i;
	}
	sort(b+1, b+1+m, cmp);
	int root = a[n];
	for(int i = 2; i <= m; i++){
		int pos = b[i].pos;
		g[a[pos+1]].push_back(a[pos]);
	}
	dfs(root, 0);
	for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}
