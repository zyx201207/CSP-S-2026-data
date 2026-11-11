#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,k;
vector<int> v[N];
vector<int> p; 
int dep[N],fat[N][22];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	fat[x][0]=fa;
	for(int i=1;i<=20;i++) fat[x][i]=fat[fat[x][i-1]][i-1];
	for(int y:v[x]){
		if(y==fa) continue;
		dfs(y,x); 
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[fat[x][i]]>=dep[y]) x=fat[x][i];
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(fat[x][i]!=fat[y][i]) x=fat[x][i],y=fat[y][i];
	}
	return fat[x][0];
}
int dis(int x,int y){return dep[x]+dep[y]-2*dep[lca(x,y)];}
int get(){
	int mx=0;
	for(int i=1;i<=n;i++){
		int mn=1e18;
		for(int j:p) mn=min(mn,dis(i,j));
		mx=max(mx,mn); 
	}
	return mx;
}
int vis[N],usd[N];
void dfs3(int x,int fa){
	vis[x]=1;
	for(int y:v[x]){
		if(y==fa||vis[y]||!usd[y]) continue;
		dfs3(y,x);
	}
}
int ans=1e18;
void dfs2(int x,int cnt){
	if(x==n+1){
		if(cnt!=k) return;
		for(int i=1;i<=n;i++) vis[i]=0;
		int cnt=0;
		for(int i:p){
			if(!vis[i]){
				dfs3(i,0);
				cnt++;
				if(cnt>2) return;
			}
		}
		ans=min(ans,get());
		return;
	}
	if(cnt<k){
		usd[x]=1;
		p.push_back(x);
		dfs2(x+1,cnt+1);
		usd[x]=0;
		p.pop_back();
	}
	dfs2(x+1,cnt);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _,T;cin>>_>>T;
	while(T--){
		ans=1e18;
		cin>>n>>k;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x); 
		}
		dfs(1,0);
		dfs2(1,0); 
		cout<<ans<<'\n';
	}	
	return 0;
}
/*
选出 k 个关键点，要求形成不超过两个连通块。
要求树上每个点距离关键点的最小值的最大值最小。
设 f[i][j][0/1] 表示 i 的子树中，
选择了 j 个点作为关键点，形成了 1/2 个连通块的答案。
或者可以考虑二分答案，把距离每个点 <=x 的点打上标记，
看能不能选出恰好 k 个点并集为全集。
暴力枚举的话时间复杂度 O(C(n,k)nk) 15 分。
*/