#include<bits/stdc++.h>
using namespace std;

int n,k;
int dp[2000010][5];
int fa[2000010],dis[2000010];
bool mark[2000010];
vector<int> e[2000010],leaves;

void dfs(int dot){
	bool flag=0;
	for(auto it:e[dot]){
		if(!mark[it]){
			fa[it]=dot;
			dis[it]=dis[fa[it]]+1;
			dfs(it);
			flag=1;
		}
	}
	if(flag==0)
		leaves.push_back(dot);
}

int bfs(int a,int b){
	memset(mark,0,sizeof mark);
	queue<pair<int,int>> q;
	q.push({a,0});
	mark[a]=1;
	while(!q.empty()){
		auto k=q.front();
		if(k.first==b){
			return k.second;
		}
		q.pop();
		for(auto it:e[k.first]){
			if(!mark[it]){
				mark[it]=1;
				q.push({it,k.second+1});
			}
		}
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	memset(dp,0x3f,sizeof dp);
	mark[1]=1;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&n,&k);
		int u,v;
		for(int j=1;j<=n-1;j++){
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int j=1;j<=n;j++){
		dp[j][0]=min(dp[j-1][0],dp[j-1][1]);
		int maxx=-1;
		maxx=max(i,1);
		for(int j=1;j<=n;j++){
			maxx=max(maxx,bfs(i,leaves));
		}
		dp[j][1]=dp[j][0]-maxx;
	}
	printf("%d",min(dp[k][1],dp[k][0]));
	}
	
	return 0;
}

