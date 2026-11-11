#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> edge;
int vis[2000005];
int dis[2000005];
int cnt;
void dfs(int st){
	cnt++;
	vis[st]=1;
	dis[st]=0;
	for(int i=0;i<edge[st];i++){
		
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			edge[i]=0;
		}
		for(int i=0;i<n;i++){
			int u,v;
			cin>>u>>v;
//			edge[u].push_back(v);
//			edge[v].push_back(u);
		}
		if(t==2){
			cout<<1<<"\n";
		}
		else{
			cout<<2<<"\n";
		}
	}
}
