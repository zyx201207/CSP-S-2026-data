#include<bits/stdc++.h>
using namespace std;
int c,n,k,dist[310][310],t,x,y,deep[310],f[310],vis[310],ans,vis2[310];
vector<int> v[310];
void dfstree(int u,int fa){
	deep[u]=deep[fa]+1;
	f[u]=fa;
	for(int i:v[u]){
		if(i==fa) continue;
		dfstree(i,u);
	}
} 
int lca(int x,int y){
	int ans=0;
	if(deep[x]<deep[y]) swap(x,y);
	while(deep[x]>deep[y]) x=f[x],ans++;
	while(x!=y) x=f[x],y=f[y],ans+=2;
	return ans;
}
void dfstree2(int u,int fa){
	vis2[u]=1;
	for(int i:v[u]){
		if(i==fa) continue;
		if(vis[i])dfstree2(i,u);
	}
} 
void dfs(int x,int cnt){
	if(cnt==k){
		int sum=0,sum2=0;
		for(int i=1;i<=n;i++) vis2[i]=0;
		for(int i=1;i<=n;i++){
			if(vis[i]&&!vis2[i]){
				dfstree2(i,0);
				sum++;
			}
		}
		if(sum>2) return;
		for(int i=1;i<=n;i++){
			int num=1000000000;
			for(int j=1;j<=n;j++) if(vis[j]) num=min(num,dist[i][j]);
			sum2=max(sum2,num); 
		}
		ans=min(ans,sum2);
		return;
	}
	if(x==n+1) return;
	vis[x]=1;
	dfs(x+1,cnt+1);
	vis[x]=0;
	dfs(x+1,cnt);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=1000000000;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfstree(1,0);
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)dist[i][j]=dist[j][i]=lca(i,j);
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}

