#include <bits/stdc++.h>

using namespace std;
#define int long long

int c,n,m,d,q;
int w[500005],k[505],x,y,f[505][505];
int a[500005];
int t[500005];

void solve() {
	for(int i = 1;i <= m; ++ i) cin >> w[i];
	for(int i = 1;i <= n; ++ i) {
		cin >> k[i];
//		int a[k[i] + 2];
//		int t[k[i] + 2];
		for(int j = 1;j <= k[i]; ++ j) {
			cin >> a[j] >> t[j];
			for(int o = 1;o < j; ++ o) {
				//cout << f[a[i][o]][a[i][j]] << " ";
				f[a[o]][a[j]] = min(f[a[o]][a[j]],t[j] + t[o]);
				f[a[j]][a[o]] = min(f[a[o]][a[j]],t[j] + t[o]);
				//cout << f[a[i][o]][a[i][j]] << " " << t[i][o] + t[i][j] << "\n";
			}
		}
	}
	for(int kk = 1;kk <= m; ++ kk) {
		for(int i = 1;i <= m; ++ i) {
			for(int j = 1;j <= m; ++ j) {
				if(i != kk && kk != j && i != j) f[i][j] = min(f[i][j],f[i][kk] + f[kk][j]);
				//cout << i << " " << j << " " << kk << " " << f[i][j] << "\n";
			}
		}
	}
	//cout << f[1][2] << " " << f[2][3] << " " << f[1][3] << "\n";
	while(q --) {
		cin >> x >> y;
		cout << f[x][y] + w[x] + w[y] << "\n";
	}
}

//void dijkstra() {
//	for(int i = 1;i <= m; ++ i) cin >> w[i];
//	vector<pair<int,int>> e[n + 5];
//	for(int i = 1;i <= n; ++ i) {
//		cin >> k[i];
//		int now,lst;
//		for(int j = 1;j <= k[i]; ++ j) {
//			cin >> now;
//			if(j != 1) {
//				e[lst].emplace_back(now,i);
//			} 
//			lst = now;
//		}
//	}
//}

map<int,int> mpf;
map<int,int> mps;

void mbj() {
	//cout << 1;
	for(int i = 1;i <= m; ++ i) cin >> w[i];
	int minn = INT_MAX;
	for(int i = 1;i <= n; ++ i) {
		cin >> k[i];
		for(int j = 1;j <= k[i]; ++ j) {
			cin >> a[j] >> t[j];
			if(i == 1) mpf[a[j]] = t[j];
			else {
				mps[a[j]] = t[j];
				if(mpf[a[j]] != 0) {
					minn = min(minn,t[j] + mpf[a[j]]);
				}
			}
		}
	}
	while(q --) {
		cin >> x >> y;
		if((mps[x] != 0 && mps[y] != 0) || (mpf[x] != 0 && mpf[y] != 0)) {
			int o = 0;
			if(mps[x] != 0) o += mps[x];
			else o += mpf[x];
			if(mpf[y] != 0) o += mpf[y];
			else o += mps[y]; 
			cout << w[x] + w[y] + o << "\n";
		} else {
			int o = 0;
			if(mps[x] != 0) o += mps[x];
			else o += mpf[x];
			if(mpf[y] != 0) o += mpf[y];
			else o += mps[y]; 
			cout << w[x] + w[y] + o + minn << "\n";
		}
	}
}

//struct edge{
//	int aa,bb,cc;
//	bool operator()(const edge& __x, const edge& __y) const { 
//		if(__x.aa != __y.aa) return __x.aa < __y.aa; 
//		else return __x.bb < __y.bb;
//	}
//};
//
//priority_queue<edge> pq;
//int vis[500005],dis[500005];
//
//void tb() {
//	for(int i = 1;i <= m; ++ i) cin >> w[i];
//	vector<pair<int,int>> v[500005];
//	int lst = 0,now = 0,tmi;
//	for(int i = 1;i <= n; ++ i) {
//		cin >> k[i];
//		for(int j = 1;j <= k[i]; ++ j) {
//			cin >> now >> tmi;
//			v[lst].emplace_back(now,i);
//		}
//	}
//	while(q --) {
//		cin >> x >> y;
//		pq.push((edge){tmi,x,0});
//		while(!pq.empty()) {
//			int lc = pq.top().aa;
//			int ly = pq.top().bb;
//			int lstb = pq.top().cc;
//			pq.pop();
//			if(vis[ly] == 1) continue;
//			else vis[ly] = 1;
//			for(auto e : v[ly]) {
//				if(lstb == 0) {
//					if(dis[e.first] > lc) {
//						dis[e.first] = lc;
//						pq.push((edge){lc,e.first,e.second});
//					} 
//				} else {
//					int ndd = (lstb == e.second ? 0 : tmi * 2);
//					if(dis[e.first] > lc + ndd) {
//						dis[e.first] = lc + ndd;
//						int osp = (ndd == 0 ? lstb : e.second);
//						pq.push((edge){lc + ndd,e.first,osp});
//					}
//				}
//			}
//		}
//		cout << dis[y] + w[x] + w[y] << "\n";
//	}
//}

signed main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(f,0x3f3f3f3f,sizeof f);
	cin >> c >> n >> m >> d >> q;
	//tb();
	if(c >= 20 && c <= 21) mbj();
	else solve();
	//if(c >= 22 && c <= 23) dxe();

	return 0;
}
/*
20 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
只能止步于此了吗 
*/
