#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e6+5;
const int mod=1e9+7;
ll c,n,m,d,q,lsu,tot;
ll w[N];
ll dis[N];
int vis[N];
int cnt[N];
int p[N];
struct v{
	int u;
	ll t;
};
vector<v> sub[N]; 
struct node{
	int u;
	ll dis;
	bool operator > (const node &a)const {
		return dis>a.dis;
	}
};
struct mp{
	int u;
	ll t;
};
vector<mp> a[N];
void dijkstra(int s){
	priority_queue<node,vector<node>,greater<node>> q;
	memset(dis,0x3f3f3f3f3f3f3f3fLL,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		int f=q.top().u;q.pop();
		if(vis[f])continue;
		vis[f]=1;
		for(auto v:a[f]){
			int u=v.u;
			ll w=v.t;
			if(dis[u]>dis[f]+w){
				dis[u]=dis[f]+w;
				q.push({u,dis[u]});
			}
		}	
	}
}
ll get(int u){
	return u+2*m+tot*20+cnt[u];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		ll k;cin>>k;
		for(int j=1;j<=k;j++){
			ll u;ll t;cin>>u>>t;
			cnt[u]++;
			if(cnt[u]>=2)
			{
				if(!p[u])tot++,p[u]=1;
				sub[i].push_back({get(u),t});
			}else{
				sub[i].push_back({u,t});
			}
			if(cnt[u]>=2){
				a[get(u)].push_back({u+m,t});
				a[u+m].push_back({get(u),t});
			}else{
				a[u].push_back({u+m,t});
				a[u+m].push_back({u,t});
			}
			if(j>=2){
				if(cnt[u]>=2){
					a[get(u)].push_back({lsu,0});
					a[lsu].push_back({get(u),0});
				}else{
					a[u].push_back({lsu,0});
					a[lsu].push_back({u,0});
				}
			}if(cnt[u]>=2){
				lsu=get(u);
			}else lsu=u;
		}
	}
	while(q--){
		int s,t;cin>>s>>t;
		ll ans=w[s]+w[t];
		dijkstra(s+m);
		cout<<ans+dis[t+m]<<'\n';
	}
	return 0;
}
