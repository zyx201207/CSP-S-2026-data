#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n, m, a[maxn], root, cnt[maxn];
bool visited[maxn];
vector<int> g[maxn];
void dfs(int x) {
	for(int y : g[x]) {
		dfs(y);
		cnt[x] += cnt[y];
	}
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	root = a[n];
	cnt[root]++;
	visited[root] = true;
	for(int i = n - 1; i >= 1; i--) {
		cnt[a[i]]++;
		if(!visited[a[i]]) {
			visited[a[i]] = true;
			g[a[i+1]].push_back(a[i]);
		}
	}
	dfs(root);
	for(int i = 1; i <= m; i++) {
		cout << cnt[i];
		if(i == m) cout << endl;
		else cout << ' ';
	}
	return 0;
}
