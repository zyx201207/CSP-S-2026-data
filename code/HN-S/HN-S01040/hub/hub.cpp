#include<bits/stdc++.h>
using namespace std;
int c,t;
int dis[1000005];
int f[1000005][35];
vector<int>g[1000005];
map<pair<int,int>,bool>ma;
void dfs(int x,int fa,int v){
	dis[x]=v;
	f[x][0]=fa;
	for(int i=1;i<=30;i++){
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(y!=fa)dfs(y,x,v+1);
	}
}
int lca(int x,int y){
	if(x==y)return x;
	if(dis[x]<dis[y])swap(x,y);
	for(int i=30;i>=0;i--){
		if(dis[f[x][i]]>=dis[y]){
			x=f[x][i];
		}
	}
	if(x==y)return x;
	for(int i=30;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return x;
}
int ji(int x,int y){
	return dis[x]+dis[y]-dis[lca(x,y)]-1;
}
int dp[1000005];
pair<int,int>b[1000005];
int id[1000005];
int ans=INT_MAX;
void dfs1(int x,int n,int k,int lian,vector<int>s){
	if(x==n+1){
		if(k!=0)return;
		int l=0;
		for(int i=1;i<=n;i++){
			if(l>=s.size()||i!=s[l]){
				ans=min(ans,dp[id[i]]);
				return;
			}
			else{
				l++;
			}
		}
		return;
	}
	dfs1(x+1,n,k,lian,s);
	for(int i=0;i<s.size();i++){
		if(ma[{x,s[i]}]||ma[{s[i],x}]){
			s.push_back(x);
			dfs1(x+1,n,k-1,lian,s);
			return;
		}
	}
	if(lian<2){
		s.push_back(x);
		dfs1(x+1,n,k-1,lian+1,s);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		ma.clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			ma[{x,y}]=true;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		memset(dis,0,sizeof(dis));
		memset(f,0,sizeof(f));
		dfs(1,0,1);
		memset(dp,0x3f,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				dp[i]=min(dp[i],ji(i,j));
				b[i].first=dp[i];
				b[i].second=i;
			}
		}
		sort(b+1,b+1+n);
		for(int i=1;i<=n;i++){
			id[b[i].second]=i;
		}
		ans=INT_MAX;
		dfs1(1,n,k,0,{});
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
	}
	return 0;
}
/*
0 1
7 1
1 2
1 3
2 4
2 5
3 6
3 7

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
