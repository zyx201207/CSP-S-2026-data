#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,C,T,x[2000005],f[500][500],ans[500][500],g[500][500];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--){
		int p=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=1e18;
				g[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					f[i][j]=f[j][i]=1;
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(f[i][j]>f[i][k]+f[k][j]){
						f[i][j]=f[i][k]+f[k][j];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans[i][j]=f[i][j];
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(f[i][k]+f[k][j]==ans[i][j]){
						g[i][j]++;
					}
					if(f[i][j]>f[i][k]+f[k][j]){
						f[i][j]=f[i][k]+f[k][j];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(g[i][j]==2){
					p++;
				}
			}
		}
		printf("%lld\n",p);
	}
	return 0;
}
