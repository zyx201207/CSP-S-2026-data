#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
bool cho[10010];
int d[10010],fa[10010];
vector<int> g[100010];
void dfs1(int x,int f){
	fa[x]=f;
	d[x]=d[f]+1;
	for(int i=0;i<g[x].size();++i){
		if(g[x][i]!=f){
			dfs1(g[x][i],x);
		}
	}
}
int ret=0x3f3f3f3f;
int lca(int x,int y){
	int tmp=x;
	map<int,int> vx,vy;
	while(tmp){
		vx[tmp]=1;
		tmp=fa[tmp];
	}
	tmp=y;
	while(tmp){
		vy[tmp]=1;
		tmp=fa[tmp];
	}
	vector<int> v;
	for(int i=1;i<=n;++i)
		if(vx[i]&&vy[i])
			v.push_back(i);
	int maxx=0,id=0;
	for(int i=0;i<v.size();++i)
		if(maxx<d[v[i]]){
			maxx=d[v[i]];
			id=v[i];
		}
	return id;
}
int dist(int x,int y){
	return d[x]+d[y]-2*d[lca(x,y)];
}
void work(){
	int cnt=0;
	for(int i=1;i<=n;++i)
		cnt+=(cho[i]==1);
	if(cnt!=k)	return;
	vector<int> choo;
	for(int i=1;i<=n;++i)
		if(cho[i])
			choo.push_back(i);
	int ans=0;
	for(int i=1;i<=n;++i){
		int diss=0x3f3f3f3f;
		for(int j=0;j<choo.size();++j)
			diss=min(diss,dist(i,choo[j])); 
		ans=max(ans,diss);
	}
	ret=min(ret,ans);
}
void dfs2(int x){
	if(x==n){
		work();
		return;
	}
	cho[x+1]=true;
	dfs2(x+1);
	cho[x+1]=false;
	dfs2(x+1);
}
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(0);
	cout<<ret<<endl;
	for(int i=1;i<=n;++i)
		g[i].clear();
	ret=0x3f3f3f3f;
}
int main(){
	freopen("hub.in","r",stdin); freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		solve();
	}
}
