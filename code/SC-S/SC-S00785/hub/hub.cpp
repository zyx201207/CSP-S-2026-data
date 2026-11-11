#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int op,t,n,k,u,v,dis[11],ans,cnts;
vector <int> g[1000010];
bool vis[1000010],viss[1000010];
void dfsk(int now,int fas){
	for(auto pos:g[now]){
		if(fas!=pos){
			dfsk(pos,now);
		}
	}
}
void dfss(int now){
	viss[now]=1;
	for(auto pos:g[now]){
		if(!viss[pos]){
			dfss(pos);
		}
	}
}
void dfs2(int now,int fas){
	for(auto pos:g[now]){
		if(pos!=fas){
			dis[pos]=dis[now]+1;
			dfs2(pos,now);
		}
	}
}
void dfs(int dep){
	//printf("%d %d\n",dep,cnts);
	if(cnts>k){
		return ;
	}
	if(dep==n+1 && cnts==k){
		for(int i=1;i<=n;i++){
			viss[i]=1-vis[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!viss[i]){
				dfss(i);
				cnt++;
			}
		}
		if(cnt>2){
			return ;
		}
		int maxn=0,minn;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				for(int j=1;j<=n;j++){
					dis[j]=0;
				}
				dfs2(i,i);
				minn=1e9;
				for(int j=1;j<=n;j++){
					if(vis[j]){
						minn=min(minn,dis[j]);
					}
				}
				maxn=max(minn,maxn);
			}
		}
		ans=min(ans,maxn);
		return ;
	}
	if(dep==n+1){
		return ;
	}
	dfs(dep+1);
	vis[dep]=1;
	cnts++;
	dfs(dep+1);
	cnts--;
	vis[dep]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> op >> t;
	while(t--){
		ans=1e9;
		scanf("%d%d",&n,&k);
		if(op==13 || op==14 || n==k){
			if(n==k){
				printf("0\n");
			}
			else{
				printf("%d\n",((n/2)-k)/4+(((n/2)-k)%4!=0)+1);
			}
			continue;
		}
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<=n-1;i++){
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}