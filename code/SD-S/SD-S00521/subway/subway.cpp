#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[505],x[505][1005],t[505][1005],dis[500005],vis[500005];
vector<long long> b[1005];
vector<pair<long long,long long> > e[500005];
long long dij(long long s,long long z){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	priority_queue<pair<long long,long long> > q;
	q.push({0,s});
	while(q.size()){
		long long u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for (auto i:e[u]){
			long long v=i.first,w=i.second;
			if(dis[v]>dis[u]+w){
				//cout << 111;
				dis[v]=dis[u]+w;
				q.push({-dis[v],v});
			}
		}
	}
	return dis[z];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for (int i=1;i<=n;i++){
		long long k;
		scanf("%lld",&k);
		for (int j=1;j<=k;j++){
			scanf("%lld",&x[i][j]);scanf("%lld",&t[i][x[i][j]]);
			b[x[i][j]].push_back(i);
			e[x[i][j]].push_back({i*m+x[i][j],t[i][x[i][j]]});
			e[i*m+x[i][j]].push_back({x[i][j],t[i][x[i][j]]});
		}
        for (int j=1;j<=k;j++){
        	for (int l=j+1;l<=k;l++){
        		e[i*m+x[i][j]].push_back({i*m+x[i][l],0});
			}
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=0;j<b[i].size();j++){
			for (int k=j+1;k<b[i].size();k++){
				e[b[i][j]*m+i].push_back({b[i][k]*m+i,t[b[i][j]][i]+t[b[i][k]][i]});
				//e[i].push_back({b[i][k]*m+i,t[b[i][k]][i]});
				e[b[i][k]*m+i].push_back({b[i][j]*m+i,t[b[i][k]][i]+t[b[i][j]][i]});
				//e[i].push_back({b[i][j]*m+i,t[b[i][j]][i]});
				//printf("%d %lld %lld\n",t[b[i][j]][i]+t[b[i][k]][i],b[i][j]*m+i,b[i][k]*m+i);
			}
		}
	}
	while(q--){
		long long l,r;
		scanf("%lld%lld",&l,&r);
		if(r<l)swap(l,r);
		long long ans=dij(l,r);
		printf("%lld\n",ans+w[l]+w[r]);
	}
	return 0;
}
/*0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2*/
