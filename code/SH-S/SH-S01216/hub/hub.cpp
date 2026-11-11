#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c,t,n,k,use[20],fg[20],vis[20],mi;
vector <ll> g[20];
queue <ll> q;
void bfs1(ll s){
	for (int i=1;i<=n;i++)  fg[i]=0;
	fg[s]=1;
	q.push(s);
	while (!q.empty()){
		ll u=q.front();
		q.pop();
		for (int i=0;i<g[u].size();i++){
			if (!fg[i]){
				fg[i]=1;
				q.push(i);
			}
		}
	}
}
void bfs2(ll s){
	for (int i=1;i<=n;i++)  vis[i]=0;
	vis[s]=1;
	q.push(s);
	while (!q.empty()){
		ll u=q.front();
		q.pop();
		for (int i=0;i<g[u].size();i++){
			if (!vis[i]){
				vis[i]=vis[u]+1;
				q.push(i);
			}
		}
	}
}
void dfs(ll step){
	if (step>n){
		ll flag=0;
		for (int i=1;i<=n;i++){
			if (use[i] && !fg[i])  bfs1(i),flag++;
		}
		if (flag>2)  return;
		for (int i=1;i<=n;i++){
			if (use[i]){
				bfs2(i);
				ll now=4e18;
				for (int j=1;j<=n;j++)  now=min(now,vis[j]);
			}
			flag=max(flag,now);
		}
		mi=min(flag,mi);
		return;
	}
	use[step]=1;
	dfs(step+1);
	use[step]=0;
	dfs(step+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while (t--){
		cin>>n>>k;
		ll u,v;
		for (int i=1;i<=n;i++)  g[i].clear();
		for (int i=1;i<=n-1;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		mi=4e18;
		dfs();
		cout<<mi<<"\n";
	}
	return 0;
}
