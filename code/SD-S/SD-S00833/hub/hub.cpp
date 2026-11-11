#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int c,t,n,k,vis[60],cnt,cut;
int ans;
vector<int>g[60];
void dfs1(int u,int fa){
	for(auto it:g[u]){
		if(it==fa){
			continue;
		}
		if(vis[it]&&vis[u]){
			cnt++;
		}
		dfs1(it,u);
	}
}
void dfs2(int u,int fa,int st){
	if(vis[u]){
		cut=min(cut,st);
	}
	for(auto it:g[u]){
		if(it!=fa){
			dfs2(it,u,st+1);
		}
	}
}
void dfs(int sum){
	if(sum==n+1){
		cnt=sum=0;
		dfs1(1,0);
		if(sum-cnt>2||sum!=k){
			return ;
		}
		int num=1e9;
		for(int i=1;i<=n;i++){
			cut=1e9;
			dfs2(i,0,0);
			num=max(num,cut);
		}
		ans=min(ans,num);
		return ;
	}
	vis[sum]=0;
	dfs(sum+1); 
	vis[sum]=1;
	dfs(sum+1); 
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=1e9;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		cout<<ans<<"\n";
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
