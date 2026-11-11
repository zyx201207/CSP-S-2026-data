#include <bits/stdc++.h>
#define int long long 
using namespace std;
int c,t;
int n,k;
int u,v;
vector<int> e[15];
bool jl[15];
int cnt=0;
int ans=2e18;
bool vis[15];
void dfs1(int x,int fa){
//	cout<<x<<" "<<fa<<'\n';
	for(int i=0;i<(int)e[x].size();i++){
		int y=e[x][i];
//		cout<<y<<" "<<x<< 
		if(y==fa||vis[y]==0){
			continue;
		}
		jl[y]=1;
		dfs1(y,x);
	}
}
int u_minn=2e18;
void dfs2(int x,int fa,int stp){
//	cout<<x<<" "<<fa<<" "<<stp<<'\n';
	for(int i=0;i<(int)e[x].size();i++){
		int y=e[x][i];
		if(y==fa){
			continue;
		}
		if(vis[y]==1){
			u_minn=min(u_minn,stp+1);
			continue;
		}
		dfs2(y,x,stp+1);
	}
}
void dfs(int x,int pos){
	if(x==k+1){
//		for(int i=1;i<=n;i++){
//			cerr<<vis[i]<<" ";
//		}
//		cerr<<'\n';
		for(int i=1;i<=n;i++){
			jl[i]=0;
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1&&jl[i]==0){
				jl[i]=1;
				dfs1(i,0);
				sum++;
			}
		}
//		cerr<<-1<<'\n';
		if(sum!=2){
			return ;
		}
//		for(int i=1;i<=n;i++){
//			cout<<jl[i]<<" ";
//		}
//		cout<<'\n';
		int u_sum=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				continue;
			}
			u_minn=2e18;
			dfs2(i,0,0);
//			cout<<i<<" "<<u_minn<<'\n';
//			if(u_minn==1){
//				cout<<"fucking:"<<'\n';
//				for(int i=1;i<=n;i++){
//					cout<<vis[i]<<'\n';
//				}
//			}
			u_sum=max(u_sum,u_minn);
		}
//		cout<<ans<<" "<<u_sum<<'\n';
//        if(u_sum==1){
//        	cout<<"fucking:"<<'\n';
//			for(int i=1;i<=n;i++){
//				cout<<vis[i]<<'\n';
//			}
//		}
		ans=min(ans,u_sum);
		return ; 
	}
	for(int i=pos;i<=n;i++){
		vis[i]=1;
		dfs(x+1,i+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=2e18;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
		    e[u].push_back(v);
		    e[v].push_back(u);
		} 
//		for(int i=1;i<=n;i++){
//			cout<<"begining:"<<i<<'\n';
//			for(int j=0;j<e[i].size();j++){
//				cout<<e[i][j]<<" ";
//			}
//			cout<<'\n';
//		}
		dfs(1,1);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++){
			e[i].clear();
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
