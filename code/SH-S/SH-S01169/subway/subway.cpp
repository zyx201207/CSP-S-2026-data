#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N=515, M=5e5+15;
int w[M], c, n, m, h, qs, s, t, d[N+M], st[N+M];
vector<pair<int, int>> g[N+M];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
void dij(){
	d[s]=0;
	q.push({0, s});
	while(q.size()){
		pair<int, int> dn; dn=q.top();
		int dis=dn.first, num=dn.second; q.pop();
		if(st[num]) continue;
		st[num]=1;
		for(pair<int, int> dn : g[num]){
			int x=dn.first, j=dn.second;
			if(d[x]>d[num]+j){
				d[x]=d[num]+j; q.push({d[x], x});
			}
		}
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> h >> qs;
	for(int i=1; i<=m; i++) cin >> w[i];
	for(int i=1; i<=n; i++){
		int k; cin >> k;
		while(k--){
			int x,y; cin >> x >> y;
			g[m+i].push_back({x, y});
			g[x].push_back({m+i, y});
		}
	}
	while(qs--){
		memset(st, 0, sizeof st); memset(d, 0x3f3f3f3f, sizeof d);
		cin >> s >> t;
		dij();
		cout << w[s]+w[t]+d[t] << '\n';
	}
	return 0;
} 
