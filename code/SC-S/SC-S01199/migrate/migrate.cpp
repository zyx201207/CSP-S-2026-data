#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5010,M=2e6+10,I=1e17;
int C,t,n,d,ans,x[N],b[N],f[N][N],g[N][N];
#undef int
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	#define int long long
	scanf("%lld%lld",&C,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=I;
				g[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d)f[i][j]=1,g[i][j]=1;
			}
		}
		for(int len=3;len<=n;len++){
			for(int l=1,r=len;r<=n;l++,r++){
				for(int i=l+1;i<r;i++){
					if(f[l][i]==I||f[i][r]==I)continue;
					if(f[l][i]+f[i][r]==f[l][r])g[l][r]+=g[l][i]*g[i][r];
					else if(f[l][i]+f[i][r]<f[l][r])f[l][r]=f[l][i]+f[i][r],g[l][r]=g[l][i]*g[i][r];				
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(f[i][j]!=I&&g[i][j]==2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}