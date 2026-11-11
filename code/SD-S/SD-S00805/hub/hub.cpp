#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
using namespace std;
int c,t,n,k;
vector<int> edge[1000001];
int st[1000001][20];
int dep[1000001];
int f[1000001];
int findf(int x){
	if(!f[x])return x;
	return f[x]=findf(f[x]);
}
bool he(int x,int y){
	x=findf(x),y=findf(y);
	if(x==y)return 0;
	f[x]=y;
	return 1;
}
void dfs(int rt,int fa){
	st[rt][0]=fa;
	dep[rt]=dep[fa]+1;
	for(int i=1;i<20;i++)st[rt][i]=st[st[rt][i-1]][i-1];
	for(auto i:edge[rt]){
		if(i==fa)continue;
		dfs(i,rt); 
	}
}
int lca(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	int del=dep[y]-dep[x];
	while(del){
		y=st[y][__lg(del)];
		del^=(1<<__lg(del));
	}
	if(x==y){
		return y;
	}
	for(int i=19;i>=0;i--){
		if(st[x][i]!=st[y][i]){
			x=st[x][i];
			y=st[y][i];
		}
	}
	return st[x][0];
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
vector<int> v;
bool vis[1000001];
int ans=n+1;
bool chk(){
	int cnt=k;
	for(auto i:v){
		for(auto j:edge[i]){
			cnt-=(int)he(i,j);
		}
	}
	if(cnt<=2)return 1;
	else return 0;
}
void calc(){
	if(chk()){
		int ma=0;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			int d=n+1;
			for(auto j:v){
				d=min(d,dis(i,j));
			}
			ma=max(ma,d);
		}
		ans=min(ans,ma);
	}
}
void dfs2(int id,int cnt){
	if(cnt==k){
//		for(auto i:v)cerr<<i<<' ';
//		cerr<<'\n';
		return calc();
	}
	if(cnt+n-id+1<k)return;
	v.push_back(id);
	vis[id]=1;
	dfs2(id+1,cnt+1);
	v.pop_back();
	vis[id]=0;
	dfs2(id+1,cnt);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		ans=n+1;
		dfs(1,0);
		dfs2(1,0);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++){
			vector<int>().swap(edge[i]);
		}
	}
	return 0;
}
