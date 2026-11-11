#include<bits/stdc++.h>
using namespace std;
vector<long long> g[1000005];
long long a[1000005],vis[1000005],dis[1000005],c,t,n,k,u,v,ans=LLONG_MAX;
void dfs(int x){
	if(x>k){
		ans=min(ans,x-k+1);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		a[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=0;i<n-1;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u); 
		}
		if(k==n){
			cout<<0<<"\n";
			continue;
		}
		if(!c || c==13 || c==14){
			if(k*2>=n-1){
				cout<<1<<"\n";
				continue;
			}
		}
		dfs(1);
	}
	return 0;
}
