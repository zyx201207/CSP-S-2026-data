#include<bits/stdc++.h>
using namespace std;
int T,n,k,i,j,x,y,mi,t,cnt[2000010],ff[2000010],fa[2000010][22],a[1000010],vis[2000010],dep[2000010];
vector<int>f[2000010];
void dfs(int fx,int Fa){
	fa[fx][0]=Fa;dep[fx]=dep[Fa]+1;
	for(int i=0;i<f[fx].size();i++){
		int sx=f[fx][i];
		if(sx==Fa)continue;
		dfs(sx,fx);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	int s=dep[x]-dep[y];
	for(int i=0;i<=20;i++)
		if((1<<i)&s)
			x=fa[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int dis(int x,int y){return dep[x]+dep[y]-2*dep[lca(x,y)];}
int find(int x){
	if(ff[x]==x)return x;
	return ff[x]=find(ff[x]);
}
bool pd(){
	t++;
	for(int i=1;i<=k;i++)
		ff[a[i]]=a[i];
	for(int i=1;i<=k;i++)
		for(int j=0;j<f[a[i]].size();j++){
			if(vis[f[a[i]][j]]){
				int x=find(a[i]);
				int y=find(f[a[i]][j]);
				if(x!=y)ff[x]=y;
			}
		}
	int sum=0;
	for(int i=1;i<=k;i++)
		if(cnt[ff[a[i]]]==t);
		else sum++,cnt[ff[a[i]]]=t;
	return sum<=2;
}
void dfs2(int t){
	if(t>k){
		if(k>2&&!pd())return ;
		int ma=0;
		for(int i=1;i<=n;i++)
			if(!vis[i]){
				int s=2e9;
			 	for(int j=1;j<=k;j++)
			 		s=min(s,dis(i,a[j]));
				ma=max(ma,s);
			}
		mi=min(mi,ma);
		return ;
	}
	for(int i=a[t-1]+1;i<=n;i++)
		if(!vis[i]){
			a[t]=i;
			vis[i]=1;
			dfs2(t+1);
			a[t]=0;
			vis[i]=0;
		}
}
main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T>>T;
	while(T--){
		cin>>n>>k;mi=2e9;
		for(i=1;i<=n;i++)f[i].clear();
		for(i=1;i<n;i++){
			cin>>x>>y;
			f[x].push_back(y);
			f[y].push_back(x);
		}
		dfs(1,0);
		for(j=1;j<=20;j++)
			for(i=1;i<=n;i++)
				fa[i][j]=fa[fa[i][j-1]][j-1];
		dfs2(1);
		cout<<mi<<"\n";
	}
	return 0;
}