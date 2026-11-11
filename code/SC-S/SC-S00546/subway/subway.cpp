#include<bits/stdc++.h>
#define int long long
#define M 500005
#define Q 100005
using namespace std;
int c,n,m,d,q,w[M],k,a[M],t[M],vis[M],asq[M];
map<int,int> dis[M];
struct node{
	int u,v=0,id;
	bool operator < (node rt) const {
		return v<rt.v;
	} 
}qr[Q];
void init() {
	memset(vis,-1,sizeof vis);
	return;
}
int dfs(int id,int mb) {
	if(vis[id]!=-1) return vis[id];
	if(id==mb) return vis[id]=0;
	vis[id]=1e18;
	for(auto v:dis[id]) vis[id]=min(vis[id],v.second+dfs(v.first,mb));
	return vis[id];
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++) {
		cin>>k;
		for(int j=1; j<=k; j++) cin>>a[j]>>t[j];
		for(int u=1; u<=k; u++) {
			for(int v=1; v<=k; v++) {
				if(u==v) continue;
				int ux=a[u],vx=a[v];
				if(!dis[ux][vx]) dis[ux][vx]=dis[vx][ux]=t[u]+t[v];
				else dis[ux][vx]=dis[vx][ux]=min(dis[ux][vx],t[u]+t[v]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qr[i].u>>qr[i].v;
		qr[i].id=i;
		if(qr[i].u>qr[i].v) swap(qr[i].u,qr[i].v);
	}
	sort(qr+1,qr+q+1),init();
	for(int i=1;i<=q;i++){
		if(qr[i].v!=qr[i-1].v) init();
		else init();
		asq[qr[i].id]=w[qr[i].u]+w[qr[i].v]+dfs(qr[i].u,qr[i].v);
	}
	for(int i=1;i<=q;i++) cout<<asq[i]<<"\n";
	return 0;
}
