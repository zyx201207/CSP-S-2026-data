#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10; 
ll c,t;
ll n,k,ans;
vector<ll> road[N];
vector<ll> rec;
bool use[N],vis[N];
ll fa[N];
ll get(ll x){
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
queue<pair<ll,ll> > q;
void bfs(){
	for(ll i=1;i<=n;i++) vis[i]=0;
	for(auto i:rec){
		q.push({i,0});
		vis[i]=1;
	}
	ll maxn=0;
	while(!q.empty()){
		ll u=q.front().first,dis=q.front().second;
		q.pop();
		maxn=max(maxn,dis);
		for(auto v:road[u]){
			if(vis[v]) continue;
			vis[v]=1;
			q.push({v,dis+1});
		}
	}
	ans=min(ans,maxn);
	return;
}
bool check(){
	for(auto i:rec) fa[i]=i;
	for(auto i:rec){
		for(auto j:road[i]){
			if(!use[j]) continue;
			ll u=get(i),v=get(j);
			if(u!=v) fa[u]=v;
		}
	}
	ll cnt=0;
	for(auto i:rec) if(i==fa[i]) cnt++;
	return cnt<=2; 
}
void dfs(ll now,ll cnt){
	if(now>n){
		if(cnt!=k) return;
		if(!check()) return;
		bfs();
		return;
	}
	if(cnt+(n-now+1)<k) return;
	if(cnt==k){
		dfs(n+1,cnt);
		return;
	}
	rec.push_back(now);
	use[now]=1;
	dfs(now+1,cnt+1);
	rec.pop_back();
	use[now]=0;
	dfs(now+1,cnt);
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c>=13 && c<=14){
		while(t--){
			cin>>n>>k;
			for(ll i=1;i<=n;i++) road[i].clear();
			for(ll i=1;i<n;i++){
				ll u,v;
				cin>>u>>v;
				road[u].push_back(v);
				road[v].push_back(u);
			}
			ll m=(n-1)/2;
			if(k==n) cout<<"0\n";
			else if(k>=m) cout<<"1\n";
			else cout<<(m+1-k)/3+1<<"\n";
		}
	}else{
		while(t--){
			cin>>n>>k;
			for(ll i=1;i<=n;i++) road[i].clear();
			for(ll i=1;i<n;i++){
				ll u,v;
				cin>>u>>v;
				road[u].push_back(v);
				road[v].push_back(u);
			}
			ans=INT_MAX;
			dfs(1,0);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
