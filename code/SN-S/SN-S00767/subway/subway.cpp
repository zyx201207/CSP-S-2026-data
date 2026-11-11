#include <bits/stdc++.h>
#define int long long
using namespace std;
using ary = array<int,4>;
const int N = 5e5+5;
int c,n,m,d,q;
int w[N],u[N],t[N];
int ans;
int dis[N],vis[N];
vector<array<int,4>>e[N];
void dij(int s){
	for(int i = 1;i <= m;i ++){
		dis[i] = 1e9;
		vis[i] = 0;
	}
	priority_queue<ary,vector<ary>,greater<ary>> q;
	dis[s] = 0;
	q.push({0ll,s,0ll,0ll});
	while(!q.empty()){
		auto p = q.top();
		q.pop();
		int u = p[1],id1 = p[2],lt = p[3];
		if(vis[u]){
			continue;
		}
		vis[u] = 1;
		for(auto it:e[u]){
			int v = it[0],tu = it[1],te = it[2],id2 = it[3];
			if(id1!=id2){
				if(dis[v]>dis[u]+tu+te){
					dis[v]=dis[u]+tu+te;
//					cout << id1 << " " << id2 << " " << u << " " << v << " " << dis[v] << "\n";
//					vis[v] = 1;
					q.push({dis[v],v,id2,te});
				}
			}else{
				if(dis[v]>dis[u]-lt+te){
					dis[v] = dis[u]-lt+te;
//					cout << u << " " << v << " " << dis[v] << "\n";
	//				vis[v] = 1;
					q.push({dis[v],v,id2,te});
				}
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i ++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j ++){
			cin >> u[j] >> t[j];
		}
		for(int j = 1;j < k;j ++){
			e[u[j]].push_back({u[j+1],t[j],t[j+1],i});
			e[u[j+1]].push_back({u[j],t[j+1],t[j],i});
		}
	}
//	cout << 9;
	while(q--){
		int s,e;
		cin >> s >> e;
		ans = w[s]+w[e];
		dij(s);
		int k = dis[e];
		dij(e);
		int l = dis[s];
		cout << min(l,k)+ans << "\n";
	}
	return 0;
}
/*

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 5

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


*/
