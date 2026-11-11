#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstdio>
using namespace std;
const int maxn=1e6+1;
int c,t,n,k,ans;
bool b[11],vis[11];
vector<int> g[maxn];
int popcnt(int x) {
	int res=0;
	for(int i=0;i<n;i++) {
		b[i+1]=vis[i+1]=false;
		if(x&(1<<i)) {
			b[i+1]=true;
			res++;
		}
	}
	return res;
}
void dfs(int u,int fa) {
	vis[u]=true;
	for(int v:g[u]) {
		if(v==fa||!b[v]) {
			continue;
		}
		dfs(v,u);
	}
}
int bfs(int u) {
	if(b[u]) {
		return 0;
	}
	queue<pair<int,int> > q;
	q.push({u,0});
	for(int i=1;i<=n;i++) {
		vis[i]=false;
	}
	vis[u]=true;
	while(!q.empty()) {
		int f=q.front().first,s=q.front().second;
		q.pop();
		for(int v:g[f]) {
			if(b[v]) {
				return s+1;
			}
			q.push({v,s+1});
		}
	}
	return n;
}
int main() {
	freopen("hub2.in","r",stdin);
	freopen("hub2.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--) {
		cin>>n>>k;
		for(int i=1;i<=n;i++) {
			g[i].clear();
		}
		for(int i=1;i<n;i++) {
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(c<=3) {
			ans=n;
			for(int i=1;i<(1<<n);i++) {
				if(popcnt(i)!=k) {
					continue;
				}
				int tmp=0,mx=0;
				for(int i=1;i<=n;i++) {
					if(!b[i]||vis[i]) {
						continue;
					}
					tmp++;
					dfs(i,0);
				}
				if(tmp>2) {
					continue;
				}
				for(int i=1;i<=n;i++) {
					mx=max(mx,bfs(i));
				}
				ans=min(ans,mx);
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
