#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
const ll inf=1e18;
struct qst{
	ll y;
	ll ans,idx;
};
ll c,n,m,d,Q,z[500005],ans[100005];
ll dis[600005],vis[600005];
vector<P> adj[600005];
vector<qst> qs[500005];
priority_queue<P,vector<P>,greater<P> > q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>z[i];
	}
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll y,w;
			cin>>y>>w;
			adj[m+i].push_back({w,y});
			adj[y].push_back({w,m+i});
		}
	}
	for(int i=1;i<=Q;i++){
		int x,y;
		cin>>x>>y;
		if(x>y) swap(x,y);
		qs[x].push_back({y,inf,i});
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+m;j++){
			dis[j]=inf;
			vis[j]=0;
		}
		dis[m+i]=0;
		q.push({0,m+i});
		while(!q.empty()){
			ll d=q.top().first,x=q.top().second;
			q.pop();
			if(vis[x]) continue;
			vis[x]=1;
			for(auto pr:adj[x]){
				ll w=pr.first,y=pr.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		for(auto pr:adj[m+i]){
			ll w=pr.first,x=pr.second;
			for(qst &tem:qs[x]){
				ll y=tem.y;
				tem.ans=min(tem.ans,dis[y]+w);
			}
		}
	}
	for(int x=1;x<=m;x++){
		for(qst tem:qs[x]){
			ll y=tem.y,idx=tem.idx;;
			ans[idx]=tem.ans+z[x]+z[y];
		}
	}
	for(int i=1;i<=Q;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
