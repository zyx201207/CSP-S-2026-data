#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 510;
const int M = 5e5 + 10;

int c,n,m,d,q,w[M];
int k[N];
vector<pair<int,int>> vis[N];
int dis[N][N];
vector<pair<int,int>> xl[M];
/*
vis 是否经过j地铁站
t 去到j地铁站的时间
dis 从线路i换乘j需要的时间
*/

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++) {
		cin>>w[i];
	}
	for(int i = 1;i <= n;i++) {
		cin>>k[i];
		for(int j = 1;j <= k[i];j++) {
			int na,nt;cin>>na>>nt;
			xl[na].push_back({i,nt});
			vis[i].push_back({na,nt});
		}
		sort(vis[i].begin(),vis[i].end());
	}
	// cout<<"OK\n";
	memset(dis,0x3f,sizeof dis);
	for(int i = 1;i <= n;i++){
		dis[i][i] = 0;
	}
	for(int i =1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			int pj = 0;
			for(int nk = 0;nk < k[i];nk++) {
				while(pj < k[j] && vis[j][pj].first < vis[i][nk].first) {
					pj++;
				}
				// first >= vis[i][nk];
				if(pj < k[j] && vis[j][pj].first == vis[i][nk].first) {
					int nww = vis[i][nk].second + vis[j][pj].second;
					if(dis[i][j] > nww) dis[i][j] = dis[j][i] = nww;
				}
			}
		}
	}
	for(int k = 1;k <= n;k++) {
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++) {
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q--) {
		int xr,yr;cin>>xr>>yr;
		int ans = 1e18;
		for(int i = 0;i < (int)xl[xr].size();i++) {
			for(int j = 0;j < (int)xl[yr].size();j++) {
				auto u = xl[xr][i],v = xl[yr][j];
				int now = dis[u.first][v.first] + u.second + v.second;
				ans = min(ans,now);
			}
		}
		ans = ans + w[xr] + w[yr];
		cout<<ans<<"\n";
	}
	return 0;
}
/*
g++ '/home/user/work/csps/down/subway/subway.cpp' -o '/home/user/work/csps/down/subway/subway' -Wall
/usr/bin/time '/home/user/work/csps/down/subway/subway'
diff '/home/user/work/csps/down/subway/subway.out' '/home/user/work/csps/down/subway/subway.ans'
*/