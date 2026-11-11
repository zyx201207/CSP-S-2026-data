#include<bits/stdc++.h>
using namespace std;
long long t;
int op;
int main(){ 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>op>>t;
	while(t--){
//		int n=0,d=0;
//		int a,dp;
//		cin>>n>>d;
//		for(int i=1;i<=n;i++){
//			int x;
//			cin>>x;
//			a[i]=x;
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=i-1;a[j]+d>=a[i]&&j>0;j--){
//				dp[i]=max(dp[i],dp[j]+1);
//			}
//		}
//	cout<<dp[n]<<endl;
		if(op<=10&&op>=1){
			int n,d,ans;
			cin>>n>>d;
			long long a[20],x[20][20];
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					x[i][j]=max(x[i-1][j]+1,x[i][j]);
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(x[j][i]==2){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
		if(op>=11&&op<=12){
			long long n,d;
			cin>>n>>d;
			long long a[2000010/t];
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(d>=(3*(a[2]-a[1]))){
				cout<<1<<endl;
			}else if(d<(3*(a[2]-a[1]))&&d>=2*(a[2]-a[1])){
				cout<<(n+1)/2<<endl;
			}
		}
	}
	return 0;
}
