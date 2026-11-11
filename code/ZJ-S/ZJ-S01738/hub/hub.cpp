#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
const int N=2e6+10;
ll c,t,n,m,d[N],vis[N];
vector<int> g[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		memset(d,0,sizeof(d));
		cin>>n>>m;
		for (ll i=1;i<=n;i++){
			g[i].clear();
		}
		ll u,v;
		for (ll i=1;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			d[u]++;
			d[v]++;
		}
		if(n==m){
			cout<<0<<"\n";
			continue;
		}
		queue<pll> q;
		ll cnt=0,ans=1;
		for (ll i=1;i<=n;i++){
			if(d[i]==1){
				q.push({i,1});
				vis[i]=1;
			}
		}
		while(q.size()){
			auto x=q.front();
			ll u=x.first,w=x.second;
			cnt++;
			ans=max(ans,w);
			if(cnt+m+ans>=n){
				break;
			}
			q.pop();
			for (ll v:g[u]){
				if(vis[v]) continue;
				q.push({v,w+1});
				vis[v]=1;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}