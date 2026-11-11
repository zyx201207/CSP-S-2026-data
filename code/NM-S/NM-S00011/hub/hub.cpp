#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,d[1000005],f[1000005][25],dep[1000005],ans=0x3f3f3f3f,tq[1000005],fus[1000005];
vector<int>a[1000005];
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int j=21;j>=0;j--)if(dep[f[x][j]]>=dep[y])x=f[x][j];
	if(x==y)return x;
	for(int j=21;j>=0;j--)if(f[x][j]!=f[y][j])x=f[x][j],y=f[y][j];
	return f[x][0];
}
int dis(int x,int y){return dep[x]+dep[y]-2*dep[lca(x,y)];}
int r(int x){return fus[x]==x?x:fus[x]=r(fus[x]);}
bool check(){
	int i;
	memset(fus,0,sizeof fus);
	for(i=1;i<=k;i++)fus[d[i]]=d[i];
	for(i=1;i<=k;i++)for(int j:a[d[i]])if(fus[j]&&r(j)!=r(d[i]))fus[r(j)]=r(d[i]);
	int b1=0,b2=0;
	for(i=1;i<=k;i++)if(!b1)b1=fus[d[i]];else if(b1!=fus[d[i]]&&!b2)b2=fus[d[i]];else if(b1!=fus[d[i]]&&b2!=fus[d[i]])return false;
	return true;
}
int prog(){
	if(!check())return 0x3f3f3f3f;
	int i,j;
	memset(tq,0x3f,sizeof tq);
	for(i=1;i<=n;i++)for(j=1;j<=k;j++)tq[i]=min(tq[i],dis(i,d[j]));
	int res=0;
	for(i=1;i<=n;i++)res=max(res,tq[i]);
	return res;
}
void dfs(int p,int c){
	if(p>n&&c==k){
		ans=min(ans,prog());
		//~ for(int i=1;i<=k;i++)cout<<d[i]<<' ';
		//~ cout<<'\n';
		//~ cout<<ans<<'\n';
		return;
	}
	if(p>n)return;
	d[c+1]=p;
	dfs(p+1,c+1);
	dfs(p+1,c);
	return;
}
void build(int p,int fa){
	dep[p]=dep[fa]+1;
	f[p][0]=fa;
	for(int v:a[p])if(v!=fa)build(v,p);
	return;
}
int main(){
	int i,j;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=0x3f3f3f3f;
		for(i=1;i<=n;i++)a[i].clear();
		for(i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		build(1,0);
		for(j=1;j<=21;j++)for(i=1;i<=n;i++)f[i][j]=f[f[i][j-1]][j-1];
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
