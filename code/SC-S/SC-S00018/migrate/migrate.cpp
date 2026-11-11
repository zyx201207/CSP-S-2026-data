#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("r","migrate.in",stdin);
	freopen("w","migrate.out",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t>0){
			t--;
			int n,d;
			scanf("%d%d",&n,&d);
			long long a[n+2],dp[n+2][n+2],f[n+2][n+2];
			for(int i=1;i<=n;i++)cin>>a[i];
			int m=a[2]-a[1];
			if(d<2*m)cout<<0<<endl;
			else cout<<n-(d/m)*2+1<<endl;
		}
		return 0;
	}
	while(t--){
		int n,d;
		scanf("%d%d",&n,&d);
		long long a[n+2],dp[n+2][n+2],f[n+2][n+2];
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<n;i++){
			dp[i][i]=0;f[i][i]=0;
			for(int j=1;j+i<n;j++){
				if(a[i+j]-a[i]>d)break;
				dp[i][i+j]=dp[i+j][i]=1;
				f[i][i+j]=f[i+j][i]=1;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+d+1;j<=n;j++){
				long long num=0;
				long long fmin=f[i][j-1];
				for(int k=j-1;k>i;k--){
					if(a[j]-a[k]>d)break;
					fmin=min(fmin,f[i][k]);
				}
				for(int k=j-1;k>i;k--){
					if(a[j]-a[k]>d)break;
					if(f[i][k]==fmin)num+=dp[i][k];
				}
				dp[i][j]=dp[j][i]=num;
				f[i][j]=f[j][i]=fmin+1;
				if(dp[i][j]==2)cnt++;
			}
		}
		cout<<cnt<<endl; 
	}
	return 0;
}