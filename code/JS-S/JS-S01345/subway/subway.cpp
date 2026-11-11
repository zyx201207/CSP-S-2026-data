#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,ans,x,y;
int w[505];
bool vis[505];
struct node{
	int v,t;
}e[505][505];
void dfs(int s,int u,int cnt){
	if(u==y){
		cnt+=e[u][s].t+w[y];
		ans=min(ans,cnt);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[e[u][i].v]&&e[u][i].v!=0){
			if(i==s){
				vis[e[u][i].v]=1;
				dfs(i,e[u][i].v,cnt);
				vis[e[u][i].v]=0;
			}else{
				vis[e[u][i].v]=1;
				dfs(i,e[u][i].v,cnt+e[u][s].t+e[u][i].t);
				vis[e[u][i].v]=0;
			}
		}
	}
}
/*
 0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2
*/
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int tmp=0;
		for(int j=1;j<=k;j++){
			cin>>e[tmp][i].v>>e[e[tmp][i].v][i].t;
			tmp=e[tmp][i].v;
		}
	}
	while(q--){
		cin>>x>>y;
		if(x==y){
			cout<<0<<"\n";
		}else{
			ans=1e18;
			for(int i=1;i<=n;i++){
				if(e[x][i].v!=0){
					dfs(i,x,w[x]+e[x][i].t);
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
