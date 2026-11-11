#include<bits/stdc++.h>
using namespace std;
const int N=1000011;
int C,T,n,k,ans=INT_MAX;
vector<int>edges[N];
void bfs(int s,int dis[]){
	queue<int>q;
	q.push(s);
	dis[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(auto y:edges[x])
			if(!dis[y]){
				dis[y]=dis[x]+1;
				q.push(y);
			}
	}
}
int dis[110][110];
bool t[N],vis[N];
void dfs2(int x){
	vis[x]=1;
	for(auto y:edges[x])
		if(t[y]&&!vis[y])
			dfs2(y);
}
void dfs(int x,int cnt){
	if(cnt>k)return;
	if(x==n+1){
		if(cnt!=k)return;
//		printf("1\n");
		vector<int>w;w.clear();
		for(int i=1;i<=n;i++){
			vis[i]=0;
			if(t[i])w.push_back(i);
		}
		int g=0;
		for(int i=1;i<=n;i++)vis[i]=0;
		for(auto i:w)
			if(!vis[i]){
				g++;
				dfs2(i);
			}
//		printf("%d\n",g);
		if(g!=2)return;
//		printf("1");
		int d2=0;
		for(int i=1;i<=n;i++)
			if(!t[i]){
				int d=INT_MAX;
				for(auto j:w)
					d=min(d,dis[i][j]-1);
				d2=max(d2,d);
			}
		ans=min(ans,d2);
		return;
	}
	t[x]=1;
	dfs(x+1,cnt+1);
	t[x]=0;
	dfs(x+1,cnt);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)edges[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			edges[x].push_back(y);
			edges[y].push_back(x);
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=0;
		for(int i=1;i<=n;i++)bfs(i,dis[i]);
		ans=INT_MAX;
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10*/
