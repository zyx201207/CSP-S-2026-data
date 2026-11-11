#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int c,t,n,k,u,v,s,ans;
vector<int>mp[1000006];
bool vis[1000006];
void dfs(int x,int dis,int fa){
	if(ans<dis){
		ans=dis;
		s=x;
	}
	for(int i=0;i<(int)mp[x].size();i++){
		if(mp[x][i]==fa||vis[mp[x][i]]||mp[x][i]==0)continue;
		vis[mp[x][i]]=1;
		dfs(mp[x][i],dis+1,x);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d %d",&u,&v);
			mp[u].push_back(v);
			mp[v].push_back(u);
		}dfs(1,0,0);
		memset(vis,0,sizeof vis);
		ans=0;
		dfs(s,0,0);
		printf("%d\n",ans/k-1);
	}
	return 0;
}
