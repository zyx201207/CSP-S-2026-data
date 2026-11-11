#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> p,r;
	DSU(int n) : p(n),r(n,0){ iota(p.begin(),p.end(),0)} 
	int find(int x) { whilt (p[x] != x) { p[x] = p[p[x]]; x = p[x]; } return x;}
	bool un(int a, int b){
		a = find(a); b = find(b);
		if (a == b) return false;
		if (r[a] < r[b]) p[a] = b;
		else { p[b] = a; if (r[a] == r[b]) r[a]++;}
		return true;
	}
};
int main() {
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	int n,m; cin >> n >> m;
	vector<tuple<long long,int,int>> edges;
	edges,reserve(n + m);
	
	for(int i = 1;i <= n; i++){
		long long c; cin >> c;
		edges.emplace_back(c,0,i);
	}
	for(int i = 0; i < m; i++){
		int u,v; long long w;
		cin >> u >> v >> w;
		edges.emplace_back(w,u,v);
	}
	
	sort(edges.begin(),edges.end());
	DSU dsu(n + 1);
	long long ans = 0, cnt = 0;
	
	for(auto &[w,u,v] : edges){
		if(dsu.un(u,v)){
			ans += w;
			cnt++;
			if(cnt == n) break;
		}
	}
	cout << ans << '\n';
	return 0;
} 
