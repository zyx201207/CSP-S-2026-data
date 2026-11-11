#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,T,n,k,x,y,ans;
vector<int> e[N];
int fa[N],sz[N],d[N],mad[N],lb[N];
void dfs(int u){
	int p=fa[u],q=lb[p],r=lb[q];
	lb[u]=d[p]-d[q]==d[q]-d[r] ? r : p;
	d[u]=d[fa[u]]+1;
	sz[u]=1;
	mad[u]=d[u];
	for(auto v : e[u]){
		if(v!= fa[u]){
			fa[v]=u;
			dfs(v);
			sz[u]+=sz[v];
			mad[u]=max(mad[u],mad[v]);
		}
	}
}
int check(int x,int y){
	if(d[x]<d[y]) swap(x,y);
	while(d[x]>d[y]){
		if(d[lb[x]]>d[y]) x=lb[x];
		else x=fa[x];
	}
	if(x==y) return -1;
	while(x!=y){
		if(lb[x]==lb[y]) x=fa[x],y=fa[y];
		else x=lb[x],y=lb[y];
	}
	return x;
}
void search(int u,int id){
	if(sz[u]+sz[id]==k){
		int res=check(u,id);
		if(res!=-1){
			ans=min(ans,mad[u]+mad[id]-2*d[res]);
		}
	}
	if(n-sz[u]+sz[id]==k){
		int res=check(u,id);
		if(res==-1){
			ans=min(ans,mad[1]+d[u]+mad[id]);
		}
	}
	for(auto v : e[u]){
		if(v!=fa[u]) search(v,id);
	}
}

void clear(){
	for(int i=1;i<=n;i++) fa[i]=0;
	for(int i=1;i<=n;i++) sz[i]=0;
	for(int i=1;i<=n;i++) d[i]=0;
	for(int i=1;i<=n;i++) mad[i]=0;
	for(int i=1;i<=n;i++) e[i].clear();
} 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		ans=INT_MAX;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs(1);
		for(int i=1;i<=n;i++){
			search(1,i);
		}
		cout<<ans<<'\n';
		clear();
	}
	
	
	return 0;
}