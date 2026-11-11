#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> v[1000005];
/*
int dp[1000005],ht[1000005],dep[1000005];
void dfs1(int x,int fa){
	ht[x]=1;dep[x]=dep[fa]+1;
	for(auto to:v[x]){
		if(to!=fa){
			dfs1(to,x);
			ht[x]=max(ht[x],ht[to]+1);
		}
	}
}
void dfs2(int x,int fa,int r){
	dp[x]=1;
	for(auto to:v[x]){
		if(to!=fa){
			dfs2(to,x,r);
			if(ht[to]>r)dp[x]+=dp[to];
		}
	}
}
int up[1000005];bool vis[1000005];
void bfs(int rt){
	for(int i=1;i<=n;i++)vis[i]=0;up[rt]=0;
	queue<int> qu;qu.push(rt);vis[rt]=1;
	while(qu.size()){
		int x=qu.front(),to;qu.pop();
		int premax=0;
		for(int i=0;i<(int)v[x].size();i++){
			to=v[x][i];if(vis[to])continue;
			up[to]=max(up[x],premax)+1;
			premax=max(premax,ht[to]);
		}premax=0;
		for(int i=v[x].size()-1;i>=0;i--){
			to=v[x][i];if(vis[to])continue;
			up[to]=max(up[to],premax+1);
			premax=max(premax,ht[to]);
			qu.push(to);vis[to]=1;
		}
	}
}
bool check(int r){
	for(int rt=1;rt<=n;rt++){
		dfs1(rt,0);
		bfs();dfs2(rt,0,r);
		if(dp[rt]<=k)return 1;
	}
	return 1;
}
*/
bool p[1000005],vis[1000005];
int dis[1000005];
void dfs1(int x,int fa){
	vis[x]=1;
	for(auto to:v[x]){
		if(to!=fa&&p[to]){
			dfs1(to,x);
		}
	}
}
int check(){
	int col=0;
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]&&p[i]){
			col++;dfs1(i,0);
		}
	}
	if(col>2)return 0x3f3f3f3f;
	queue<int> q;
	for(int i=1;i<=n;i++)vis[i]=0,dis[i]=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		if(p[i]){
			q.push(i);vis[i]=1;dis[i]=0;
		}
	}
	while(q.size()){
		int x=q.front();q.pop();
		for(auto to:v[x]){
			if(!vis[to]){
				vis[to]=1;
				dis[to]=dis[x]+1;
				q.push(to);
			}
		}
	}
	int ans=0;
	//for(int i=1;i<=n;i++)cout<<dis[i];cout<<'\n';
	for(int i=1;i<=n;i++)ans=max(ans,dis[i]);return ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<n;i++){
			int a,b;cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(int i=1;i<=n-k;i++)p[i]=0;
		for(int i=n-k+1;i<=n;i++)p[i]=1;
		int ans=n+1;
		do{
			//for(int i=1;i<=n;i++)cout<<p[i];cout<<'\n';
			ans=min(ans,check());
		}while(next_permutation(p+1,p+n+1));
		cout<<ans<<'\n';
	}
	return 0;
}
