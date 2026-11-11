#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2010;
ll c,n,m,d,q,x,y,si[N],sj[N],id[N][N],w[N],k[N],a,t,idx,dis[N],dis1[N][N],vis[N];
vector<pair<ll,ll> > g[N],s[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a>>t;
			si[++idx]=i;
			sj[idx]=a;
			id[i][j]=idx;
			s[a].push_back({idx,t});
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<k[i];j++){
			g[id[i][j]].push_back({id[i][j+1],0});
			g[id[i][j+1]].push_back({id[i][j],0});
		}
	}
	for(ll i=1;i<=m;i++){
		for(pair<ll,ll> v : s[i]){
			for(pair<ll,ll> v2 : s[i]){
				if(v.first<=v2.first) continue;
				g[v.first].push_back({v2.first,v.second+v2.second});
				g[v2.first].push_back({v.first,v.second+v2.second});
			}
		}
	}
	for(ll i=1;i<=idx;i++){
		memset(dis,63,sizeof(dis));
		memset(vis,0,sizeof(vis));
		dis[i]=0;
		priority_queue<pair<ll,ll> >q;
		q.push({0,i});
		while(q.size()){
			ll now=q.top().second;
			q.pop();
			if(vis[now]) continue;
			vis[now]=1;
			for(pair<ll,ll> v : g[now]){
				if(dis[v.first]>dis[now]+v.second){
					dis[v.first]=dis[now]+v.second;
					//cout<<v.first<<" ";
					q.push({dis[v.first],v.first});
				}
			}
		}
		for(ll j=1;j<=idx;j++) dis1[i][j]=dis[j];
	}
	while(q--){
		cin>>x>>y;
		ll ans=LLONG_MAX;
		for(pair<ll,ll> v1 : s[x]){
			for(pair<ll,ll> v2 : s[y]){
				ans=min(ans,v1.second+v2.second+dis1[v1.first][v2.first]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
