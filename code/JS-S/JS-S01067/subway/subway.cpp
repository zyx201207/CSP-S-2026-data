#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5, M=505;
int n, m, d, q, W[N], dis[M][M];
vector <pair<int,int> > v[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)cin>>W[i];
	for(int i=1; i<=n; i++){
		int s;
		cin>>s;
		while(s--){
			int x, y;
			cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1; i<=m; i++){
		for(auto y:v[i])for(auto z:v[i]){
			dis[y.first][z.first]=min(dis[y.first][z.first],y.second+z.second);
		}
	}
	for(int i=1; i<=n; i++)dis[i][i]=0;
	for(int k=1; k<=n; k++)for(int i=1; i<=n; i++)for(int j=1; j<=n; j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x, y;
		cin>>x>>y;
		int ans=1e18;
		for(auto u:v[x])for(auto z:v[y]){
			ans=min(ans,dis[u.first][z.first]+W[x]+W[y]+u.second+z.second);
		}
		cout<<ans<<'\n';
	}
	return 0;
}