#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,dis[505][505],w[1000005];
vector<pair<int,int> > v[1000005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++){
		int len;
		cin>>len;
		for(int j=1,A,T; j<=len; j++) cin>>A>>T,v[A].push_back({i,T});
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1; i<=n; i++) dis[i][i]=0;
	for(int i=1; i<=m; i++) for(int j=0; j<v[i].size(); j++) for(int k=j+1; k<v[i].size(); k++){
		pair<int,int> p=v[i][j],P=v[i][k];
		dis[p.first][P.first]=min(dis[p.first][P.first],p.second+P.second);
		dis[P.first][p.first]=min(dis[P.first][p.first],p.second+P.second);
	}
	for(int k=1; k<=n; k++) for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y,ans=(int)1e18;
		cin>>x>>y;
		for(auto p:v[x]) for(auto P:v[y]) ans=min(ans,w[x]+p.second+dis[p.first][P.first]+P.second+w[y]);
		cout<<ans<<'\n';
	}
	return 0;
}