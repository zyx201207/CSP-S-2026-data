#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e4 + 8;
int c, n, m, d, q, st, ed, ans;
int w[N], len0[N], f[N];
bool vis[N], flag;
struct Node{
	int v, w;
};
vector<Node> g[N];

//int find(int x) {
//	if(f[x] == find(x)) return f[x];
//	return f[x] = find(x);
//}

void dfs(int x) {
	if(x == ed) {
//		cout<<x<<endl;
		flag = 1;
		return ;
	}
	vis[x] = 1;
	for(Node en: g[x]) {
		int vv = en.v;
		if(vis[vv] == 1) continue;
		vis[vv] = 1;
		dfs(vv);
		if(flag == 1) {
//			cout<<x<<endl;
//			cout<<en.w<<endl;
			ans += en.w;
			return ;
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) f[i] = i;
	for(int i=1; i<=m; i++) {
		cin>>len0[i+n];
	}
	
	for(int i=1; i<=n; i++) {
		int ci; cin>>ci;
		while(ci--) {
			int u, w; 
//			scanf("%d%d", &u, &w);
			cin>>u>>w;
			g[i].push_back({n+u, w});
			g[n+u].push_back({i, w});
//			cout<<i<<' '<<i+u<<endl;
		}
	}
	
//	cout<<endl;
//	for(int i=1; i<=n+m; i++){
//		for(Node en: g[i]) {
//			cout<<en.v<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	for(int i=1; i<=q; i++) {
		for(int j=1; j<=m+n; j++) vis[j] = 0;
		ans = 0, flag = 0;
		cin>>st>>ed;
		st += n;
		ed += n;
//		cout<<st<<' '<<ed<<endl;
		dfs(st);
		cout<<ans + len0[st] + len0[ed]<<endl;
	}
	
	
	return 0;
}
