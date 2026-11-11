#include <bits/stdc++.h>
using namespace std;
struct node{
	long long to,nxt,w;
}e[200005];
long long dist[200005],cnt=0,head[200005],aa[200005];
bool f[200005];
priority_queue < pair<long long,long long> ,vector<pair<long long,long long>>,greater<pair<long long,long long> > > q;
void add(long long u,long long v,long long w){
	e[++cnt].to=v;
	e[cnt].w=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
void prim(long long x){
	memset(dist,0x3f,sizeof(dist));
	memset(f,0,sizeof(f));
	dist[x]=0;
	q.push(make_pair(0,x));
	while(!q.empty()){
		long long u=q.top().second;
		q.pop();
		if(f[u])continue;
		f[u]=1;
		for(long long i=head[u];i;i=e[i].nxt){
			long long v=e[i].to;
			if(e[i].w+dist[u]+aa[u]+aa[v]<dist[v]){
				dist[v]=e[i].w+dist[u];
				q.push(make_pair(dist[v],v));
			}
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long cc,n,m,a,b,d,qq;
	scanf("%lld%lld%lld%lld%lld",&cc,&n,&m,&d,&qq);
	for(long long i=1;i<=m;i++){
		scanf("%lld",&aa[i]);
	}
	for(long long i=1;i<=n;i++){
		long long k,c,dd;
		scanf("%lld",&k);
		scanf("%lld%lld%lld%lld",&a,&b,&c,&dd);
			add(c,a,b+dd);
			add(a,c,b+dd);
		
	}
	for(long long i=1;i<=qq;i++){
		long long s,t;
		scanf("%lld%lld",&s,&t);
		prim(s);
		printf("%lld\n",dist[t]+aa[s]+aa[t]);
	}
	return 0;
}
