#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
int n, m;
int a[N];
int fa[M], num[M], ans[M], cot[M];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		fa[a[i]] = -1;
		num[a[i]]++;
	}
	for(int i = n; i >= 1; i--) if(fa[a[i]] == -1) fa[a[i]] = a[i + 1];
	for(int i = 1; i <= m; i++) cot[fa[i]]++;
//	for(int i = 1; i <= m; i++) cout << fa[i] << " ";
//	cout << "\n";
	queue<int> topo;
	for(int i = 1; i <= m; i++) if(!cot[i]) topo.push(i);
	while(topo.size()) {
		int u = topo.front();
		topo.pop();
		ans[u] += num[u];
		ans[fa[u]] += ans[u];
		cot[fa[u]]--;
		if(!cot[fa[u]] && fa[u]) topo.push(fa[u]);
	} 
	for(int i = 1; i <= m; i++) {
		cout << ans[i];
		if(i != m) cout << " ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
