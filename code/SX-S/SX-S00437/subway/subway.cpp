#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long ww[500005];
long long k,a,t,xx,yy;
struct P{
	long long x,y;//第x条地铁线，花费时间y
};
vector<P> s[500005];
long long h[505][505];
const long long inf=(1ll<<55);
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++){
		scanf("%lld",&ww[i]);
	}
	for(long long i=1;i<=n;i++){
		scanf("%lld",&k);
		for(long long j=1;j<=k;j++){
			scanf("%lld%lld",&a,&t);
			s[a].push_back(P{i,t});
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			h[i][j]=inf;
			if(i==j)h[i][j]=0;
		}
	}
	for(long long i=1;i<=m;i++){
		for(auto u:s[i]){
			for(auto v:s[i]){
				if(u.x==v.x&&u.y==v.y)continue;
				long long uu=u.x;
				long long vv=v.x;
				if(h[uu][vv]==inf){
					h[uu][vv]=u.y+v.y;
				}
				else {
					h[uu][vv]=min(h[uu][vv],u.y+v.y);
				}
			}
		}
	}
	for(long long b=1;b<=n;b++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				h[i][j]=min(h[i][j],h[i][b]+h[b][j]);
			}
		}
	}
	while(q--){
		scanf("%lld%lld",&xx,&yy);
		long long rty=inf;
		for(auto u:s[xx]){
			for(auto v:s[yy]){
				rty=min(rty,u.y+v.y+h[u.x][v.x]);
			}
		}
		printf("%lld\n",rty+ww[xx]+ww[yy]);
	}
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/