#include <bits/stdc++.h>
#define int long long
using namespace std;
int val[500005];
int d[505][505];
int head[500005],to[5000005],ww[500005],nxt[500005],tot;
void add(int x,int y,int w) {
	to[++tot]=y;
	ww[tot]=w;
	nxt[tot]=head[x];
	head[x]=tot;
}
signed main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,rr,q;
	cin>>c>>n>>m>>rr>>q;
	for(int i=1;i<=m;i++) cin>>val[i];
	for(int i=1;i<=n;i++) {
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) {
			int v,w;
			cin>>v>>w;
			add(v,i,w);
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) if(i!=j) d[i][j]=1e18;
	}
	for(int i=1;i<=m;i++) {
		for(int j=head[i];j;j=nxt[j]) {
			for(int k=head[i];k;k=nxt[k]) {
				if(j==k) continue;
				d[to[j]][to[k]]=min(d[to[j]][to[k]],ww[j]+ww[k]);
				d[to[k]][to[j]]=d[to[j]][to[k]];
			}
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			for(int k=1;k<=n;k++) {
				d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
			}
		}
	}
/*	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) cout<<i<<" "<<j<<" "<<d[i][j]<<endl;
	}*/
	while(q--) {
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int i=head[x];i;i=nxt[i]) {
			for(int j=head[y];j;j=nxt[j]) {
				ans=min(ans,d[to[i]][to[j]]+ww[i]+ww[j]);
			}
		}
		cout<<ans+val[x]+val[y]<<endl;
	}
	return 0;
}
