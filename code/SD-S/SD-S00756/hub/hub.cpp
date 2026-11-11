#include<bits/stdc++.h>
using namespace std;
#define ll long long
int un,t,n,k,ok[111],a[111][111];
ll d[111],q[111];
vector<int> edges[111];
bool unok () {
	for (int x=1;x<=n;x++){
		for (int y=1;y<=n;y++) {
			for (int z=1;z<=n;z++) {
				
			}
		}
	}
}
void bfs () {
	int front=1,rear=0;
	for (int i=1;i<=n;i++) {
		if (!ok[i]) {
			d[i]=10000;
		}
		else {
			d[i]=0;
			q[++rear]=i;
		}
	}
	while (front<=rear) {
		int x=q[front];
		for ()
	}
}
void dfs (int x,int cnt) {
	if (cnt==k) {
		if (unok()) return;
		bfs();
		int ma=0;
		for (int i=1;i<=n;i++) ma=max(ma,d[i]);
		ans=min(ans,ma);
		return;
	}
	if (x==n+1) return;
	ok[x]=0;
	dfs(x+1,cnt);
	ok[x]=1;
	dfs(x+1,cnt+1);
}
void solve () {
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) edges[i].clear();
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) a[i][j]=0;
	}
	for (int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
		a[u][v]=a[v][u]=1;
	}
	dfs(1,0);
}
int main () {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&un,&t);
	while (t--) {
		solve();
	}
	return 0;
}
/*
16:50 ~ 16:55
û˼· 
*/
