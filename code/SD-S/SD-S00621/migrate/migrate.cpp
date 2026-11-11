#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int a[2000005];
vector<int> g[100005];
int dis[5005][5005],cnt[5005][5005];
bool vis[5005];
void bfs(int s){
	queue<int> q;
	for(int i = 1;i <= n;i++) vis[i] = 0,dis[s][i] = 0;
	q.push(s);
	vis[s] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0;i < g[u].size();i++){
			int v = g[u][i];
			if(vis[v]){
//				if(s == 1&&v == 5) cout << u << " ";
//				if(dis[s][v] == dis[s][u]+1) cnt[s][v]++;
				continue;
			}
			dis[s][v] = dis[s][u]+1;
			vis[v] = 1;
			q.push(v);
		}
	}
}
void add(int s){
	queue<pair<int,int>> q;
	for(int i = 1;i <= n;i++) vis[i] = 0;
	q.push({s,0});
	cnt[s][s] = 1,vis[s] = 1;
	while(!q.empty()){
		int u = q.front().first,val = q.front().second;
		q.pop();
//		cout << u << " " << val << " " << dis[s][u]<< "\n";
		for(int i = 0;i < g[u].size();i++){
			int v = g[u][i];
			if(val+1 == dis[s][v]) cnt[s][v]++;
//			if(vis[v]) continue;
			q.push({v,val+1});
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> a[i];
		for(int i = 1;i <= n;i++){
			g[i].clear();
			int j = i+1;
//			if(i == 9) cout << j << " " << a[j]-a[i] << "\n";
			while(a[j]-a[i] <= d&&j <= n){
//				if(i == 9) cout << j << " " << a[j]-a[i] << "\n";
				g[i].push_back(j);
				j++;
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++) cnt[i][j] = 0;
		}
		for(int ii = 1;ii <= n;ii++){
			bfs(ii);add(ii);
//			for(int i = 0;i < g[ii].size();i++) cout << g[ii][i] << " ";
//			cout << "\n";
		}
//		cout << dis[1][2] << "\n";
//		cout << "\n";
		int ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
//				cout << cnt[i][j] << " ";
				if(cnt[i][j] == 2){
					ans++;
//					cout << i << " " << j << " " << cnt[i][j] << "\n";
				}
			}
//			cout << "\n";
//			cout << ans << " ";
		}
		cout << ans << "\n";
	}
}
/*
0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

0 3 6 7 8 9 10 11 14 17
*/
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


*/
