#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5,M = 5e2+5;
int test_num,n,m,d,q;
ll go_out[N],dist[M][M],dis[M][M];
bool vis[M];
vector<int> vec[N]; // dot
vector<pair<int,ll>> e[M]; // line
map<pair<int,int>,ll> mp; // line,dot
void dijk(int st){ // O(m ^ 2 log m)
	memset(vis,0,sizeof vis); // O(m ^ 2)
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
	dis[st][st] = 0;
	q.push({dis[st][st],st});
	while (!q.empty()){
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (pair<int,ll> i:e[u]){
			int v = i.first;
			ll w = i.second;
			if (dis[st][v] > dis[st][u] + w){
				dis[st][v] = dis[st][u] + w;
				q.push({dis[st][v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>test_num>>m>>n>>d>>q;
	for (int i = 1;i <= n;++ i){
		cin>>go_out[i];
	}
	for (int i = 1;i <= m;++ i){
		int k;
		cin>>k;
		while (k --){
			int x;
			ll t;
			cin>>x>>t;
			mp[{i,x}] = t; // line,dot
			vec[x].push_back(i); // dot -> line
		}
	}
	memset(dis,0x3f,sizeof dis);
	memset(dist,0x3f,sizeof dist);
	for (int i = 1;i <= n;++ i){ // dot
		for (int j = 0;j < vec[i].size();++ j){ // index
			for (int k = j + 1;k < vec[i].size();++ k){ // index
				int u = vec[i][j],v = vec[i][k]; // line
				ll w = mp[{u,i}] + mp[{v,i}];
				if (dist[u][v] > w){
					dist[u][v] = dist[v][u] = w;
				}
			}
		}
	}
	for (int i = 1;i <= m;++ i){ // line
		for (int j = 1;j <= m;++ j){ // line
			if (dist[i][j] >= 0x3f3f3f3f3f3f3f3f) continue;
			e[i].push_back({j,dist[i][j]});
		}
	}
	for (int i = 1;i <= m;++ i){
		dijk(i);
	}
	while (q --){
		int x,y; // dot,dot
		cin>>x>>y;
		ll ans = 0x3f3f3f3f3f3f3f3f;
		for (int i:vec[x]){ // i:line
			for (int j:vec[y]){ // j:line
				ans = min(ans,dis[i][j] + mp[{i,x}] + mp[{j,y}]);
			}
		}
		ans += go_out[x] + go_out[y];
		cout<<ans<<'\n';
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