#include<bits/stdc++.h>
#define lint long long
#define pii pair<lint,lint>
using namespace std;
lint C,n,m,d,q,k,u,v,x,y,w[500005],dis[505];
bool isj[505][505],vis[505];
vector<pii > hs[500005],g[500005];
priority_queue<pii,vector<pii >,greater<pii > > Q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> C >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> x >> y;
			int ll = hs[x].size();
			for(int e = 0;e < ll;e++){
				pii pr = hs[x][e];
				if(isj[i][pr.first]) continue;
				g[i].push_back(make_pair(pr.first,pr.second + y));
				g[pr.first].push_back(make_pair(i,pr.second + y));
				isj[i][pr.first] = isj[pr.first][i] = true;
			}
			hs[x].push_back({i,y});
		}
	}
	while(q--){
		cin >> x >> y;
		for(int i = 1;i <= n;i++) dis[i] = 0x3f3f3f3f3f3f3f3f,vis[i] = false;
		while(!Q.empty()) Q.pop();
		int ll = hs[x].size();
		for(int e = 0;e < ll;e++) Q.push(make_pair(hs[x][e].second,hs[x][e].first)),dis[hs[x][e].first] = hs[x][e].second;
		while(!Q.empty()){
			pii pp = Q.top();
			Q.pop();
			lint dd = pp.first,xx = pp.second;
			int L = g[xx].size();
			for(int _ = 0;_ < L;_++){
				u = g[xx][_].first;
				lint W = g[xx][_].second;
				if(dis[u] > W + dd){
					dis[u] = W + dd;
					Q.push(make_pair(dis[u],u));
				}
			}
		}
		ll = hs[y].size();
		lint ans = 0x3f3f3f3f3f3f3f3f;
		for(int e = 0;e < ll;e++) ans = min(ans,dis[hs[y][e].first] + hs[y][e].second);
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}
