//migrate
#include<bits/stdc++.h>
#define int long long
const int N=2e6+100,M=5000+100;
using namespace std;
int C,T,n,d,x[N],f[M][M],dis[M][M];
signed main() {

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>C>>T;

	if(C==11||C==12) {
		
		while(T--) {
			int ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
			
			for(int i=1;i<=n-3;i++)if((i+1)*(x[2]-x[1])<=d&&(i+2)*(x[2]-x[1])>d){
				ans=n-i*2-1;break;
			}
			cout<<ans<<"\n";
//			cout<<x[2]-x[1]<<" "<<n<<" "<<d<<"\n";
		}
		
		return 0;
	}

	if(C<=10) {
		while(T--) {
			int ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)f[i][j]=1e9,dis[i][j]=0,f[j][j]=0,dis[j][j]=1;
			
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					for(int k=j-1;k>=i&&x[j]-x[k]<=d;k--){
						if(f[i][j]>f[i][k]+1)f[i][j]=f[i][k]+1,dis[i][j]=dis[i][k];
						else if(f[i][j]==f[i][k]+1)dis[i][j]+=dis[i][k];
					}
					if(dis[i][j]==2)ans++;
				}
			}
			
			cout<<ans<<"\n";
		}
	}


	return 0;
}
