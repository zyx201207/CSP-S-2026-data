#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;

const int maxn=510;
const int maxm=5e5+10;
const ll inf=1e18;

int c,n,m,d,q;
ll w[maxm];
vector<pli> g[maxn+maxm];
priority_queue<pli,vector<pli>,greater<pli> > q1;
ll dis[maxn+maxm];
int vis[maxn+maxm];
queue<pli> q2;

ll dijkstra(int s,int e){
	for(int i=1;i<=m+n;i++){
		vis[i]=0;dis[i]=inf;
	}
	q1.push({0,s});
	dis[s]=0;
	while(!q1.empty()){
		pli x=q1.top();
		q1.pop();
		ll d=x.first;
		int u=x.second;
		if(vis[u])continue;
		vis[u]=1;
		for(pli y:g[u]){
			ll k=y.first;
			int v=y.second;
			if(d+k<dis[v]){
				dis[v]=d+k;
				q1.push({dis[v],v});
			}
		}
	}
	return dis[e];
}

ll bfs(int s,int e){
	for(int i=1;i<=m+n;i++){
		vis[i]=0;
	}
	ll ans=0;
	q2.push({0,s});
	vis[s]=1;
	while(!q2.empty()){
		pli x=q2.front();
		q2.pop();
		ll k=x.first;
		int u=x.second;
		if(u==e){
			ans=k;
			break;
		}
		for(pli y:g[u]){
			ll d=y.first; 
			int v=y.second;
			if(vis[v]==1)continue;
			vis[v]=1;
			q2.push({d+k,v});
		}
	}
	return ans;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,x,y,idx;
		cin>>k;
		idx=i+m;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			g[x].push_back({y,idx});
			g[idx].push_back({y,x});
		}
	}

	// for(int i=1;i<=m+n;i++){
	// 	cout<<i<<": ";
	// 	for(pli y:g[i]){
	// 		int v=y.second;
	// 		cout<<v<<' ';
	// 	}
	// 	cout<<'\n';
	// }

	if(c<=11){
		while(q--){
			int x,y;
			cin>>x>>y;
			ll ans=w[x]+dijkstra(x,y)+w[y];
			cout<<ans<<'\n';
		}
	}else if(12<=c && c<=19){
		while(q--){
			int x,y;
			cin>>x>>y;
			ll ans=w[x]+bfs(x,y)+w[y];
			cout<<ans<<'\n';
		}
	}else{
	}

	return 0;
}