//邓洛克 SN-S00324 西安市铁一中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,a[500005],dis[505][505];
vector<pair<int,int>> vec[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> a[i];
	for(int i = 1,x;i <= n;i++){
		cin >> x;
		for(int j = 1,a,t;j <= x;j++){
			cin >> a >> t;
			vec[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i = 1;i <= n;i++) dis[i][i] = 0;
	for(int i = 1;i <= m;i++){
		for(int j = 0;j < vec[i].size();j++){
			for(int k = 0;k < vec[i].size();k++){
				int x = vec[i][j].first,y = vec[i][k].first,z = vec[i][j].second + vec[i][k].second;
				dis[x][y] = min(dis[x][y],z);
				dis[y][x] = min(dis[y][x],z);
			}
		}
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		} 
	}
	while(q--){
		int x,y,ans = 1e18;
		cin >> x >> y;
		for(auto i : vec[x]){
			for(auto j : vec[y]){
				ans = min(ans,i.second + j.second + dis[i.first][j.first]);
			}
		}
		cout << ans + a[x] + a[y] << '\n';
	}
	return 0;
}
