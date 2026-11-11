#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define fop(i,l,r) for(int i=l;i<=r;i++)
int dc,T,n,k,ans,vis[1000005],vis2[1000005],dis[1000005],temp[1000005];
vector<int>ls[1000005];
void dfs_ans(int u,int fa){
	dis[u]=min(dis[u],temp[u]);
	for(int v:ls[u]){
		if(v==fa)continue;
		temp[v]=temp[u]+1;dfs_ans(v,u);
	}
}void check(){
	int cnt=0;fop(i,1,n)vis2[i]=0;
	fop(i,1,n){dis[i]=4e18;if(vis[i]){
		int f=0;for(int&v:ls[i])f|=vis2[v];
		vis2[i]=1;if(!f)cnt++;
	}}if(cnt>2)return;
	fop(i,1,n)if(vis[i]){
		temp[i]=0;dfs_ans(i,i);
	}int res=0;fop(i,1,n)res=max(res,dis[i]);
	ans=min(ans,res);
}void dfs(int no,int s){
//	cout<<no<<'\n';
	if(no>n){if(!s)check();}
	else{
		if(s){vis[no]=1;dfs(no+1,s-1);}
		vis[no]=0,dfs(no+1,s);
	}return;
}signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	cin>>dc>>T;while(T--){
		ans=4e18;cin>>n>>k;fop(i,1,n)ls[i].clear();
		fop(i,1,n-1){
			int u,v;cin>>u>>v;
			ls[u].push_back(v);
			ls[v].push_back(u);
		}dfs(1,k);cout<<ans<<'\n';
	}return 0;
}/*
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