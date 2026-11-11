#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500010],k[1000],mp[1000][1000],dist[1000][1000],ans;
vector<pair<int,int> >a[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,x,t;j<=k[i];j++){
			cin>>x>>t;
			a[x].push_back(make_pair(i,t));
		}
	}
	memset(mp,0x3f,sizeof mp);
	for(int i=1;i<=n;i++) mp[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto u:a[i]){
			for(auto v:a[i]){
				if(u==v) continue;
				mp[u.first][v.first]=min(mp[u.first][v.first],u.second+v.second);
			}
		}
	}
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) dist[i][j]=mp[i][j];
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	while(q--){
		int x,y;
		ans=1e18;
		cin>>x>>y;
		for(auto u:a[x])
			for(auto v:a[y]) ans=min(ans,w[x]+w[y]+u.second+v.second+dist[u.first][v.first]);
		cout<<ans<<'\n';
	}
	return 0;
}