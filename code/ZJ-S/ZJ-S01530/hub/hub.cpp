#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=220;
const int inf=2e18;
int c,T,n,k,ans;
int f[N],vis[N],mp[N];
struct node {
	int id;
	int dep;
};
queue<node> q;
vector<int> b;
vector<int> g[N];
int find(int x) {
	if(!vis[f[x]]) return x;
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
int bfs(int s) {
	while(!q.empty()) q.pop();
	q.push({s,0});
	while(!q.empty()) {
		node fr=q.front();
		int u=fr.id,depth=fr.dep;
		q.pop();
		for(int v:g[u]) {
			node h;
			h.id=v,h.dep=depth+1;
			if(vis[v]) return h.dep;
			q.push(h);
		}
	}
}
void dfs(int lst,int cnt) {
	if(cnt==k) {
		memset(mp,0,sizeof(mp));
		memset(f,0,sizeof(f));
		int cur=0;
		for(int i=1; i<=n; i++) if(vis[i]==1) b.push_back(i);
		for(int i=1; i<=k; i++) f[b[i]]=b[i];
		for(int i=1; i<=k; i++) {
			int fi=find(b[i]);
			if(!mp[fi]) {
				mp[fi]=1;
				cur++;
			}
		}
		if(cur>2) return;
		int r=0;
		for(int i=1; i<=n; i++) {
			if(vis[i]) continue;
			r=max(r,bfs(i));
		}
		ans=min(ans,r);
	}
	if(lst>n) return;
	for(int i=lst+1; i<=n; i++) {
		vis[i]=1;
		dfs(i,cnt+1);
		vis[i]=0;
	}
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>c>>T;
	while(T--) {
		ans=inf;
		cin>>n>>k;
		memset(g,0,sizeof(g));
		for(int i=1; i<=n; i++) {
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(0,0);
		cout<<ans<<"\n";
	}

	return 0;
}
