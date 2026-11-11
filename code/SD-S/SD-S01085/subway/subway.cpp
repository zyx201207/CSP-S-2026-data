#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, d, qq, ww[501000], disn[505][505];
//priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
vector<pair<int, int> > las[501000];
//void add(int u, int v, int w){
//	a[++tot].v = v;
//	a[tot].w = w;
//	a[tot].nxt = head[u];
//	head[u] = tot;
//}
//int mindis(int s, int e){
//	while(!q.empty())q.pop();
//	for(int i = 1;i <= m;i++) dis[i] = INT_MAX, vis[i] = 0;
//	dis[s] = 0;
//	q.push(make_pair(0, s));
//	while(!q.empty()){
//		int x = q.top().second;
//		q.pop();
//		if(x == e){
//			return dis[x];
//		}
//		if(vis[x]) continue;
//		vis[x] = 1;
//		for(int i = head[x];i;i = a[i].nxt){
//			int y = a[i].v, w = a[i].w;
//			if(dis[y] > dis[x] + w){
//				dis[y] = dis[x] + w;
//				q.push(make_pair(dis[y], y));
//			}
//		}
//	}
//	return dis[e];
//}
void mindisn(){
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				disn[i][j] = min(disn[i][j], disn[i][k] + disn[k][j]);
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int tttt;
	cin >> tttt >> n >> m >> d >> qq;
	for(int i = 1;i <= m;i++){
		cin >> ww[i];
	}
//	if(m <= 1000){
//		for(int j = 1;j <= n;j++){
//			int len;
//			cin >> len;
//			vector<pair<int, int> > v;
//			for(int j = 1;j <= len;j++){
//				int x, w;
//				cin >> x >> w;
//				v.push_back(make_pair(x, w));
//			}
//			for(int i = 0;i < v.size();i++){
//				for(int j = i + 1;j < v.size();j++){
//					int w = v[i].second + v[j].second;
//					add(v[i].first, v[j].first, w);
//					add(v[j].first, v[i].first, w);
//				}
//			}
//		}
//		while(qq--){
//			int x, y;
//			cin >> x >> y;
//			cout << mindis(x, y) + ww[x] + ww[y] << "\n";
//		}
//	}
//	else{
		memset(disn, 0x3f, sizeof(disn));
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i == j) disn[i][j] = 0;
			}
		}
		for(int j = 1;j <= n;j++){
			int len;
			cin >> len;
			for(int i = 1;i <= len;i++){
				int x, t;
				cin >> x >> t;
				for(auto y : las[x]){
					disn[j][y.second] = min(disn[j][y.second], y.first + t);
					disn[y.second][j] = min(disn[y.second][j], y.first + t);
				}
				las[x].push_back(make_pair(t, j));
			} 
		}
		mindisn();
		while(qq--){
			int x, y;
			cin >> x >> y;
			int minn = LLONG_MAX;
			for(auto xx : las[x]){
				for(auto yy : las[y]){
					minn = min(minn, disn[xx.second][yy.second] + xx.first + yy.first);
				}
			}
			cout << ww[x] + ww[y] + minn << "\n";
		}
//	}
	return 0;
}
/*
0 1 3 20 2
1 2 3
3 1 1 2 1 3 1
1 3
1 2
*/

