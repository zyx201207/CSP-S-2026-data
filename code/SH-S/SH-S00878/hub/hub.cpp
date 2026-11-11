#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int c,t,n,k,u,v;
vector <int> cities(k);
vector <int> g[101];
int path[101][101];
int vis[101];
void dfs_path(int st,int fa,int id,int l) {
	path[st][id] = path[id][st] = l;
	for(int v : g[id]) {
		if(v==fa) continue;
		dfs_path(st,id,v,l+1);
	}
}
void findpath() {
	for(int i=1;i<=n;++i) {
		dfs_path(i,0,i,0);
	}
}
inline int lowbit(int i) {
	return i & (-i);
}
inline int cal(int i) {
	int a=0;
	while(lowbit(i)) {
		++a;
		i -= lowbit(i);
	}
	return a;
} 
bool iscity[101];
void dfs(int i,int fa) {
	vis[i] = 1;
	for(int j : g[i]) if(iscity[j] &&j!=fa) dfs(j,i);
}
void solve() {
	cin >> n >> k;
	for(int i=1;i<=n;++i) {
		g[i].clear();
	}
	for(int i=1;i<n;++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		path[u][v] = path[v][u] = 0;
	}
	findpath();
//	cout << "!!" << endl;
	int ans = 2e9;
	for(int i=0;i<pow(2,n);++i) {
		if(cal(i) != k) continue;
		
//		printf("%d\n",i);
		cities.clear();
		for(int j=n,tmp=i;j;--j,tmp>>=1) {
			if(tmp & 1) {
				cities.push_back(j);
				iscity[j] = 1;
			}
			vis[j] = 0;
		}
		int ltk = 0;
		for(int i : cities) {
			if(!vis[i]) {
				dfs(i,0);
				++ltk;
			}
		}
		if(ltk > 2) continue;
		
		int sum = 0;
		for(int j=1;j<=n;++j) {
			int tmp = 2e9;
			for(int ct : cities) tmp = min(tmp,path[j][ct]);
			sum = max(sum,tmp);
		}
		ans = min(ans,sum);
		
		for(int j : cities) iscity[j] = 0;
	}
	cout << ans << endl;
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--) solve();
}
