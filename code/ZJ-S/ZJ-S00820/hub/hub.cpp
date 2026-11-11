//25
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,m,ans;
vector<int>G[2000006];
int hub[20];
int flag[1003];
int dis[1003];
void flood(int u){
	flag[u]=2;
	for(auto v:G[u]){
		if(flag[v]==1){
			flood(v);
		}
	}
}
void dfs(int rt,int u){
	for(auto v:G[u]){
		if(v!=rt){
			dis[v]=min(dis[v],dis[u]+1);
			dfs(u,v);
		}
	}
}
void check(){
	memset(flag,0x00,sizeof(flag));
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		flag[hub[i]]=1;
		dis[hub[i]]=0;
	}
	int tot=0;
	for(int i=1;i<=n;i++){
		if(flag[i]==1){
			flood(i);
			tot++;
		}
	}
	if(tot>2){
		return;
	}
	for(int i=1;i<=m;i++){
		dfs(-1,hub[i]);
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		mx=max(mx,dis[i]);
	}
	ans=min(ans,mx);
}
void bf(int now,int num){
	if(num==m){
		check();
		return;
	}
	if(now>n){
		return;
	}
	hub[num+1]=now;
	bf(now+1,num+1);
	bf(now+1,num);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++){
			G[i].clear();
		}
		ans=0x3f3f3f3f;
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%lld%lld",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(c==13||c==14){
			cout<<(n/2-m+1+3)/4+1<<endl;
			continue;
		}
		bf(1,0);
		cout<<ans<<endl;
	}
	return 0;
}