#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define File(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
#define LL long long
#define fi first
#define se second
const int N = 505,M = 5e5 + 10;
const LL INF = 1e17;
int n,m,d,Q;
LL mp[N][N];
vector< pair<int ,LL> > vec[M];
LL w[M];
int main(){
	IOS;
	File("subway");
	int _; cin >> _;
	cin >> n >> m >> d >> Q;
	for(int i=1;i<=m;i++)
		cin >> w[i];
	for(int i=1;i<=n;i++){
		int k; cin >> k;
		for(int j=1;j<=k;j++){
			int a; LL t;
			cin >> a >> t;
			vec[a].push_back({i,t});
		}
	}
	memset(mp,0x3f,sizeof mp);
	for(int i=1;i<=m;i++){
		int len = vec[i].size();
		for(int j=0;j<len;j++)
			for(int k=0;k<len;k++){
				int u = vec[i][j].fi; int v = vec[i][k].fi; LL w = vec[i][j].se + vec[i][k].se;
				mp[u][v] = min(mp[u][v],w);
				mp[v][u] = min(mp[v][u],w);
			}
	}
	for(int i=1;i<=n;i++)
		mp[i][i] = 0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				mp[i][j] = min(mp[i][j],mp[i][k] + mp[k][j]);
	while(Q -- ){
		LL ans = INF;
		int x,y;
		cin >> x >> y;
		for(int i=0;i<vec[x].size();i++)
			for(int j=0;j<vec[y].size();j++){
				int u = vec[x][i].fi;
				int v = vec[y][j].fi;
				LL val = vec[x][i].se + vec[y][j].se;
				ans = min(ans,val + mp[u][v] + w[x] + w[y]);
			}
		cout << ans << "\n";
	}
	return 0;
}