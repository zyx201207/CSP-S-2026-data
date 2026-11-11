#include<bits/stdc++.h>
#define lon long long
#define INF 1e16
using namespace std;
const int N=2000010;
int c,t;
int n,k;
lon ans;
vector<int> d[2000010];
bool take[2000010];
int gs;
void dfs(int u,int from){
	for(int i=0;i<d[u].size();i++){
		int v=d[u][i];
		if(v==from) continue ;
		if(take[v] && !take[u]) gs++;
		dfs(v,u);
	}
	return ;
}
bool check(){
	gs=0;
	if(take[1]) gs++;
	dfs(1,0);
	if(gs>2) return false;
	return true;
}
lon minz;
void dfs2(int u,int from,int jl){
	if(take[u]) minz=min(minz,(lon)jl);
	for(int i=0;i<d[u].size();i++){
		int v=d[u][i];
		if(v==from) continue ;
		dfs2(v,u,jl+1);
	}
	return ;
}
void todo(){
	if(!check()) return ;
	lon maxz=0;
	for(int i=1;i<=n;i++){
		minz=INF;
		if(take[i]) minz=0;
		else dfs2(i,0,0);
		maxz=max(maxz,minz);
	}
	ans=min(ans,maxz);
	return ;
}
void dfs3(int w,int gs){
	if(n-w+1+gs<k) return ;
	if(w==n+1){
		if(gs!=k) return ;
		todo();
		return ;
	}
	if(gs<k){
		take[w]=1;
		dfs3(w+1,gs+1);
	}
	take[w]=0;
	dfs3(w+1,gs);
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=INF;
		for(int i=1;i<=n;i++) d[i].clear();
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			d[u].push_back(v);
			d[v].push_back(u);
		}
		dfs3(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}//¿ÉÏ§²¢·ÇÓµ±§ ()
//15
