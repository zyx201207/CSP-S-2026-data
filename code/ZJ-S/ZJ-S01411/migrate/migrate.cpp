#include <bits/stdc++.h>
using namespace std;
const int N=3e2+100;
long long c,t,n,d,x[N],dp[N][N],o,k[N],qian[N][N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<n;i++){
			dp[i][0]=1;
			for(int j=i;j<=n;j++) qian[j][0]=1;
			for(int z=1;z<=n;z++){
				long long lt=i;
				for(int j=i+1;j<=n;j++){
					while(x[j]-x[lt]>d) lt++;
					dp[j][z]+=qian[j][z-1]-qian[lt-1][z-1];
//					for(int lt=j-1;lt>=i;lt--){
//						if(abs(x[j]-x[lt])<=d) dp[j][z]+=dp[lt][z-1];
//					}
					qian[j][z]=qian[j-1][z]+dp[j][z];
				}
			}
			for(int j=1;j<=n;j++) k[j]=1;
			for(int ct=1;ct<=n;ct++){
				for(int z=i+1;z<=n;z++){
					if(dp[z][ct]>=1){
						if((dp[z][ct]==2)&&(k[z])){
							ans++;
						}
						k[z]=false;
					}
				}
			}
			for(int j=0;j<=n;j++){
				for(int z=0;z<=n;z++){
					dp[j][z]=0;
					qian[j][z]=0;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}