#include<bits/stdc++.h>
using namespace std;
const int N=11;
int c,t,n,k;
vector<int>g[N];
void file(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
}
void input(){
	memset(g,0,sizeof(g));
	scanf("%d%d",&n,&k);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x) ;
	}
}
namespace subBUF{
	int dis[N][N];
	bool vis[N],s[N];
	void dfs(int u){
		vis[u]=true;
		for(int v:g[u])if(!vis[v] and s[v])dfs(v);
	}
	void func(){
		int rst=1e9;
		memset(dis,0x3f,sizeof(dis));
		for(int u=1;u<=n;u++){
			for(int v:g[u])dis[u][v]=1;
			dis[u][u]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int h=1;h<=n;h++){
					dis[i][j]=min(dis[i][j],dis[i][h]+dis[h][j]);
				}
			}
		}
		for(int st=0;st<(1<<n);st++){
			int pcnt=0,scnt=0,ans=0;
			for(int i=1;i<=n;i++){
				if(st&(1<<(i-1)))s[i]=true,pcnt++;
				else s[i]=false;
				vis[i]=false;
			}
			if(pcnt!=k)continue;
			for(int i=1;i<=n;i++)if(s[i] and !vis[i])scnt++,dfs(i);
			if(scnt>2)continue;
			for(int i=1;i<=n;i++){
				int tep=1e9;
				for(int j=1;j<=n;j++){
					if(s[j])tep=min(tep,dis[i][j]);
				}
				ans=max(ans,tep);
			}
			/*if(ans<rst){
				for(int i=1;i<=n;i++)if(s[i])printf("%d ",i);
				printf(":%d\n",ans);
			}*/
			rst=min(rst,ans);
		}
		printf("%d\n",rst);
	}
}
int main(){
	file();
	scanf("%d%d",&c,&t);
	while(t--){
		input();
		subBUF::func();
	}
	return 0; 
}
