#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int>v[1000005];
vector<int>leaf;
int fa[1000005][21],dep[1000005];
void dfs(int x,int f){
	if(x!=1&&v[x].size()==1)leaf.push_back(x);
	fa[x][0]=f;
	dep[x]=dep[f]+1;
	for(int j=0;j<v[x].size();j++){
		if(v[x][j]==f)continue;
		dfs(v[x][j],x);
	}
}
int queryfa(int x,int dep){
	for(int j=20;j>=0;j--){
		if(dep&(1<<j))x=fa[x][j];
	}
	return x;
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	x=queryfa(x,dep[x]-dep[y]);
	if(x==y)return x;
	for(int j=20;j>=0;j--){
		if(fa[x][j]!=fa[y][j]){
			x=fa[x][j];
			y=fa[y][j];
		}
	}
	return fa[x][0];
}

int dis[20],vis[20],siz,ans;
void dfs1(int J,int x){
	vis[x]=1;
	siz++;
	for(int j=0;j<v[x].size();j++){
		int y=v[x][j];
		if(vis[y])continue;
		if(J&(1<<(y-1)))dfs1(J,y);
	}
}
void dfs2(int x,int f,int step){
	dis[x]=min(dis[x],step);
	for(int j=0;j<v[x].size();j++){
		if(v[x][j]==f)continue;
		dfs2(v[x][j],x,step+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			v[i].clear();
			for(int j=0;j<=20;j++)fa[i][j]=0;
		}
		leaf.clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,0);
		for(int j=1;j<=20;j++){
			for(int i=1;i<=n;i++)fa[i][j]=fa[fa[i][j-1]][j-1];
		}
		if(k>=n){
			cout<<0<<'\n';
			continue;
		}
		ans=n-1;
		if(c<=3){
			ans=n-1;
			for(int j=1;j<(1<<n);j++){
				if(__builtin_popcount(j)!=k)continue;
				siz=0;
				for(int i=1;i<=n;i++){
					dis[i]=n;
					vis[i]=0;
				}
				for(int x=1;x<=n;x++){
					if(j&(1<<(x-1))){
						if(!vis[x])dfs1(j,x);
					}
				}
				if(siz!=k)continue;
				for(int x=1;x<=n;x++){
					if(j&(1<<(x-1)))dfs2(x,0,0);
				}
				int sum=0;
				for(int i=1;i<=n;i++){
					sum=max(sum,dis[i]);
				}
				ans=min(ans,sum);
			}
			cout<<ans<<'\n';
			continue;
		}
		cout<<1<<'\n';
	}
	return 0;
}