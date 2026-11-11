#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,n,m,D,_,w[500005],dist[505][505];
vector<pair<int,int> >v[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>D>>_;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int cnt;cin>>cnt;
		for(int j=1;j<=cnt;j++){
			int x,y;cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=n;i++) dist[i][i]=0;
	for(int i=1;i<=m;i++)
		for(auto p:v[i])
			for(auto q:v[i]){
				if(p.first==q.first) continue;
				int x=p.first,y=q.first,w=p.second+q.second;
				dist[x][y]=min(dist[x][y],w);
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	while(_--){
		int x,y,ans=0x3f3f3f3f3f3f3f3f;cin>>x>>y;
		for(auto p:v[x])
			for(auto q:v[y])
				ans=min(ans,dist[p.first][q.first]+p.second+q.second);
		ans+=w[x]+w[y];
		if(x==y) ans=0;
		cout<<ans<<'\n';
	}
	return 0;
}