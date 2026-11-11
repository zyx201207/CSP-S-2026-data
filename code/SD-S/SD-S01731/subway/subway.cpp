#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int c,n,m,d,q,bg,ed;
int w[20010],k[510];
int a[510][20010],t[510][20010];
int visz[20010],visln[510];
ll ans;
struct node{
	int line,tm;
};
vector<node> g[20010];
void dfs1(int u,ll tt);
void dfs2(int ln,int u,ll tt){
	for(int i=1;i<=k[ln];i++){
		if(a[ln][i]==u) continue;
		int v=a[ln][i];
		if(!visz[v]){
			visz[v]=1;
			dfs1(v,tt+t[ln][i]);
			visz[v]=0;
		}
	}
}
void dfs1(int u,ll tt){
	if(u==ed){
		tt+=w[ed];
		ans=min(ans,tt);
		return;
	}
	for(int i=0;i<g[u].size();i++){
		node j=g[u][i];
		int ln=j.line;
		if(!visln[ln]){
			visln[ln]=1;
			dfs2(ln,u,tt+j.tm);
			visln[ln]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	if(c==0) c++;
	while(c--){
		cin>>n>>m>>d>>q;
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j]>>t[i][j];
				g[a[i][j]].push_back((node){i,t[i][j]});
			}
		}
		while(q--){
			cin>>bg>>ed;
			ans=1e18;
			visz[bg]=1;
			dfs1(bg,w[bg]);
			visz[bg]=0;
			cout<<ans<<'\n';
			for(int i=1;i<=m;i++) visz[i]=0;
			for(int i=1;i<=n;i++) visln[i]=0;
		}
		for(int i=1;i<=m;i++) g[i].clear();
	}
	return 0;
}
