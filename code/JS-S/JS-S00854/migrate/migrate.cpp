#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[5009],f[5002][5002],sum[5002][5002];
int q[5002];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//~ freopen("migrate4.in","r",stdin);
	//~ freopen("migrate4.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;++i) scanf("%lld",&x[i]);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				f[i][j]=0;
				sum[i][j]=0;
			}
		}
		for(int i=1;i<=n;++i){
			sum[i][i]=1;
			f[i][i]=0;
			for(int j=1;j<=n;++j){
				q[j]=0;
			}
			int l=1,r=1;
			q[l]=i;
			for(int j=i+1;j<=n;++j){
				while(l<=r&&x[j]-x[q[l]]>d) ++l;
				if(l<=r){
					f[i][j]=f[i][q[l]]+1;
					for(int k=l;k<=min(r,l+2);++k){
						//~ cout<<q[k]<<' '<<x[j]<<' '<<x[q[k]]<<endl;
						if(f[i][j]-1==f[i][q[k]]) sum[i][j]+=sum[i][q[k]];
					}
					//~ cout<<endl;
					//~ cout<<i<<' '<<j<<":"<<sum[i][j]<<' '<<f[i][j]<<endl;
				}
				q[++r]=j;
				while(l<=r&&f[i][j]<f[i][q[r]]) --r;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(sum[i][j]==2) ++ans;
			}
		}
		printf("%lld\n",ans);		
	}
	return 0;
}
