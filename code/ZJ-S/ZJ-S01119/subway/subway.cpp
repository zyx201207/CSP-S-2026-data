#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=20010;
ll c,n,m,d,Q,i,j,x,y,k[N],w[N];
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
vector<ll> v[N],g[N],dis[N],vis[N];
void dij(ll x){
	ll fx,i,sx,sb;
	q.push({0,x});dis[x][x]=0;
	while(!q.empty()){
		fx=q.top().second;q.pop();
		if(vis[x][fx])continue;
		vis[x][fx]=1;
		for(i=0;i<v[fx].size();i++){
			sx=v[fx][i];sb=dis[x][fx]+g[fx][i];
			if(sb<dis[x][sx]){
				dis[x][sx]=sb;
				q.push({sb,sx});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=n;i++){
		cin>>k[i];
		for(j=1;j<=k[i];j++){
			cin>>x>>y;
			v[x].push_back(m+i);
			v[m+i].push_back(x);
			g[x].push_back(y);
			g[m+i].push_back(y);
		}
	}
	if(m<=1000){
		for(i=1;i<=m;i++)
			dis[i].resize(m+n+1,2e18),vis[i].resize(m+n+1),dij(i);
	}
	while(Q--){
		cin>>x>>y;
		if(m>1000)dis[x].resize(m+n+1,2e18),vis[x].resize(m+n+1),dij(x); 
		cout<<dis[x][y]+w[x]+w[y];
		if(Q!=0)cout<<"\n";
	}
	return 0;
}

