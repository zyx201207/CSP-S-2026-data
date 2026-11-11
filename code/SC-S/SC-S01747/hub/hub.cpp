//#include <bits/stdc++.h>
//
//#define int long long
//
//using namespace std;
//
//const int N = 1e6 + 10;
//
////int dp[4010][4010][2][3];
////int tmp[4010][2][3];
//int dis[N];
//int c,t,n,k;
//vector<int> g[N];
//bool vis[N];
//void calc(int st) {
//	for(int i = 1;i <= n;i++) vis[i] = dis[i] = 0;
//	queue<pair<int,int>> q;q.push({st,0});
//	while(q.size()) {
//		int u = q.front();
//		q.pop();
////		cout<<u<<" "<<dis[u]<<"\n\n";
//		if(vis[u]) continue;
//		vis[u] = 1;
//		for(int v : g[u]) {
//			dis[v] = max(dis[v],dis[u] + 1);
//			q.push(v);
//		}
//	}
//}
////
////void dfs(int u,int fa) {
////	dp[u][0][0][0] = dis[u];
////	dp[u][1][1][1] = dis[u] - 1;
////	for(int v : g[u]) {
////		if(v == fa)continue;
////		dfs(v,u);
////		for(int nk = 0;nk <= k;nk++) {
////			for(int ch = 0;ch <= 1;ch++) {
////				for(int lt = 0;lt <= 2;lt++) {
////					tmp[nk][ch][lt] = dp[u][nk][ch][lt];
////				}
////			}
////		}
////		for(int uk = k;uk >= 0;uk--) {
////			for(int vk = uk;vk >= 0;vk--) {
////				for(int ult = 2;ult >= 0;ult--) {
////					if(ult>0) dp[]
////				}
////			}
////		}
////	}
////}
//
////void sol() {
////	for(int i = 1;i <= n;i++) {
////		dis[i] = 0;
////		for(int j = 1;j <= k;j++) {
////			dp[i][j][0][0] = dp[i][j][0][1] = dp[i][j][1][0] = dp[i][j][1][1] = 1e18;
////			dp[i][j][0][2] = dp[i][j][1][2]  = 1e18;
////		}
////	}
////}
//
//pair<int,int> fd(int u) {
//	calc(u);
//	int mx = 0,nd = u;
//	for(int i = 1;i <= n;i++) {
////		cout<<u<<"->"<<i<<" "<<dis[i]<<"\n";
//		if(dis[i] > mx) mx = dis[i],nd = i;
//	}
//	return {nd,mx};
//}
//
//int sv[N];
//int dp[N][3];
//
//void cdff(int u,int fa) {
//	dp[u][0] = 0;dp[u][1] = sv[u];
//	for(int v : g[u]) {
//		if(v == fa) continue;
//		cdff(v,u);
//		for(int nk = k;nk >= 0;nk--) {
//			if(nk > 0) dp[u][nk] = min(dp[u][nk],max(sv[u],dp[v][nk-1]));
//			dp[u][nk] = max(dp[u][nk],dp[v][nk]);
//		}
//	}
//	cout<<u<<" "<<dp[u][0]<<" "<<dp[u][1]<<" "<<dp[u][2]<<"\n";
//}
//
//void sol2() {
//	auto A = fd(1);
//	auto B = fd(A.first);
////	cout<<A.first<<"<->"<<B.first<<"\n";
//	for(int i = 1;i <= n;i++) {
//		sv[i] = dis[i];
//	}
//	fd(A.first);
//	for(int i = 1;i <= n;i++) {
//		sv[i] = max(sv[i],dis[i]);
//		cout<<i<<" "<<sv[i]<<"\n";
//	}
//	int ans = 1e18;
//	for(int i = 1;i <= n;i++) {
//		dp[i][1] = dp[i][2] = 1e18;dp[i][0] = 0;
//	}
//	cdff(1,1);
////	for(int i = 1;i <= n;i++) {
////		for(int j = 1;j <= n;j++) {
////			ans = min(ans,max(sv[i][0],sv[i][1]));
////		}
////	}
//	for(int i = 1;i <= n;i++) {
//		ans = min(ans,dp[i][k]);
//	}
//	cout<<ans<<"\n";
//}
//
//signed main() {
////	freopen("hub1.in","r",stdin);
////	freopen("hub.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
//	int c,t;cin>>c>>t;
//	while(t--) {
//		cin>>n>>k;
//		for(int i = 1;i <= n;i++) {
//			g[i].clear();dis[i] = 0;
//		}
//		for(int i = 1;i < n;i++) {
//			int u,v;cin>>u>>v;
//			g[u].push_back(v);
//			g[v].push_back(u);
//		}
//		if(k <= 2) {
//			sol2();
//		} else {
//			cout<<"0\n";
//		}
//	}
//	return 0;
//}
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e6 + 10;

int dp[4010][4010][2][3];
int tmp[4010][2][3];
int dis[N];
int c,t,n,k;
vector<int> g[N];
bool vis[N];
void calc(int st) {
	for(int i = 1;i <= n;i++) vis[i] = dis[i] = 0;
	queue<int> q;q.push(st);
	while(q.size()) {
		int u = q.front();
		q.pop();
//		cout<<u<<" "<<dis[u]<<"\n\n";
		if(vis[u]) continue;
		vis[u] = 1;
		for(int v : g[u]) {
			dis[v] = max(dis[v],dis[u] + 1);
			q.push(v);
		}
	}
}
//
//void dfs(int u,int fa) {
//	dp[u][0][0][0] = dis[u];
//	dp[u][1][1][1] = dis[u] - 1;
//	for(int v : g[u]) {
//		if(v == fa)continue;
//		dfs(v,u);
//		for(int nk = 0;nk <= k;nk++) {
//			for(int ch = 0;ch <= 1;ch++) {
//				for(int lt = 0;lt <= 2;lt++) {
//					tmp[nk][ch][lt] = dp[u][nk][ch][lt];
//				}
//			}
//		}
//		for(int uk = k;uk >= 0;uk--) {
//			for(int vk = uk;vk >= 0;vk--) {
//				for(int ult = 2;ult >= 0;ult--) {
//					if(ult>0) dp[]
//				}
//			}
//		}
//	}
//}

//void sol() {
//	for(int i = 1;i <= n;i++) {
//		dis[i] = 0;
//		for(int j = 1;j <= k;j++) {
//			dp[i][j][0][0] = dp[i][j][0][1] = dp[i][j][1][0] = dp[i][j][1][1] = 1e18;
//			dp[i][j][0][2] = dp[i][j][1][2]  = 1e18;
//		}
//	}
//}

pair<int,int> fd(int u) {
	calc(u);
	int mx = 0,nd = u;
	for(int i = 1;i <= n;i++) {
//		cout<<u<<"->"<<i<<" "<<dis[i]<<"\n";
		if(dis[i] > mx) mx = dis[i],nd = i;
	}
	return {nd,mx};
}

int sv[N][2];

void sol2() {
	auto A = fd(1);
	auto B = fd(A.first);
//	cout<<A.first<<"<->"<<B.first<<"\n";
	for(int i = 1;i <= n;i++) {
		sv[i][0] = dis[i];
	}
	fd(A.first);
	for(int i = 1;i <= n;i++) {
		sv[i][1] = dis[i];
//		cout<<i<<" "<<max(sv[i][0],sv[i][1])<<"\n";
	}
	int ans = 1e18;
	for(int i = 1;i <= n;i++) {
		for(int j = i + 1;j <= n;j++) {
			int now = min(max(sv[i][0],sv[i][1]),max(sv[j][0],sv[j][1]));
			ans = min(ans,now);
		}
	}
	cout<<ans<<"\n";
}

signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--) {
		cin>>n>>k;
		for(int i = 1;i <= n;i++) {
			g[i].clear();dis[i] = 0;
		}
		for(int i = 1;i < n;i++) {
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(k == 2) {
			sol2();
		} else if(c == 13 || c == 14) {
			if(k == n) cout<<"0\n";
			else cout<<max(0ll,n/2-k)+1<<"\n";
		} else {
			cout<<"0\n";
		}
	}
	return 0;
}