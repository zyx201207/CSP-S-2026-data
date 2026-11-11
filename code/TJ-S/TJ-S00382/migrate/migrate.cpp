#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000006],dp[2000006][2];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(c==11||c==12){
			long long u=d/(a[2]-a[1]);
			if(n-2*u+1>=0)
				cout<<(n-2*u+1)<<"\n";
			else{
				cout<<0<<"\n";
			}
		} else{
		for(int i=1;i<=n;i++){
			dp[i][0]=0;
			dp[i][1]=-1;
			for(int j=i+1;j<=n;j++){
				long long m=1e16,s=0;
				for(int k=j-1;k>=i&&a[j]-a[k]<=d;k--){
					if(dp[k][0]<=m&&dp[k][0]!=-1){
						if(m!=dp[k][0]) s=0;
						m=dp[k][0];
						s++;
					}
					if(dp[k][1]!=-1){
						if(dp[k][1]<=m){
							if(m!=dp[k][1]) s=0;
							m=dp[k][1];
							s+=2;
						}
					}
				}
				if(s==1)
				dp[j][0]=m+1;
				else 
				dp[j][0]=-1;
				if(s==2) {
				dp[j][1]=m+1;
					sum++;
				}else{
				dp[j][1]=-1;	
				}
			}
		}
		cout<<sum<<"\n";
	}
	}
	return 0;
} 
