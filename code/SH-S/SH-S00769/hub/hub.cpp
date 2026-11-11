#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,k;
vector<int>G[1000002];
int ans=1000000000000000000;
int vis[1000002];
int v[1000002];
int check(){
	return n/2;
}
bool fdsa(int now,int last){
	
	if(v[now]) return false;
	for(auto nxt:G[now]){
		if(nxt==last||vis[nxt]==0) continue;
		bool jkl=fdsa(nxt,now);
		v[nxt]=1;
	}
	return true;
}
bool f(){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(fdsa(i,-1)) sum++;
	}
	return sum<=2;
}
void dfs(int now,int num){
	if(now==n+1){
		if(num!=k||!f()) return;
		ans=min(ans,check());
		return;
	}
	vis[now]=1;
	dfs(now+1,num+1);
	vis[now]=0;
	dfs(now+1,num);
}
void bl(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++) vis[i]=v[i]=0;
	dfs(1,0);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		bl();
		cout<<ans<<"\n";
	}
	return 0;
}
