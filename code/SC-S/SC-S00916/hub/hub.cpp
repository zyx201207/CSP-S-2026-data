#include<bits/stdc++.h>
using namespace std;
const int N=55;
vector<int>mask,p;
bool vis[N];
int n,k,fa[N],g[N][N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool check(int sta){
	p.clear();
	int cc=0,t=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=0;i<n;i++){
		if((1<<i)&sta){
			++cc,p.push_back(i+1);
			if(cc>k) return 0;
		}
	}
//	for(int i=0;i<p.size();i++) cout<<p[i]<<' ';
//	cout<<'\n';
	if(cc!=k) return 0;
	for(int i=0;i<p.size();i++){
		for(int j=0;j<p.size();j++)
			if(p[i]!=p[j]&&g[p[i]][p[j]]!=0x3f3f3f3f)
				fa[find(p[i])]=fa[find(p[j])];		
	}
	
	for(int i=0;i<p.size();i++)
		if(fa[p[i]]==p[i]) ++t;
//	cout<<t<<'\n';
	return t<=2;
}
void floyed(){
	for(int l=1;l<=n;l++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][l]+g[l][j]);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		mask.clear();
		int ans=0x3f3f3f3f;
		memset(g,0x3f,sizeof g);
		cin>>n>>k;
		for(int i=1;i<n;i++){
			g[i][i]=0;
			int u,v;cin>>u>>v;
			g[u][v]=1,g[v][u]=1;
		}
		for(int i=0;i<(1<<n);i++)
			if(check(i)) mask.push_back(i);
		floyed();
		for(int i=0;i<mask.size();i++){
			memset(vis,0,sizeof vis);
			p.clear();
			int ct=0;
			for(int j=0;j<n;j++)
				if((1<<j)&mask[i]) p.push_back(j+1),vis[j+1]=1;
//			for(int j=0;j<p.size();j++) cout<<p[j]<<' ';
//			cout<<'\n';
			for(int ii=1;ii<=n;ii++){
				int dis=1e9;
				if(!vis[ii]){
					for(int j=0;j<p.size();j++)
						dis=min(dis,g[ii][p[j]]);
					ct=max(ct,dis);
				}
			}
			ans=min(ans,ct);
		}
		cout<<ans<<'\n';
	}
	return 0;
}