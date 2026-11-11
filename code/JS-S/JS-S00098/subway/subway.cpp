#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,r1,r2,k,w[500009],qq[100009];
long long a[100009],t[100009];
set<pair<long long,long long>>p;
struct node{
	long long y,v;
	node(long long _y,long long _v){
		y=_y,v=_v;
	}
};
vector<node>x1[100009];
long long dist[1000009];
long long dj(long long s,long long t){
	memset(dist,127,sizeof(dist));
	p.clear();
	dist[s]=0;
	for(long long i=1;i<=m;i++)p.insert(make_pair(dist[i],i));
	for(;!p.empty();){
		long long w=p.begin()->second;
		if(dist[w]>1<<30||w==t)break;
		p.erase(p.begin());
		for(auto i:x1[w]){
			if(i.v+dist[w]<dist[i.y]){
				p.erase(make_pair(dist[i.y],i.y));
				dist[i.y]=i.v+dist[w];
				p.insert(make_pair(dist[i.y],i.y));
			}
		}
	}
	return dist[t];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&k);
		for(long long j=1;j<=k;j++){
			scanf("%lld%lld",&a[j],&t[j]);
		}
		for(long long j=1;j<k;j++){
			for(long long q=j+1;q<=k;q++){
				x1[a[j]].push_back(node(a[q],t[j]+t[q]));
				x1[a[q]].push_back(node(a[j],t[j]+t[q]));
			}
		}
	}
	for(long long i=1;i<=q;i++){
		scanf("%lld%lld",&r1,&r2);
		printf("%lld\n",dj(r1,r2)+w[r1]+w[r2]);
	}
	return 0;
}
