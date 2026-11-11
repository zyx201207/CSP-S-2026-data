#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,m,vis[200001],y;
vector<int> vec[200001];
void dfs(int u){
	for(int i:vec[u]){
		if(vis[i]) continue;
		vis[i]=vis[u]+1;
		if(vis[i]>vis[y]) y=i;
		dfs(i);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) vec[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		dfs(1);
		memset(vis,0,sizeof(vis));
		dfs(y);
		int le=vis[y]/2,ri=(vis[y]+1)/2;
		int fle=m/2,fri=(m+1)/2;
		cout<<max({(le+1-fle)/2,(ri+1-fri)/2,(le+1-fle)/2+(ri+1-fri)%2,(le+1-fle)%2+(ri+1-fri)/2})<<'\n';
	}
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