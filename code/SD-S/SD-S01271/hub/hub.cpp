#include<bits/stdc++.h>
using namespace std;
vector<int> e[15];
int a[15];
int vis[15];
int num[15];
void dfs(int x,int fa,int cnt){
	if(vis[x])return;
	vis[x]=cnt;
	for(int i=0;i<e[x].size();i++){
		if(e[x][i]!=fa){
			if(vis[e[x][i]]==0 && a[e[x][i]]==1){
				dfs(e[x][i],x,cnt);
			}
		}
	}
}
int ans;
void dfs1(int x,int fa,int len,int tott){
//	printf("x=%d ",x);
	for(int i=0;i<e[x].size();i++){
		if(e[x][i]!=fa){
			if(a[e[x][i]]==1)
			num[tott]=min(num[tott],len+1);
			else
			dfs1(e[x][i],x,len+1,tott);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n-1;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int mamam=INT_MAX;
		for(int T=1;T<=pow(2,n);T++){
			memset(vis,0,sizeof(vis));
			memset(a,0,sizeof(a));
			int ii=T,now=0;
			while(ii){
				a[++now]=ii%2;
				ii/=2;
			}
			int sum=0;
			for(int i=1;i<=n;i++)
				sum+=a[i];
			if(sum!=k){//标记k个点 
				continue;
			}
			int col=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1 && vis[i]==0){
					++col;
					dfs(i,i,col);
				}
			}
			if(col>2)//构成不超过两个联通块 
			continue;
			ans=0;
			for(int i=1;i<=n;i++)
			num[i]=INT_MAX;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					num[i]=0;
					continue;
				}
				dfs1(i,i,0,i);
			}
			for(int i=1;i<=n;i++){
				ans=max(ans,num[i]);
			}
			mamam=min(mamam,ans);
		}
		printf("%d\n",mamam);
		for(int i=1;i<=n;i++)
		e[i].clear();
		memset(vis,0,sizeof(vis));
	}
	return 0;
}
