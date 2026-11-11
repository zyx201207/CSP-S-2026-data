#include<bits/stdc++.h>
using namespace std;
vector<int> g[1010];
int dis[1010];
bool vis[1010];
void dfs(int x,int step,int fa){
	dis[x]=min(dis[x],step);
	for(auto c:g[x]){
		if(c==fa) continue;
		dfs(c,step+1,x);
	}
}
void dfs2(int x){
	vis[x]=0;
	for(auto c:g[x])
		if(vis[c]==1)
			dfs2(c);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		for(int i=0;i<1010;i++)
			g[i].clear();
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans=1e9;
		if(k==2){
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++){
					for(int k=0;k<=1000;k++)
						dis[k]=1e9;
					dfs(i,0,0);
					dfs(j,0,0);
					int cnt=1;
					for(int i=1;i<=n;i++){
						cnt=max(cnt,dis[i]);
					}
					ans=min(ans,cnt);
				}
			cout<<ans<<endl;
			goto nxt;
		}
		for(int s=0;s<(1<<n);s++){
			for(int i=0;i<20;i++){
				dis[i]=1e9;
				vis[i]=0;
			}
			int cnt=0;
			for(int i=0;i<n;i++)
				if(s&(1<<i)){
					vis[i+1]=1;
					cnt++;
					dfs(i+1,0,-1);
				}
			if(cnt!=k) continue;
			int ltk=0;
			for(int i=1;i<=n;i++)
				if(vis[i]==1){
					ltk++;
					dfs2(i);
				}
			if(ltk<=2){
				int cnt=1;
				for(int i=1;i<=n;i++)
					cnt=max(cnt,dis[i]);
				ans=min(ans,cnt);
			}
		}
		cout<<ans<<endl;
		nxt:;
	}
}