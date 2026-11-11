#include<bits/stdc++.h>
#define int long long

using namespace std;

int read(){
	int t=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		t=t*10+ch-48;
		ch=getchar();
	}
	return t*f;
}

int c;
int T;
int n;
int k;
vector<int>G[15];

int vis[15];
int dis[15];
int x;
void dfs(int u,int fa,int sum){
	if((x>>u)&1){
		dis[u]=0;
		for(auto v:G[u]){
			if(v==fa)continue;
			dfs(v,u,0);
		}
	}else{
		dis[u]=dis[fa]+1;
		for(auto v:G[u]){
			if(v==fa)continue;
			dfs(v,u,dis[u]);
		}
	}
}

int solve(){
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	for(int i=1;i<=n;i++){
		dis[i]=1e18;
	}
	int sta;
	for(int i=1;i<=n;i++){
		if((x>>i)&1){
			sta=i;
			break;
		}
	}
	dfs(sta,0,0);
	int res=0;
	for(int i=1;i<=n;i++){
		res=max(res,dis[i]);
	}
	return res;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	c=read();
	T=read();
	
	for(int i=1;i<=T;i++){
		n=read();
		k=read();
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int ans=1e18;
		for(int i=0;i<(1<<n);i++){
			if(__builtin_popcount(i)!=k)continue;
			x=i;
			ans=min(ans,solve());
		}
	}
	
	return 0;
}
/*

*/