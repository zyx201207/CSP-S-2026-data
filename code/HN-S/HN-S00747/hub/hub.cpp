#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,u[1000005],v[2000006],vis[2000006],f[2000006],dis[2000005],ans=INT_MAX;
vector<int>g[2000005];
void bfs(int x){
	for(int i=1;i<=n;i++) dis[i]=INT_MAX,vis[i]=0;
	queue<int>q;
	q.push(x);
	dis[x]=0;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(auto i:g[t]){
			if(vis[i])continue;
			dis[i]=dis[t]+1;
			vis[i]=1;
			q.push(i);
		}
	}
}
void dfs(int x,int k){
	if(k==0){
		for(int i=1;i<=n;i++){
			g[i].clear();
			dis[i]=0;
		}
		for(int i=1;i<n;i++){
			if(f[i]){
				g[u[i]].push_back(v[i]);
				g[v[i]].push_back(u[i]);
			}
		}
		int maxn=0;
		for(int i=1;i<=n;i++){
			bfs(i);
			int minn=INT_MAX;
			for(int j=1;j<=n;j++){
				minn=min(minn,dis[j]);
			}
			maxn=max(maxn,minn);
		}
		ans=min(ans,maxn);
	}
	if(x>n-1) return;
	f[x]=0;
	dfs(x+1,k);
	f[x]=1;
	dfs(x+1,k-1);
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin>> n >> k;
		for(int i=1;i<n;i++)cin >> u[i] >> v[i];
		dfs(1,k);
		cout << ans << '\n';
		ans=INT_MAX;
	}
	return 0;
}
/*
100+40+0+0
while(1) RP++;
*/

