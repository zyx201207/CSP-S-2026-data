#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=505,M=5e5+5;
const ll inf=1e18;
int c,n,m,d,q;
vector<pii> vec[M];
ll f[N][N];
int w[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		while(k--){
			int a,t;cin>>a>>t;
			vec[a].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)vec[i].size();j++){
			for(int k=j+1;k<(int)vec[i].size();k++){
				int u=vec[i][j].first,v=vec[i][k].first;
				f[u][v]=f[v][u]=min(f[u][v],(ll)vec[i][j].second+vec[i][k].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		ll ans=inf;
		for(int i=0;i<(int)vec[x].size();i++){
			for(int j=0;j<(int)vec[y].size();j++){
				ans=min(ans,f[vec[x][i].first][vec[y][j].first]+vec[x][i].second+vec[y][j].second);
			}
		} 
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0; 
}
