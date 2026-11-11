#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,t,dist[N];
int n,k;
vector<int> G[N];
void dfs(int x,int d){
	if(x==n)return;
	dist[x]=d;
	for(int i=0;i<G[x].size();++i)dfs(G[x][i],d+1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		
		
		for(int i=1;i<=n-1;++i){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1,0);
		int ans1=0;
		for(int mask=0;mask<(1<<n);++mask){
			vector<int> e;
			int cnt=0;
			for(int i=0;i<k;++i)if(mask&(1<<i))e.push_back(i),cnt++;
			if(cnt!=k)continue;
			int ans=INT_MAX;
			for(int i=1;i<=n;++i){
				for(int j=0;j<e.size();++j){
					ans=min(ans,dist[e[j]]-dist[i]);
				}
			}
			ans1=min(ans,ans1);
		}
		cout<<ans1<<'\n';
	}
	return 0;
}
