#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
int c,t,n,k,x,y,dp[301],p[301],ans=1e18;
bool vis[301],l[301];
queue<int> q;
vector<int> G[301];
void bfs(int x) {
	q.push(x);
	while(!q.empty()) {
		int f=q.front();q.pop();
		vis[f]=true;
		for(auto y:G[f]) {
			if(l[y]==false) continue;
			if(vis[y]==true) continue;
			q.push(y);
		}
	}
}
void dfs(int x,int last) {
	if(x-1+n-last<k) return;
	if(x>k) {
		int cnt=0;
		for(int i=1;i<=n;i++) {
			vis[i]=false;
		}
		for(int i=1;i<=k;i++) {
			if(!vis[p[i]]) {
				bfs(p[i]);
				++cnt;
			}
		}
		if(cnt>2) return;
		for(int i=1;i<=k;i++) {
			dp[p[i]]=0;
			q.push(p[i]);
		}
		while(!q.empty()) {
			int p=q.front();q.pop();
			for(auto y:G[p]) {
				if(vis[y]) continue;
				dp[y]=dp[p]+1;
				q.push(y);
				vis[y]=true;
			}
		}
		int res=0;
		for(int i=1;i<=n;i++) {
			if(!l[i]) res=max(res,dp[i]);
		}
		ans=min(ans,res);
		return;
	}
	for(int i=last+1;i<=n;i++) {
		p[x]=i;l[i]=true;
		dfs(x+1,i);
		l[i]=false;
	}
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	for(int ii=1;ii<=t;ii++) {
		cin>>n>>k;ans=1e18;
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<n;i++) {
			cin>>x>>y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		if(k==n) cout<<0<<"\n";
		else {
			dfs(1,0);
			cout<<ans<<"\n";
		}
	}
	return 0;
}