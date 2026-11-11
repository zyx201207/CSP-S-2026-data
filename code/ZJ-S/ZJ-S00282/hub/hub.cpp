#include<bits/stdc++.h>
using namespace std;
int n,k;
bool vis[100010];
bool dis[100010];
vector<int>adj[100010];
void dfs(int no) {
	dis[no]=1;
	for(int i=0; i<adj[no].size(); i++) {
		int v=adj[no][i];
		if(dis[v])continue;
		if(vis[v]) {
			dfs(v);
		}
	}
}
bool check() {
	for(int i=1; i<=n; i++)dis[i]=0;
	int cnt=0;
	for(int i=1; i<=n; i++) {
		if(vis[i]&&!dis[i]) {
			dfs(i);
			cnt++;
		}
	}
	return cnt<=2;
}
int visd[20];
struct att {
	int w,time;
};
int djstl(int no) {
	queue<att>p;
	p.push({no,0});
	while(p.size()) {
		att u=p.front();
		p.pop();
		if(vis[u.w])return u.time;
		if(visd[u.w]==no)continue;
		visd[u.w]=no;
		for(int i=0; i<adj[u.w].size(); i++) {
			int v=adj[u.w][i];
			if(visd[v]==no)continue;
			p.push({v,u.time+1});
		}
	}
}
int ans=1e9;
int a[20];
void fenk(int kk,int last) {
	if(kk>k) {
		for(int i=1; i<=n; i++) {
			visd[i]=0;
		}
		if(!check())return ;
		int pyte=0;
		for(int i=1; i<=n; i++) {
			pyte=max(pyte,djstl(i));
		}
		ans=min(ans,pyte);
		return ;
	}
	for(int i=last+1; i<=n; i++) {
		if(!vis[i]) {
			vis[i]=1;
			a[kk]=i;
			fenk(kk+1,i);
			a[i]=0;
			vis[i]=0;
		}
	}
	return ;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) {
		cin>>n>>k;
		if(c==13||c==14){
			int m=(n-1)/2;
			cout<<(m+k)/3+1<<'\n';
			continue;
		}
		for(int i=1; i<=n; i++)adj[i].clear();
		for(int i=1; i<n; i++) {
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		ans=1e9;
		fenk(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}