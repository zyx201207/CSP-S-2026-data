#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k,root,dep[N],fa[N],f[4005][10005][2];
set<int>g[N];
bool vis[N];
void dfs(int x,int ft){
	dep[x]=dep[ft]+1;
	if(dep[root]<dep[x])root=x;
	fa[x]=ft;
	for(const int&u:g[x])if(u!=ft){
		dfs(u,x);
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		g[u].insert(v);
		g[v].insert(u);
	}
	dep[0]=-1;
	dfs(1,0);
	dfs(root,0);
	int l=dep[root];
	for(int i=1;i*2<=l;i++)root=fa[root];
	dfs(root,0);
	if(k==1){
		cout<<dep[root]<<"\n";
		return;
	}
	l=dep[root];
	for(int i=1;i*2<=l;i++)root=fa[root];
	g[root].erase(fa[root]);
	g[fa[root]].erase(root);
	int r=root;
	dfs(root,0);
	memset(vis,0,sizeof vis);
	priority_queue<int>dq;
	for(int i=1;i<=n;i++)vis[fa[i]]=1;
	for(int i=1;i<=n;i++)if(!vis[i])dq.push(dep[i]);
	if(k==2){
		cout<<dq.top()<<"\n";
		return;
	}
	for(int i=1;i<=k-2;i++){
		int u=dq.top();
		dq.pop();
		dq.push(u-1);
	}
	cout<<max(0,dq.top())<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
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
