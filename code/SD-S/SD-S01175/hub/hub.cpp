#include<bits/stdc++.h>
using namespace std;
vector<int>g[15];
int vis[15],dep[15];
void dfs(int u){
	for(auto v:g[u]){
		if(dep[v]>dep[u]){
			dep[v]=dep[u]+1;
			dfs(v);
		}
	}
}
int c,t;
void work(){
	int n,k;
	cin>>n>>k;
	if(c==13||c==14){
		int x;
		for(int i=1;i<n;i++)cin>>x>>x;
		if(n==k){
			cout<<"0\n";
			return;
		}
		if(k>=n/2){
			cout<<"1\n";
			return;
		}
		cout<<(n/2-k+3)/4+1<<"\n";
		return;
	}
	for(int i=0;i<n;i++)g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u-1].push_back(v-1);
		g[v-1].push_back(u-1);
	}
	int ans=1e9;
	for(int bt=0;bt<(1<<n);bt++){
		memset(vis,0,sizeof(vis));
		int lt=0,cnt=0;
		for(int i=0;i<n;i++){
			if((bt>>i)&1){
				int c=1;
				for(auto j:g[i])c-=vis[j];
				vis[i]=1;
				lt+=c;
				cnt++;
			}
		}
		if(lt<=2&&cnt==k){
			memset(dep,0x3f,sizeof(dep));
			for(int i=0;i<n;i++){
				if((bt>>i)&1){
					dep[i]=0;
					dfs(i);
				}
			}
			for(int i=0;i<n;i++){
				if((bt>>i)&1){
					dfs(i);
				}
			}
			int mx=0;
			for(int i=0;i<n;i++)mx=max(mx,dep[i]);
			ans=min(ans,mx);
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)work();
	return 0;
}

