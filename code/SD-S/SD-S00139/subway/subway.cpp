#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<pair<int,int>> g[500005];
int tim[505][20005];
int vis[505][20005];
int w[500005];
int k[505];
int a[505][20005];
int t[505][20005];
int ans=0x3f3f3f3f;
void dfs(int pos,int line,int sum,int end){
	if(pos==end){
		if(sum+w[pos]+tim[line][pos]<ans){
			ans=sum+w[pos]+tim[line][pos];
		}
		return ;
	}
	for(auto x:g[pos]){
		int v=x.first;
		int v_line=x.second;
		if(v_line==line){
			if(vis[v_line][v]==0){
				vis[v_line][v]=1;
				dfs(v,v_line,sum,end);
				vis[v_line][v]=0;		
			}
		}
		else{
			if(vis[v_line][v]==0){
				vis[v_line][v]=1;
				dfs(v,v_line,sum+tim[line][pos]+tim[v_line][pos],end);
				vis[v_line][v]=0;
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
			tim[i][a[i][j]]=t[i][j];
		}
		g[a[i][1]].push_back({a[i][2],i});
		g[a[i][k[i]]].push_back({a[i][k[i]-1],i});
		for(int j=2;j<=k[i];j++){
			g[a[i][j]].push_back({a[i][j-1],i});
			g[a[i][j]].push_back({a[i][j+1],i}); 
		}
	}
	for(int i=1;i<=q;i++){
		ans=0x3f3f3f3f;
		int x,y;
		scanf("%d%d",&x,&y);
		for(auto u:g[x]){
			vis[u.second][x]=1;
			dfs(x,u.second,w[x]+tim[u.second][x],y);
			vis[u.second][x]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}
