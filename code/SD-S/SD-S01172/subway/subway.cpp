#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=505,INF=1e18;
int c,n,m,d,q,w[N];
int a[M][1000],b[M][M],ans[M][M],ans1[M][M],ans2[M][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			b[i][j]=b[j][i]=INF;
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=m;++j){
			ans[i][j]=ans[j][i]=INF;
		}
	}
	int u=-1,v=0;
	for(int i=1;i<=n;++i){
		int k,o=-1;
		scanf("%lld",&k);
		for(int j=1;j<=k;++j){
			int x,y;
			scanf("%lld %lld",&x,&y);
			a[i][x]=y;
			if(u==-1){
				u=y;
			}else{
				if(u!=y){
					v=1;
				}
			}
			if(o!=-1){
				ans[o][x]=ans[x][o]=0;
				ans1[o][x]=ans1[x][o]=a[i][o],ans2[o][x]=ans2[x][o]=a[i][x];
			}
			o=x;
		}
	}
//	if(v==0){
//		cout<<2*u;
//		return 0;
//	}
	for(int i=1;i<=n;++i){
		b[i][i]=0;
	}
	for(int i=1;i<=m;++i) ans[i][i]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i][j]!=0){
				for(int k=1;k<=n;++k){
					if(a[k][j]!=0){
						b[k][i]=b[i][k]=min(b[i][k],a[i][j]+a[k][j]);
					}
				}
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				b[i][j]=min(b[i][j],b[i][k]+b[k][j]); 
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i][j]!=0){
				for(int k=1;k<=n;++k){
					for(int l=1;l<=m;++l){
						if(a[k][l]!=0){
							if(b[i][k]<ans[j][l]){
								ans[j][l]=b[i][k];
								ans1[j][l]=a[i][j],ans2[j][l]=a[k][l];
							}
							if(b[i][k]==ans[j][l]){
								if(ans1[i][l]+ans[i][l]>a[i][j]+a[k][l]){
									ans[j][l]=b[i][k];
									ans1[j][l]=a[i][j],ans2[j][l]=a[k][l];
								}	
							}
						}
					}
				}
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%lld %lld",&x,&y);
		printf("%lld\n",ans[x][y]+ans1[x][y]+ans2[x][y]+w[x]+w[y]);
	}
	return 0;
}

