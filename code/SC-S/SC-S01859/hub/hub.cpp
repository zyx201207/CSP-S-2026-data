#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> G[20];
int n,k;
int c,t;
int fat[20];
int dep[20];
int res[20];
int vis[20];
int d[20];
int ans;
int dis[20][20];
void dfs0(int u,int fa,int de){
	dep[u]=de;
	fat[u]=fa;
	for(auto v:G[u]){
		if(v!=fa) dfs0(v,u,de+1);
	}
}
int ds(int xx,int yy){
	int x=xx,y=yy;
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]) x=fat[x];
	while(x!=y){
		x=fat[x];y=fat[y];
	} 
	return dep[xx]+dep[yy]-2*dep[x];
}
void dfs1(int u,int fa){
	vis[u]=1;
	for(auto v:G[u]){
		if(v!=fa&&res[v]==1) dfs1(v,u);
	}
}
void dfs(int st,int now1){
	if(now1==k){
		int cnt=0;
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=n;i++){
			if(res[i]==0) continue;
			if(!vis[i]){
				cnt++;
				if(cnt>2) return;
				dfs1(i,0);
			}
		}
		for(int i=1;i<=n;i++){
			int di=1e18;
			if(res[i]==1) continue;
			for(int j=1;j<=n;j++){
				if(res[j]==0) continue;
				di=min(di,dis[i][j]);
			}
			d[i]=di;
		}
		int bj=0;
		for(int i=1;i<=n;i++){
			bj=max(bj,d[i]);
		}
		ans=min(ans,bj);
		return;
	}
	else if(st==n+1) return;
	res[st]=1;
	dfs(st+1,now1+1);
	res[st]=0;
	dfs(st+1,now1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs0(1,0,1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) dis[i][j]=0;
				else{
					dis[i][j]=ds(i,j);
				}
			//	cout<<i<<" "<<j<<" "<<dis[i][j]<<"\n";
			}
		}
		ans=1e9;
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/