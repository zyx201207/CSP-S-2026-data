#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;

int a[N],n,k,ans=INT_MAX,t,vis[1000],C,c[N],dis[N];
vector<int> g[N];

inline void col(int x){
	dis[x]=1;
	for(int k=0;k<(int)g[x].size();k++){
		int e=g[x][k];
		if(c[e]&&dis[e]==-1) col(e);
	}
	return;
}

inline void calc(){
	queue<int> q;
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++)
		if(!c[i]) vis[i]=-1;
		else vis[i]=0,q.push(i);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int k=0;k<(int)g[now].size();k++){
			int e=g[now][k];
			if(vis[e]==-1){
				vis[e]=vis[now]+1;
				q.push(e);
			}
		}
	}
	return;
	
};

inline void dfs(int x,int cnt){
	if(x==n+1){
		if(cnt!=k) return;
		int sum=0LL;
		for(int i=1;i<=n;i++) dis[i]=-1;
		for(int i=1;i<=n;i++){
			if(c[i]&&dis[i]==-1){
				sum++;
				col(i);
			}
		}
		if(sum>2) return;
		sum=0;
		calc();
		for(int i=1;i<=n;i++) sum=max(sum,vis[i]);
		ans=min(ans,sum);
		return;
	}
	c[x]=0;dfs(x+1,cnt);
	if(cnt<k){
		c[x]=1;
		dfs(x+1,cnt+1);
	}
	return;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&C,&t);
	if(C<=3){
		while(t--){ans=INT_MAX;
			scanf("%lld%lld",&n,&k);
			for(int i=1;i<=n;i++) g[i].clear();
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
				g[u].push_back(v),g[v].push_back(u);
			}
			dfs(1,0);
			printf("%lld\n",ans);
		}
	}
	if(C==7){
			while(t--){ans=INT_MAX;
			scanf("%lld%lld",&n,&k);
			for(int i=1;i<=n;i++) g[i].clear();
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
				g[u].push_back(v),g[v].push_back(u);
			}
			for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
				if(i!=j){
					c[i]=c[j]=1;
					dfs(n+1,2);
					c[i]=c[j]=0;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
