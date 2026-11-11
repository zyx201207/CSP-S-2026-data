#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
vector<int> g[N];
bool vis[N];
int bfs(int x){
	if(vis[x])	return 0;
	vector<bool> o(N,0);
	queue<pair<int,int> >q;
	q.push({0,x});
	while(!q.empty()){
		int u=q.front().second,s=q.front().first;
		q.pop();
		if(o[u])	continue;
		o[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(vis[v])	return s+1;
			q.push({s+1,v});
		}
	}
	return -1;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		
		for(int i=1;i<=n;i++)	g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans=1e18;
		if(k==2){
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					int cnt=-1e18;
					vis[i]=1,vis[j]=1;
					for(int k=1;k<=n;k++)	cnt=max(cnt,bfs(k));
					vis[i]=0,vis[j]=0;
					ans=min(ans,cnt);
				}
			}
			cout<<ans<<"\n";
		}
		else	cout<<n/3-1<<"\n";
	}
	return 0;
}