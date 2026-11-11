#include<bits/stdc++.h>
#define int long long
using namespace std;
struct str{
	int nect,to,vals;
}g[1010101];
int opt,n,m,q,d,cnt,ans;
int dval[505050],head[505050];
int fa[505050],dep[505050],zise[505050],son[505050],top[505050],suval[505050];
bool used[505050];
int minn(int u,int v){
	return u<v?u:v;
}
void add(int u,int v,int w){
	cnt++;
	g[cnt].nect=head[u];
	g[cnt].to=v;
	g[cnt].vals=w;
	head[u]=cnt;
	return;
}
void dfsst(int level,int fath,int tdep,int tval){
	fa[level]=fath;
	dep[level]=tdep;
	zise[level]=1;
	suval[level]=tval;
	for(int i=head[level];i;i=g[i].nect){
		int v=g[i].to;
		if(v==fath)continue;
		dfsst(v,level,tdep+1,tval+g[i].vals);
		if(zise[son[level]]<zise[v])son[level]=v;
		zise[level]+=zise[v];
	}
	return;
}
void dfsnd(int level,int ttop){
	top[level]=ttop;
	if(son[level])dfsnd(son[level],ttop);
	for(int i=head[level];i;i=g[i].nect){
		int v=g[i].to;
		if(v==fa[level]||v==son[level])continue;
		dfsnd(v,v);
	}
	return;
}
int LCA(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	return u;
}
void dfsrd(int level,int tans,int la){
	if(level==la){
		ans=minn(ans,tans);
		return;
	}
	used[level]=true;
	for(int i=head[level];i;i=g[i].nect){
		int v=g[i].to,w=g[i].vals;
		if(used[v])continue;
		dfsrd(v,tans+w,la);
	}
	used[level]=false;
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>opt>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>dval[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,v;
			cin>>u>>v;
			add(m+i,u,v);
			add(u,m+i,v);
		}
	}
	if(d<=2){
		dfsst(1,0,1,0);
		dfsnd(1,1);
		for(int i=1;i<=q;i++){
			int u,v;
			cin>>u>>v;
			int lca=LCA(u,v);
			cout<<suval[u]+suval[v]-2*suval[lca]+dval[u]+dval[v]<<'\n';
		}
	}
	else{
		for(int i=1;i<=q;i++){
			int u,v;
			cin>>u>>v;
			ans=LLONG_MAX;
			dfsrd(u,0,v);
			cout<<ans+dval[u]+dval[v]<<'\n';
		}
	}
	return 0;
}
