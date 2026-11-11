#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int inf=1e9;
int c,T;
int n,k;
vector<int>g[N+5];
bool b[N+5];
bool vis[N+5];
void dfs1(int u,int f){
	for(int i=0;i<g[u].size();++i){
		int v=g[u][i];
		if(v==f || vis[v] || b[v]==0) continue;
		vis[v]=1;
		dfs1(v,u);
	}
}
bool check(){
	for(int i=1;i<=n;++i){
		vis[i]=0;
	}
	int res=0;
	for(int i=1;i<=n;++i){
		if(!vis[i] && b[i]){
			vis[i]=1;
			dfs1(i,0);
			res++;
		}
	}
	if(res<=2) return true;
	return false;
}
bool used[N+5];
struct node {
	int u,w;
};
int dist(int S){
	for(int i=1;i<=n;++i){
		used[i]=0;
	}
	queue<node>q;
	q.push((node){S,0});
	while(!q.empty()){
		int u=q.front().u,w=q.front().w;
		q.pop();
		for(int i=0;i<g[u].size();++i){
			int v=g[u][i];
			if(used[v]) continue;
			if(b[v]) return w+1;
			q.push((node){v,w+1});
		}
	}
	return inf;
}
int solve(){
	int ans=0;
	for(int i=1;i<=n;++i){
		if(!b[i]){
			ans=max(ans,dist(i));
		}
	}
	return ans;
}
int Ans;
void dfs(int u,int ls){
	if(k-u+1>n-ls) return ;
	if(u>k){
		if(check()){
			int res=solve();
			Ans=min(Ans,res);
		}
		return ;
	}
	for(int i=ls+1;i<=n;++i){
		b[i]=1;
		dfs(u+1,i);
		b[i]=0;
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;++i){
			g[i].clear();
			b[i]=0;
		}
		Ans=inf;
		for(int i=1;i<n;++i){
			int u,v; cin>>u>>v;
			g[u].push_back(v),g[v].push_back(u);
		}
		dfs(1,0);
		cout<<Ans<<"\n";
	}
	

	fclose(stdin);
	fclose(stdout);
	return 0;
}