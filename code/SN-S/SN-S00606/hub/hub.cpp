#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
vector<int> a[10005];
int lg[20005];
int dfn[10005],fdfn[10005],dfnx[20005][18],de[10005],zs[10005],ldfn[10005],rdfn[10005],cntdfn,numdfn;
void dfs1(int x,int fa){
	de[x]=de[fa]+1,dfn[x]=++cntdfn,fdfn[dfn[x]]=x,dfnx[++numdfn][0]=dfn[x],ldfn[x]=numdfn;
	for(auto v:a[x]){
		if(fa==v) continue;
		dfs1(v,x);
		dfnx[++numdfn][0]=dfn[x],zs[x]=max(zs[x],zs[v]+1);
	}
	dfnx[++numdfn][0]=dfn[x],rdfn[x]=numdfn;
	return;
}
void st_set(void){
	for(int j=1;j<=18;j++){
		for(int i=1;i<=2*n-(1<<j);i++) dfnx[i][j]=min(dfnx[i][j-1],dfnx[i+(1<<j-1)][j-1]);
	}
	return;
}
int lca(int l,int r){
	if(ldfn[l]>ldfn[r]) swap(l,r);
	int len=ldfn[r]-ldfn[l];
	return fdfn[min(dfnx[ldfn[l]][lg[len]],dfnx[ldfn[r]-(1<<lg[len])+1][lg[len]])];
}
bool vis[20005],vis2[10005];
void dfs2(int x,int fa,int xl,int xr,int d,bool op){
	if(x==xl||x==xr) op=1;
	vis2[x]=op;
	for(auto v:a[x]){
		if(v==fa) continue;
		if(zs[x]!=d) dfs2(v,x,xl,xr,d,op);
	}
	return;
}
bool check(int x){
	vector<int> p;
	memset(vis,0,sizeof(vis));
	memset(vis2,0,sizeof(vis2));
	for(int i=1;i<=n;i++){
		if(zs[i]==x) p.push_back(i);
	}
	priority_queue<pair<int,pair<int,int> > > q;
	for(int i=0;i<p.size();i++){
		for(int j=i+1;j<p.size();j++){
			q.push({de[lca(p[i],p[j])],{i,j}});
		}
	}
	if(p.size()==1){
		if(k==1) return de[p[0]]-k-x<=0;
		return de[p[0]]-k-3*x<=0;
	}
	int nump=p.size()-2;
	while(--nump){
		auto v=q.top();q.pop();
		int l=v.second.first,r=v.second.second;
		if(vis[l]||vis[r]) continue;
		vis[l]=1,vis[r]=1;
		int ll=lca(l,r);
		p.push_back(ll);
		for(int i=0;i<p.size();i++){
			if(vis[i]) continue;
			q.push({de[lca(ll,p[i])],{ll,p[i]}});
		}
	}
	int xl=p[p.size()-2],xr=p[p.size()-1];
	dfs2(1,0,xl,xr,x,0);
	int yj=0,mxn=0;
	for(int i=1;i<=n;i++) yj+=vis2[i];
	for(int i=1;i<=n;i++){
		if(a[i].size()==1&&de[i]<=x) mxn=max(mxn,de[i]);
	}
	yj+=min(de[xl],de[xr])+mxn-2-x;
	return yj<=k;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	for(int i=1;i<=20000;i++) lg[i]=lg[i/2]+1;
	while(T--){
		cin>>n>>k;
		cntdfn=numdfn=0;
		for(int i=1;i<=n;i++) a[i].clear();
		memset(dfn,0,sizeof(dfn));
		memset(fdfn,0,sizeof(fdfn));
		memset(dfnx,0,sizeof(dfnx));
		memset(de,0,sizeof(de));
		memset(zs,0,sizeof(zs));
		memset(ldfn,0,sizeof(ldfn));
		memset(rdfn,0,sizeof(rdfn));
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		dfs1(1,0);
		st_set();
		int maxzs=0;
		for(int i=1;i<=n;i++) maxzs=max(maxzs,zs[i]);
		int l=0,r=maxzs;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid)) r=mid-1;
			else l=mid+1;
		}
		cout<<l<<'\n';
	}
	return 0;
}

