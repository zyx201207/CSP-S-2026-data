#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=600;
int c,n,m,d,q,w[N],a[N][N],t[N][N],k,x,y,v[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld",&a[i][j]);
			scanf("%lld",&t[i][j]);
			v[a[i][j]][i]=1;
		}
	}
	while(q--){
		int ans=LONG_LONG_MAX;
		scanf("%lld%lld",&x,&y);
		for(int i=1;i<=n;i++){
			for(int i1=1;i1<=n;i1++){
				for(int j=1;j<=m;j++)
					if(v[x][i]&&v[j][i]&&v[y][i1]&&v[j][i1]){
						ans=min(ans,t[i][x]+t[i1][y]+t[i][j]+t[i1][j]);
					}
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
} 
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
