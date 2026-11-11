#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
int ID,n,m,d,ca;
ll w[500005];
vector<pair<int,ll> >p[500005];
ll dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>ID>>n>>m>>d>>ca;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,u,v,t;i<=n;i++){
		cin>>u;
		while(u--) cin>>v>>t,p[v].emplace_back(i,t);
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=(i!=j)*inf;
	for(int i=1;i<=m;i++){
		int t=p[i].size();
		for(int j=0;j<t;j++) for(int k=j+1;k<t;k++){
			int u=p[i][j].first,v=p[i][k].first;
			dis[u][v]=dis[v][u]=min(dis[u][v],p[i][j].second+p[i][k].second);
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
	while(ca--){
		int u,v;
		cin>>u>>v;
		ll res=inf;
		for(auto [x,tx]:p[u]) for(auto [y,ty]:p[v]) res=min(res,tx+ty+dis[x][y]);
		cout<<res+w[u]+w[v]<<"\n";
	}
	return 0;
}