#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+1145;
const int M = 512;
int c, n, m, d, q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
int w[N], k[N];
map<int, int> t[N];
int e[M][M];
vector<int> st[N];//第i个地铁站连接的线路
int dis[M][M];//两地铁站之间距离
map<int, int> vis[M];
vector<int> e2[N];//点i和哪些点有有效连线 
void dijk(int s){
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	dis[s][s]=0;
	pq.push({0, s});
	while(pq.size()){
		auto x = pq.top();
		pq.pop();
		int d = x.first;
		int p = x.second;
		if(vis[s][p]==1)continue;
		vis[s][p]=1;
		for(int i : e2[p]){
			if(dis[p][i]==0)continue;
			if(dis[s][i]>dis[s][p]+e[p][i]){
				dis[s][i]=dis[s][p]+e[p][i];
				dis[i][s]=dis[s][i];
				pq.push({dis[p][i], i});
			}
		}
	}
	return;
} 
main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 0;i < M;i++)for(int j = 0;j < M;j++){
		dis[i][j]=1e18;
		e[i][j]=1e18;	
	}
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			int a;
			cin >> a;
			cin >> t[i][a];
			st[a].push_back(i);
		}
	}
	for(int i = 1;i <= m;i++){
		for(int i1 = 0;i1 < st[i].size();i1++){
			for(auto i2 = i1+1;i2 < st[i].size();i2++){
				int _1 = st[i][i1], _2 = st[i][i2];
				e[_1][_2]=min(e[_1][_2], t[ st[i][i1] ][i]+t[ st[i][i2] ][i]);
				e[_2][_1]=min(e[_2][_1], t[ st[i][i2] ][i]+t[ st[i][i1] ][i]);
				e2[_1].push_back(_2);
				e2[_2].push_back(_1);
			}
		}
	}
	
	for(int i = 1;i <= n;i++)dijk(i);
	for(int i = 1;i <= q;i++){
		int x, y;
		cin >> x >> y;
		int ans = 1e18;
		for(int i1 : st[x]){
			for(int i2 : st[y]){
				ans = min(dis[i1][i2]+t[i1][x]+t[i2][y], ans);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
