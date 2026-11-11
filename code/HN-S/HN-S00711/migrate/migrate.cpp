#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const int N=2e6+5;
ll c,t,n,d,x[N],dis[N],vis[N];
vector<pii>e[N];
void Dijkstra(ll st){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<pii,vector<pii>,greater<pii>>q;
	dis[st]=0; 
	q.push({0,st});
	while(!q.empty()){
		auto p=q.top();q.pop();
		ll u=p.s;
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(auto edge:e[u]){
			auto v=edge.f,w=edge.s;
			if(vis[v]){
				continue;
			}
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>d){
					break;
				}
				e[i].push_back({j,x[j]-x[i]});
				e[j].push_back({i,x[j]-x[i]});
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			Dijkstra(i);
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(j==i||k==i){
						continue;
					}
					if(dis[j]==dis[k]&&j!=k){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
