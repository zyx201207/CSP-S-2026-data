#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,k,dp[4005][4005];
//vector<vector<ll>>dp;
vector<ll>edge[1000005],son[1000005];
void dfs1(ll u,ll fa){
	for(ll v:edge[u]){
		if(v!=fa){
			son[u].push_back(v);
			dfs1(v,u);
		}
	}
}
ll dfs(ll u,ll dd){
	if(son[u].empty()){
		dp[u][1]=0;
		dp[u][0]=1;
		return 0;
	}
	ll unn[4005]={0};
	for(ll v:son[u]){
		if(dfs(v,dd))unn[dfs(v,dd)]=1;
	}
	for(ll kk=0;kk<=k;kk++){
		if(unn[kk])continue;
		ll fi=-1,se=-1;
		for(ll v:son[u]){
			if(dp[v][kk]>fi){
				se=fi;
				fi=dp[v][kk];
			}else if(dp[v][kk]>se){
				se=dp[v][kk];
			}
			ll yy=0;
			for(ll v:son[u]){
				yy+=dp[v][kk];
			}
			if(yy>k)return kk;
		}
		if(fi+se+1>dd){
			if(kk+1<=k){
				dp[u][kk+1]=0;
				dp[u][kk]=1e18;
			}else{
				return kk;
			}
		}else{
			dp[u][kk+1]=0;
			dp[u][kk]=fi+1;
		}
		//cerr<<u<<kk<<dp[u][kk]<<endl;
	}
	return 0;
}
bool check(ll dd){
	return !dfs(1,dd);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(dp,0x3f,sizeof dp);
		cin>>n>>k;
		//dp.resize()
		for(ll i=1,u,v;i<=n-1;i++){
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		dfs1(1,0);
		ll l=0,r=n+1;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(check(mid)){
				r=mid;
			}else l=mid+1;
		}cout<<l<<'\n';
		for(ll i=0;i<=n;i++){
			edge[i].clear();
			son[i].clear();
		}//for(ll i=1;i<=n;i++)dp[i].clear();
	}
	return 0;
}
