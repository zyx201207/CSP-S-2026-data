#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll C,T,n,k,cnt,ans=2e18;
vector<ll>g[N];
ll vis[N],dis[N];
void dfs(ll u,ll s){
	for(auto t:g[u]){
		if(!vis[t]&&(s>>(t-1))&1){
			vis[t]=1;
			dfs(t,s);
		}
	}
}
void dfs2(ll u,ll f){
	for(auto t:g[u]){
		if(t!=f){
			dis[t]=min(dis[t],dis[u]+1);
			dfs2(t,u);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0);
	cin>>C>>T;
	while(T--){
		ans=2e18;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			ll u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int s=1;s<(1<<n);s++){
			ll sum=0;
			for(int i=1;i<=n;i++){
				if((s>>(i-1))&1){
					sum++;
				}vis[i]=0;
				dis[i]=2e18;
			}if(sum!=k){
				continue;
			}
			sum=0;
			for(int i=1;i<=n;i++){
				if(!vis[i]&&(s>>(i-1))&1){
					vis[i]=1;
					sum++;
					dfs(i,s);
				}
			}
//			cout<<s<<" ";
			if(sum>2){
				continue;
			}
			cnt=0;
			for(int i=1;i<=n;i++){
				if((s>>(i-1))&1){
					dis[i]=0;
					dfs2(i,0);
				}
			}for(int i=1;i<=n;i++){
				cnt=max(cnt,dis[i]);
//				cout<<dis[i]<<" ";
			}
			ans=min(ans,cnt);
//			cout<<s<<" "<<cnt<<"\n";
		}cout<<ans<<"\n";
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
	}
	return 0;
}