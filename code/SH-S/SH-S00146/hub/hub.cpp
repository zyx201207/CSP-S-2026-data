#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
vector<int> to[N];
int vis[N],id[N];
int n,k,Min=1e9+5,Max=0;
int root(int u){
	return id[u]==u?u:id[u]=root(id[u]);
}
void dfs2(int u,int fa,int sum){
	if(vis[u]){
		Max=min(Max,sum);
		return ;
	}
	for(int i=0;i<to[u].size();i++){
		int v=to[u][i];
		if(v==fa)continue;
		dfs2(v,u,sum+1);
	}
	return ;
}
void add(){
	for(int i=1;i<=n;i++)id[i]=i;
	int sum=k;
	for(int u=1;u<=n;u++){
		for(int i=0;i<to[u].size();i++){
			int v=to[u][i];
			if(!vis[u]||!vis[v])return ;
			int ru=root(u),rv=root(v);
			if(ru!=rv){
				id[ru]=rv,sum--;
			}
		}
	}
	if(sum>2)return ;
	int f=0;
	for(int i=1;i<=n;i++){
		Max=1e9+5;
		dfs2(i,0,0);
		f=max(f,Max);
	}
	Min=min(Min,f);
	return ;
}
void dfs(int i,int cnt){
	if(i==n+1&&cnt==k)
		add();
	if(i>n)return ;
	if(cnt>k)return ;
	dfs(i+1,cnt);
	vis[i]=1;
	dfs(i+1,cnt+1);
	vis[i]=0;
	return ;
}
signed main(){
	int c,T;
	cin>>c>>T;
	if(c<=3){
		while(T--){
			memset(vis,0,sizeof(vis));
			cin>>n>>k;
			for(int i=1;i<=n;i++)to[i].clear();
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
				to[u].push_back(v);
				to[v].push_back(u);
			}
			dfs(1,0);
			cout<<Min<<"\n";
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
