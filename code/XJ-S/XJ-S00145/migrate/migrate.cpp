#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=5005;
const ll INF=0x3f3f3f3f3f3f3f3f;

int n;
vector<int> g[N];
ll x[N];
ll d[N];
ll d2[N];
int vis[N];

void bfs(int s) {
	queue<int> q;
	q.push(s);
	for(int i=1; i<=n; i++) d[i]=INF;
	d[s]=0;

	while(!q.empty()) {
		int u=q.front();
		q.pop();
		
		for(int i=0; i<g[u].size(); i++) {
			int v=g[u][i];
			if(d[u]+1<d[v]) {
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
}
void bfs2(int s) {
	queue<int> q;
	q.push(s);
	for(int i=1; i<=n; i++) d2[i]=INF;
	d2[s]=0;

	while(!q.empty()) {
		int u=q.front();
		q.pop();
		
		for(int i=0; i<g[u].size(); i++) {
			int v=g[u][i];
			if(d2[u]+1<d2[v]) {
				d2[v]=d2[u]+1;
				q.push(v);
			} if(d2[u]+1==d[v]) {
				vis[v]++;
			}
		}
	}
}

void solve() {
	ll d;
	cin>>n>>d;
	for(int i=1; i<=n; i++) {
		cin>>x[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<i; j++) {
			ll xx=x[i]-x[j];
			xx=(xx<0 ? -xx : xx);
			if(xx<=d) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	for(int i=1; i<=n; i++) {
		bfs(i);
	}
	for(int i=1; i<=n; i++) {
		bfs2(i);
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		if(vis[i]==2) {
			ans++;
		}
	} cout<<ans<<endl;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin>>c>>t;
	while(t--) {
		solve();
	}
	
	return 0;
}
