#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,k,e[30],ans,lum,vis[30],dis[30];
vector<ll> tree[30];
void b(ll num,ll fa){
	vis[num]=1;
	for(ll j=0;j<tree[num].size();j++){
		ll i=tree[num][j];
		if(i==fa)continue;
		if(e[i])b(i,num);
	}
	return ;
}
void dfs(ll num,ll fa,ll dep){
	if(dis[num]==-1)dis[num]=dep;
	else dis[num]=min(dis[num],dep);
	for(ll j=0;j<tree[num].size();j++){
		ll i=tree[num][j];
		if(i==fa)continue;
		dfs(i,num,dep+1);
	}
	return ;
}
void solve(ll num){
	if(num>n){
		ll sum=0,_=0;
		for(ll i=1;i<=n;i++){
			if(!vis[i]&&e[i]){
				b(i,0);sum++;
			}
			_+=e[i];
		}
//		cout<<<<":";

		memset(vis,0,sizeof vis);
		memset(dis,-1,sizeof dis);
		if(sum>2||_!=k)return ;

		for(ll i=1;i<=n;i++)
			if(e[i])dfs(i,0,0);
		sum=0;
		for(ll i=1;i<=n;i++)sum=max(sum,dis[i]);
//		for(ll i=1;i<=n;i++){
//			cout<<dis[i]<<" ";
//		}cout<<"\n";
		ans=min(ans,sum);
		return ;
	}
	solve(num+1);
	e[num]=1;
	solve(num+1);
	e[num]=0;
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=LONG_LONG_MAX;
		scanf("%lld%lld",&n,&k);
		for(ll i=1;i<n;i++){
			ll u,v;
			scanf("%lld%lld",&u,&v);
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		solve(1);
		printf("%lld\n",ans);
		for(ll i=1;i<=n;i++)tree[i].clear();
	}
	return 0;
}
