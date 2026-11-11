#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1010;
int c,n,m,d,q,w[N],k[N],a[505][N],t[505][N],x,y,dis[N][N];
bool flag = true;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;++i){
		scanf("%lld",&w[i]);
	}
	for(int i = 1;i <= n;++i){
		scanf("%lld",&k[i]);
		if(k[i] > 2) flag = false;
		for(int j = 1;j <= k[i];++j){
			scanf("%lld %lld",&a[i][j],&t[i][j]);
		}
	}
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= k[i];++j){
			for(int kx = j + 1;kx <= k[i];++kx){
				dis[a[i][j]][a[i][kx]] = min(dis[a[i][j]][a[i][kx]],w[a[i][j]] + t[i][j] + t[i][kx] + w[a[i][kx]]);
				dis[a[i][kx]][a[i][j]] = min(dis[a[i][kx]][a[i][j]],w[a[i][j]] + t[i][j] + t[i][kx] + w[a[i][kx]]);
			}
		}
	}
/*
		for(int k = 1;k <= m;++k){
			for(int i = 1;i <= m;++i){
				for(int j = i + 1;j <= m;++j){
					if(i == j || i == k || j == k) continue;
					dis[i][j] = min(dis[i][j],w[i] + val[i][k] + val[k][j] + w[j]);
				}
			}
		}
*/
	for(int k = 1;k <= m;++k){
		for(int i = 1;i <= m;++i){
			for(int j = i + 1;j <= m;++j){
				if(i == j || i == k || j == k) continue;
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j] - 2 * w[k]);
			}
		}
	}
/*
		for(int i = 1;i <= m;++i){
			for(int j = 1;j <= m;++j){
				printf("%lld ",dis[i][j]);
			}
			printf("\n");
		}
*/
	while(q--){
		scanf("%lld %lld",&x,&y);
		if(x > y) swap(x,y);
		printf("%lld\n",dis[x][y]);
	}
	return 0;
}
