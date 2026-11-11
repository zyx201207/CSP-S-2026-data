#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
long long W[500500],K[550],dis[550][550];
struct node{
	long long a,t;
};
vector <node> R[500500];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,i,j,a,t,k,ans,l,r;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(i = 1;i <= m;i++){
		scanf("%lld",&W[i]);
	}
	for(i = 1;i <= n;i++){
		scanf("%lld",&k);
		for(j = 1;j <= k;j++){
			scanf("%lld%lld",&a,&t);
			R[a].push_back((node){i,t});
		}
		for(j = 1;j <= n;j++){
			dis[i][j] = 1e18;
			if(i == j){
				dis[i][j] = 0;
			}
		}
	}
	for(i = 1;i <= m;i++){
		for(j = 0;j < R[i].size();j++){
			for(k = j+1;k < R[i].size();k++){
				dis[R[i][j].a][R[i][k].a] = min(dis[R[i][j].a][R[i][k].a],R[i][j].t + R[i][k].t);
				dis[R[i][k].a][R[i][j].a] = min(dis[R[i][k].a][R[i][j].a],R[i][j].t + R[i][k].t);
			}
		}
	}//O(md^2) = 10^8
	for(i = 1;i <= n;i++){
		for(j = 1;j <= n;j++){
			for(k = 1;k <= n;k++){
				dis[j][k] = min(dis[j][k],dis[j][i] + dis[i][k]);
			}
		}
	}//O(n^3) = 10^8
	for(i = 1;i <= q;i++){
		scanf("%lld%lld",&l,&r);
		ans = 1e18;
		for(j = 0;j < R[l].size();j++){
			for(k = j;k < R[r].size();k++){
				ans = min(ans,W[l] + W[r] + dis[R[l][j].a][R[r][k].a] + R[l][j].t + R[r][k].t);
			}
		}
		printf("%lld\n",ans);
	}//O(qd^2) = 10^8
	return 0;
}
//hyw??? ~green
//58min.
//IO need 1s!
