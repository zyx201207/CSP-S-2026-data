#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e2 + 10,M = 5e5 + 10;
const ll inf = LLONG_MAX;
int c,n,m,d1,q;
int w[M];
vector<int >a[M];
vector<int >spnd[N];
int t[N][M];
ll d[N][N];
void dij(int s){
	priority_queue<pair<ll,int > >q;
	q.push({0ll,s});
	for(int i = 1;i <= n;i ++)d[s][i] = (i == s?0ll:inf); 
	int viss[N],vis[M];
	memset(viss,0,sizeof(viss));
	memset(vis,0,sizeof(vis));
	viss[s] = 1;
	while(q.size()){
		int u = q.top().second;
		q.pop();
		viss[u] = 1;
		for(int i = 0;i < spnd[u].size();i ++){
			int nd = spnd[u][i];
			if(vis[nd])continue;
			vis[nd] = 1;
//			cout << 3 << endl;
			for(int j = 0;j < a[nd].size();j ++){
				if(a[nd][j] == u || viss[a[nd][j]])continue;
				int to = a[nd][j];
//				cout << 1 << endl;
				if(d[s][to] > d[s][u] + t[u][nd] + t[to][nd]){
					d[s][to] = d[s][u] + t[u][nd] + t[to][nd];
					q.push({-d[s][to],to});
				}
//				cout << 2 << endl;
			}
//			cout << 4 << endl;
		}
	}
//	cout << 5 << endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d1 >> q;
	for(int i = 1;i <= m;i ++)cin >> w[i];
	for(int i = 1;i <= n;i ++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j ++){
			int s;
			cin >> s;
//			cout << s << endl;
			cin >> t[i][s];
//			cout << t[i][s] << ' ' << i << ' ' << s << endl;
			spnd[i].push_back(s);
			a[s].push_back(i);
		}
	}
	for(int i = 1;i <= n;i ++){
		dij(i);
//		for(int j = 1;j <= n;j ++){
//			cout << d[i][j] << ' ';
//		}
//		cout << endl;
	}
	while(q --){
		int x,y;
		ll ans = LLONG_MAX;
		cin >> x >> y; 
		for(int i = 0;i < a[x].size();i ++){
			for(int j = 0;j < a[y].size();j ++){
				int u = a[x][i],v = a[y][j];
//				cout << d[u][v] << ' ' << t[u][x] << ' ' << u << ' ' << x << endl;
				ans = min(ans,d[u][v] + t[u][x] + t[v][y]);
			}
		}
//		cout << w[x] << ' ' << w[y] << ' ' << ans << endl;
		cout << ans + w[x] + w[y]<< endl;
	}
	return 0;
} 
