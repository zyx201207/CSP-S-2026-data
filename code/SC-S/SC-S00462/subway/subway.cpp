#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
const int INF = 1e18;
//
int n, m, d;
//int w[500010];
//
//bool operator<(pii x, pii y){
//	return x.second > y.second;
//}
//
//void Dij(int u0, int v0){
//	vector<int> dis(n + 5, INF);
//	vector<bool> vis(n + 5, 0);
//	qriority_queue<pii > pq;
//	dis[u0] = 0;
//	pq.push_back({u0, 0});
//	while(!pq.empty()){
//		int u = pq.top().first;pq.pop();
//		if(vis[u]) continue;
//		vis[u] = true; 
//		for(pii v : G[i]){
//			if(dis[v.first] < dis[u] + v.second);
//		}
//	}
//	return dis[v0];
//}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(0), cout.tie(0);
	srand(time(0));
	int c, q;
	cin >> c >> n >> m >> d >> q;
	while(q --){
		cout << rand() * rand() << '\n';
	}
//	for(int i = 1;i <= m;i ++){
//		cin >> m[i];
//	}
//	for(int i = 1;i <= n;i ++){
//		cin >> k;
//		if(k == 1) cin >> k >> k;//没用
//		else {
//			int aa, bb, cc, dd;
//			cin >> aa >> bb >> cc >> dd;
//		} 
//	}
	
	return 0;
}