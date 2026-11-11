#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500010],dis[510][510];
vector<pair<long long,long long> > stops[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,127,sizeof(dis));
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i = 1;i<=n;i++) dis[i][i] = 0;
	for(int i = 1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i = 1;i<=n;i++){
		long long k;
		scanf("%lld",&k);
		for(int j = 1;j<=k;j++){
			long long id,t;
			scanf("%lld %lld",&id,&t);
			stops[id].push_back({i,t});
		}
	}
	for(int i = 1;i<=m;i++){
		long long sz1 = stops[i].size(),sz2 = stops[i].size();
		for(int j = 0;j<sz1;j++){
			for(int k = j+1;k<sz2;k++){
				pair<long long,long long> u = stops[i][j],v = stops[i][k];
				dis[u.first][v.first] = dis[v.first][u.first] = min(dis[u.first][v.first],u.second+v.second);
			}
		}
	}
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++) if(dis[i][k]<=1e18&&dis[k][j]<=1e18){
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		long long x,y; scanf("%lld %lld",&x,&y);
		long long res = 1e18;
		for(auto i : stops[x]){
			for(auto j : stops[y]){
				res = min(res,w[x]+w[y]+i.second+j.second+dis[i.first][j.first]);
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
