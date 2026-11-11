#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
void solve();
main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
}
int mask=0,bl=0;
vector<int> e[1014514];
void dfs(int u,int f){
	int cnt=0;
	for(auto v:e[u]){
		if(v==f)continue;
		dfs(v,u);
		cnt+=(((1ll<<(v-1))&mask)>0);
	}
	if(((1ll<<(u-1))&mask)>0){
		if(cnt>0)bl-=(cnt-1);
		else bl++;
	}
}
int dfs2(int u,int f){
	if(((1ll<<(u-1))&mask)>0){
		return 0;
	}
	int ans=1e18;
	for(auto v:e[u]){
		if(v==f)continue;
		ans=min(ans,dfs2(v,u));
	}
	return ans+1;
}
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	int ans=1e18;
	for(mask=0;mask<(1ll<<n);mask++){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(((1ll<<(i-1))&mask)>0)cnt++;
		}
		if(cnt!=k)continue;
		dfs(1,0);
		if(bl<=2){
			int dist=0;
			for(int i=1;i<=n;i++){
				dist=max(dist,dfs2(i,0));
			}
			ans=min(ans,dist);
		}
		bl=0;
	}
	cout<<ans<<endl;
}
//I hope everything is ok.
//good luck.
