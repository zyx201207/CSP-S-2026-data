#include<bits/stdc++.h>
#define ll long long
#define pa pair<int,int>
#define fi first
#define se second
#define N 1000050
using namespace std;
vector<int>g[N];
int edgeu[N],edgev[N];
int n,k;
namespace pinbao{
	map<pa,int>zj;
	map<pa,int>zc;
	int zuichang(int u,int fa){
		if(zc.count(make_pair(u,fa)))return zc[make_pair(u,fa)];
		zc[make_pair(u,fa)]=0;
		int siz=g[u].size();
		for(int i=0;i<siz;i++){
			int v=g[u][i];
			if(v==fa)continue;
			zc[make_pair(u,fa)]=max(zc[make_pair(u,fa)],zuichang(v,u)+1);
		}
		return zc[make_pair(u,fa)];
	}
	int zhijing(int u,int fa){
		if(zj.count(make_pair(u,fa)))return zj[make_pair(u,fa)];
		zj[make_pair(u,fa)]=0;
		int siz=g[u].size();
		int chang=0;
		for(int i=0;i<siz;i++){
			int v=g[u][i];
			if(v==fa)continue;
			zj[make_pair(u,fa)]=max(zj[make_pair(u,fa)],zhijing(v,u));
			zj[make_pair(u,fa)]=max(zj[make_pair(u,fa)],chang+zuichang(v,u)+1);
			chang=max(chang,zuichang(v,u)+1);
		}
		return zj[make_pair(u,fa)];
	}
	void solve(){
		zj.clear();zc.clear();
		int ans=1e9;
		for(int i=1;i<n;i++){
			int num=max(zhijing(edgeu[i],edgev[i]),zhijing(edgev[i],edgeu[i]));
			ans=min(ans,(num+1)/2);
		}
		printf("%d\n",ans);
		return;
	}
}
int zuiyuan[N],ciyuan[N],shang[N];
int shuyu[N];
int tong[N],you1[N],you2[N];
int zhengzaizuo;
void dfs1(int u,int fa){
	shuyu[u]=zhengzaizuo;
	int siz=g[u].size();
	zuiyuan[u]=0,ciyuan[u]=0;
	shang[u]=0;
	for(int i=0;i<siz;i++){
		int v=g[u][i];
		if(v==fa)continue;
		dfs1(v,u);
		int xin=zuiyuan[v]+1;
		if(xin>zuiyuan[u]){
			ciyuan[u]=zuiyuan[u];
			zuiyuan[u]=xin;
		}
		else if(xin>ciyuan[u]){
			ciyuan[u]=xin;
		}
	}
	return;
}
void dfs2(int u,int fa){
	int siz=g[u].size();
	int maxn=shang[u]+1;
	for(int i=0;i<siz;i++){
		int v=g[u][i];
		if(v==fa)continue;
		shang[v]=max(shang[v],maxn);
		maxn=max(maxn,zuiyuan[v]+2);
	}
	maxn=shang[u]+1;
	for(int i=siz-1;i>=0;i--){
		int v=g[u][i];
		if(v==fa)continue;
		shang[v]=max(shang[v],maxn);
		maxn=max(maxn,zuiyuan[v]+2);
	}
	for(int i=0;i<siz;i++){
		int v=g[u][i];
		if(v==fa)continue;
		dfs2(v,u);
	}
	return;
}
void jisuan(int uu,int vv,int &ans){
	zhengzaizuo=1;
	dfs1(uu,vv);dfs2(uu,vv);
	zhengzaizuo=2;
	dfs1(vv,uu);dfs2(vv,uu);
	for(int i=1;i<=n;i++){
		if(shang[i]>zuiyuan[i]){
			ciyuan[i]=zuiyuan[i];
			zuiyuan[i]=shang[i];
		}
		else if(shang[i]>ciyuan[i]){
			ciyuan[i]=shang[i];
		}
	}
	for(int i=0;i<=n;i++){
		tong[i]=you1[i]=you2[i]=0;
	}
	for(int i=1;i<=n;i++){
		tong[ciyuan[i]]++;
		if(shuyu[i]==1)you1[ciyuan[i]]=1;
		else you2[ciyuan[i]]=1;
	}
	int you11=0,you22=0,num=0;
	for(int i=n;i>=1;i--){
		num+=tong[i];
		you11|=you1[i];
		you22|=you2[i];
		if(num+(you11^1)+(you22^1)>k)break;
		ans=min(ans,i);
	}
	return;
}
void solve(int Ceshidian){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
		edgeu[i]=u;edgev[i]=v;
	}
	if(k==2){
		pinbao::solve();
		return;
	}
	int ans=1e9;
	if(Ceshidian==13||Ceshidian==14){
		int m=n/2;
		for(int i=max(m/2-10,1);i<=min(m/2+10,m);i++){
			jisuan(i,i+1,ans);
		}
		return;
	}
	else {
		for(int i=1;i<n;i++){
			jisuan(edgeu[i],edgev[i],ans);
		}
	}
	printf("%d\n",ans);
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;scanf("%d%d",&c,&t);
	while(t--){
		solve(c);
	}
	return 0;
}
