#include<bits/stdc++.h>
using namespace std;
int c,t; 
int n,k;
vector<int> mp[1000005];
int ch[1000005],vis[1000005],dis[1000005];
int a[1000006];
int ans=0x3f3f3f3f;
int dv[1000005];
int bfs(int s){
	memset(dis,0x3f3f3f3f,sizeof(dis));
	queue<int> q;
	vis[s]=1;
	dis[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<mp[u].size();i++){
			int v=mp[u][i];
			if(!vis[v]){
				vis[v]=1;
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
}
int dfs(int d){
	if(d>=k){
		memset(vis,0,sizeof(vis));
		int cnt=0;
		for(int i=1;i<=d;i++){
			if(!vis[a[i]])bfs(i),cnt++;
		}
		if(cnt>2)return 0;
		else{
			int maxn=-1;
			for(int i=1;i<=k;i++){
				memset(vis,0,sizeof(vis));
				bfs(a[i]);
				for(int j=1;j<=n;j++){
					if(!dv[j])maxn=max(maxn,dis[j]);
				}
			}
			ans=min(ans,maxn);
			return 1;
		}
	}
	for(int i=1;i<=n;i++){
		if(!dv[i]){
			dv[i]=1;
			a[i]=i;
			int flag=dfs(d+1);
			if(!flag)break;
			dv[i]=0;
			
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0x3f3f3f3f;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		dfs(1);
		cout<<ans<<"\n";
	}
}
