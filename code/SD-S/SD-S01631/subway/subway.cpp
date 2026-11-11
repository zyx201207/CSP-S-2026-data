#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],x,y,h[1500005],cnt,dis[1500005],a,t;
struct edge {
	long long val,to,nxt;
} e[1000005];
void add(long long u,long long v,long long w) {
	e[++cnt].val =w;
	e[cnt].nxt =v;
	e[cnt].to =h[u];
	h[u]=cnt;
	return;
}
void dij(long long x) {
	dis[x]=0;
	priority_queue<long long> q;
	q.push(x);
	while(!q.empty()) {
		long long u=q.top();
		q.pop();
		for(long long i=h[u]; i; i=e[i].to ) {
			long long v=e[i].nxt ;
			if(dis[v]>dis[u]+e[i].val ) {
				dis[v]=dis[u]+e[i].val ;
				q.push(v);
			}
		}
	}
	return;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1; i<=m; i++) {
		cin>>w[i];
		add(i+m*2,i,w[i]);
		add(i,i+m*2,w[i]);
	}
	for(long long i=1; i<=n; i++) {
		cin>>k[i];
		for(long long j=1; j<=k[i]; j++) {
			cin>>a>>t;
			if(i==a)add(i,a+m,t);
			else add(i+m,a,t);
		}
	}
	for(long long i=1; i<=q; i++) {
		cin>>x>>y;
		memset(dis,0x3f,sizeof(dis));
		dij(x+m*2);
		cout<<dis[y+m*2]<<"\n";
	}
	return 0;
}//×î¶ÌÂ·?
