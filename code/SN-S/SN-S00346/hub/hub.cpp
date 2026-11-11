//张芃浩 西安交通大学附属中学 SN-S00346 
#include<bits/stdc++.h>
using namespace std;
const int mx=1e9;
void chkmin(int &x,int y){
	if(y<x)x=y;
}
vector<int>to[101];
bool sel[101];
int curans=mx,n,k;
void dfs(int x,int f,int curdis){
	if(sel[x]){
		chkmin(curans,curdis);
		return;
	}
	for(int i:to[x])if(i!=f)dfs(i,x,curdis+1);
}
bool used[101];
void dfs1(int x,int f){
	used[x]=true;
	for(int i:to[x])if(i!=f&&sel[i])dfs1(i,x);
}
void work(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		to[u].push_back(v),to[v].push_back(u);
	}
	int ans=mx;
	for(int i=0;i<(1<<n);i++){
		if(__builtin_popcount(i)!=k)continue;
		for(int j=1;j<=n;j++)if((i>>(j-1))&1)sel[j]=true;
		for(int j=1;j<=n;j++)
			used[j]=false;
		int curcnt=0;
		for(int j=1;j<=n;j++)
			if(!used[j]&&sel[j])dfs1(j,0),curcnt++;
		if(curcnt>2)continue;
		int pans=0;
		for(int j=1;j<=n;j++){
			curans=mx;
			dfs(j,0,0);
			pans=max(pans,curans);
		}
		ans=min(ans,pans);
		for(int j=1;j<=n;j++)sel[j]=false;
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)to[i].clear();
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)work();
	return 0;
}
