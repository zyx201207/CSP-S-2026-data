#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e3+5;
int c,n,m,d,q,w[M],a[M][M],t[M][M],k[M];
vector<int> mp[M];
int ans[M][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld",&a[i][j]);
			scanf("%lld",&t[i][a[i][j]]);
			mp[a[i][j]].push_back(i);
		}
	}
	memset(ans,0x3f,sizeof ans);
	for(int i=1;i<=m;i++){
		for(int j=0;j<mp[i].size();j++){
			for(int kk=0;kk<j;kk++){
				int p1=mp[i][j];
				int p2=mp[i][kk];
				for(int t1=1;t1<=k[p1];t1++){
					for(int t2=1;t2<=k[p2];t2++){
						int l=a[p1][t1],r=a[p2][t2];
						if(l==i&&r!=i){
							ans[l][r]=min(ans[l][r],w[l]+t[p2][l]+t[p2][r]+w[r]);
							ans[r][l]=min(ans[r][l],w[l]+t[p2][l]+t[p2][r]+w[r]);
						}else if(l!=i&&r==i){
							ans[l][r]=min(ans[l][r],w[l]+t[p1][l]+t[p1][r]+w[r]);
							ans[r][l]=min(ans[r][l],w[l]+t[p1][l]+t[p1][r]+w[r]);
						}else if(l==i&&r==i){
							ans[l][r]=0;
						}else{
							ans[l][r]=min(ans[l][r],w[l]+w[r]+t[p1][l]+t[p2][r]+t[p1][i]+t[p2][i]);
							ans[r][l]=min(ans[r][l],w[l]+w[r]+t[p1][l]+t[p2][r]+t[p1][i]+t[p2][i]);
						}
					}
				}
			}
		}
	}
	while(q--){
		int l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",ans[l][r]);
	}
	return ~(-1);
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/