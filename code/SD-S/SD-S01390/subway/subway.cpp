#include<bits/stdc++.h>
using namespace std;
struct node {
	int v,w;
};
int c,n,m,d,q;
int w[500010],k[500010],a[500010];
vector <node> t[500010];
vector <node> s[500010];
long long dis[110][110];
int vis[110];
void spfa(int f) {
	fill(dis[f]+1,dis[f]+1+n,1e18);
	fill(vis+1,vis+1+n,0);
	dis[f][f]=0;
	queue <int> q;
	q.push(f);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto r:s[u]) {
			int v=r.v;
			int w=r.w;
			if(!vis[v]&&dis[f][v]>dis[f][u]+w) {
				dis[f][v]=dis[f][u]+w;
				q.push(v);
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			int w;
			cin>>a[j]>>w;
			t[a[j]].push_back({i,w});
		}
	}
	for(int i=1; i<=m; i++) {
		for(auto f:t[i]) {
			int v=f.v;
			int w1=f.w;
			for(auto e:t[i]) {
				int u=e.v;
				int w2=e.w;
				if(u==v) continue;
				int fl=0;
				for(auto r:s[u]) {
					int l=r.v;
					if(l!=v) continue;
					fl=1;
					r.w=min(r.w,w1+w2);
				}
				if(!fl) {
					s[u].push_back({v,w1+w2});
				}
			}
		}
	}
	for(int i=1; i<=n; i++) {
		spfa(i);
	}
	for(int i=1; i<=q; i++) {
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(auto s:t[x]) {
			int u=s.v,w1=s.w;
			for(auto e:t[y]) {
				int v=e.v,w2=e.w;
				long long sum=dis[u][v]+w1+w2+w[x]+w[y];
				ans=min(ans,sum);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
