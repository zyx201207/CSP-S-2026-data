#include<bits/stdc++.h>
using namespace std;
const int N=20;
vector<int>v[N];
int g[N],vis[N];int n,k;
void dfs2(int x){
	vis[x]=1;
	for(int i=0;i<v[x].size();i++){
		int to=v[x][i];
		if(!vis[to]){
			dfs2(to);
		}
	}
}
bool check(){
	int sum=0;
	memset(vis,0,sizeof vis);
	for(int i=1;i<=k;i++){
		if(!vis[g[i]]){
			dfs2(g[i]);
			sum++;
		}
		if(sum>2)return 0;
	}
	if(sum>2)return 0;
	else return 1;
}
queue<int>q;
int dis[N],ans=1e9;
int vis1[N];
int bfs(){
	memset(vis,0,sizeof vis);
	memset(vis1,0,sizeof vis);
	int ma=0;
	for(int i=1;i<=k;i++)if(g[i]!=0)vis[g[i]]=1;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			memset(vis1,0,sizeof vis1);
			memset(dis,0,sizeof dis);
			q.push(i);
			vis1[i]=1;
			while(!q.empty()){
				int t=q.front();
				q.pop();
				if(vis[t]){
					ma=max(ma,dis[t]);
					break;
				}
				for(int i=0;i<v[t].size();i++){
					int to=v[t][i];
					if(!vis1[to]){
						vis1[to]=1;
						q.push(to);
						dis[to]=dis[t]+1;
					}
				}
			}
		}
	}
	return ma;
}
int vis3[N];
void dfs(int x,int cnt){
	vis3[x]=1;
	if(cnt==k){
		if(check()){
			ans=min(ans,bfs());
		}
		return ;
	}
	if(cnt>k)return ;
	for(int i=0;i<v[x].size();i++){
		int to=v[x][i];
		if(vis3[to])continue;
		dfs(to,cnt);
		g[cnt+1]=to;
		dfs(to,cnt+1);
		g[cnt+1]=0;
	}
	vis3[x]=0;
}	
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=1e9;
		v[0].push_back(1);
		for(int i=1;i<n;i++){
			int u,vv;
			cin>>u>>vv;
			v[u].push_back(vv);
			v[vv].push_back(u);
		}
		memset(vis3,0,sizeof vis3);
		dfs(0,0);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++){
			v[i].clear();
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