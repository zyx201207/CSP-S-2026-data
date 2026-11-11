//O(md^2+2qd^2+qdn^2 log n^2)
//O md^2+2qd^2+n^3 log n^2+qd^2; 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
int lensub[505];
vector<int> a[505];
vector<int> t[505];
map<int,int> crossp[505];
vector<pair<int,int>> psubway[500005];
int edge[505][505];
vector<pair<int,int> > g[505];
int dis[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> lensub[i];
		for(int j = 1;j <= lensub[i];j++){
			int x,y;
			cin >> x >> y;
			a[i].push_back(x);t[i].push_back(y);
			crossp[i][x] = 1;
			psubway[x].push_back({i,y});
		}	
	}
	for(int i = 1;i <= m;i++){
		for(int j = 0;j < psubway[i].size();j++){
			for(int k = 0;k < psubway[i].size();k++){
				if(j == k) continue;
				int num1 = psubway[i][j].first,num2 = psubway[i][k].first,val1 = psubway[i][j].second,val2 = psubway[i][k].second;
				edge[num1][num2] = max(edge[num1][num2],val1+val2);
				edge[num2][num1] = max(edge[num2][num1],val1+val2);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(edge[i][j]) g[i].push_back({j,edge[i][j]});
//			cout << edge[i][j] << " ";
		}
//		cout << "\n";
	}
	for(int i = 1;i <= n;i++){
		int sum = 1e18;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
		for(int j = 1;j <= n;j++) dis[i][j] = 1e18;
		dis[i][i] = 0;
		q.push({0,i});
		while(!q.empty()){
			int u = q.top().second,val = q.top().first;
			q.pop();
			for(int k = 0;k < g[u].size();k++){
				int v = g[u][k].first,w = g[u][k].second;
				if(dis[i][v] > dis[i][u]+w){
					dis[i][v] = dis[i][u]+w;
					q.push({dis[i][v],v});
				}
			}
		}
	}
	while(q--){
		int u,v;
		cin >> u >> v;
		int ans = 1e18;
		bool flag = 0;
		for(int i = 0;i < psubway[u].size();i++){
			for(int j = 0;j < psubway[v].size();j++){
				int num1 = psubway[u][i].first,num2 = psubway[v][j].first,val1 = psubway[u][i].second,val2 = psubway[v][j].second;
//				if(num1 == num2){
				ans = min({ans,val1+val2+w[u]+w[v]+dis[num1][num2],val1+val2+w[u]+w[v]+dis[num2][num1]}),flag = 1;
//					cout << ans << " " << num1 << " " << num2 << " " << val1 << " " << val2 << " "<< w[u] << " " << w[v] << "\n";
//				}
			}
		}
//		if(flag){
//			cout << ans << "\n";
//			continue;
//		}
//		cout << "flag:" << ans << "\n";
		
//		cout << w[u] << " " << w[v] << " ";
		cout << ans << "\n";
	}
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
38
*/
