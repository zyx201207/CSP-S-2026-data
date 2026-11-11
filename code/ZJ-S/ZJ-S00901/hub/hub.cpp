#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,k,mp[1005],dis[1005][1005],vis[1005],ans;
struct node{
	ll to;
	ll v;
	bool operator<(const node &s)const{
		return s.v<v;
	}
};
priority_queue<node>pq;
vector<int>G[1005];
void dfs(ll now){
	vis[now]=1;
	for(auto u:G[now]){
		if(mp[u]&&!vis[u])dfs(u);
	}
}bool ck(ll x){
	memset(vis,0,sizeof vis);
	memset(mp,0,sizeof mp);
	ll p=1,cnt=0,ltk=0;
	while(x){
		if(x%2)mp[p]=1;
		p++;
		x/=2;
	}for(ll i=1; i<=n; i++){
		if(!mp[i]||vis[i])continue;
		else{
			dfs(i);
			ltk++;
		}
	}if(ltk<=2)return 1;
	return 0;
}ll solve(ll x){
	memset(mp,0,sizeof mp);
	ll p=1,cnt=0,ltk=0;
	while(x){
		if(x%2)mp[++cnt]=p;
		p++;
		x/=2;
	}ll mx=0;
	for(ll i=1; i<=n; i++){
		ll mi=1e18;
		for(ll j=1; j<=cnt; j++)mi=min(mi,dis[i][mp[j]]);
		mx=max(mx,mi);
	}return mx;
}int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		for(int i=1; i<=n; i++)G[i].clear();
		ans=1e18;
		memset(dis,0x3f,sizeof dis);
		memset(vis,0,sizeof vis);
		cin>>n>>k;
		for(ll i=1,u,v; i<n; i++){
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}for(ll i=1; i<=n; i++){
			memset(vis,0,sizeof vis);
			dis[i][i]=0;
			pq.push({i,0});
			while(pq.size()){
				ll now=pq.top().to;
				ll bs=pq.top().v;
				pq.pop();
				if(vis[now])continue;
				vis[now]=1;
				for(auto u:G[now]){
					if(bs+1<dis[i][u]){
						dis[i][u]=bs+1;
						pq.push({u,dis[i][u]});
					}
				}
			}
		}for(ll i=0; i<(1<<n); i++){
			if(__builtin_popcount(i)==k){
				if(ck(i))ans=min(ans,solve(i));
			}
		}cout<<ans<<'\n';
	}return 0;
}