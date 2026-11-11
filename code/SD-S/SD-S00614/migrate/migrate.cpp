#include<bits/stdc++.h>
using namespace std;
long long t;
long long c;
long long n;
long long d,x[2000010];
long long dp[2000010];
long long dp2[2000010];
long long ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
			dp[i]=0;
			dp2[i]=0;
		}
		dp[1]=0;
		long long i=2;
		while(x[i]-x[1]<=d){
			
			
			
			dp[i]=1;
			dp2[i]=1;
			i++;
		}
		
//		cout<<1<<' ';
		
		for(i;i<=n;i++){
			long long j=i-1;
			long long mn=LLONG_MAX;
			long long a=0;
			long long zx[200010];
//			cout<<2<<' ';
			while((x[i]-x[j])<=d){
				if(dp[j]<mn){
					a=1;
					zx[a]=j;
					mn=dp[j];
				}else if(dp[j]==mn){
					a++;
					zx[a]=j;
				}
				j--;
			}
			
//			cout<<3<<' ';
			
			if(mn==LLONG_MAX)dp[i]=0;
			else dp[i]=mn+1;
			
			
//			cout<<a<<endl;
			
			for(int k=1;k<=a;k++){
				
//				cout<<zx[k]<<' ';
				
				dp2[i]+=dp2[zx[k]];
			}
			
//			cout<<endl;
			
//			cout<<4<<' ';
			
			if(dp2[i]==2){
				ans++;
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<dp[i]<<' ';
//		}cout<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<dp2[i]<<' ';
//		}cout<<endl;
		
		cout<<ans<<endl;
	}
	
	return 0;
}

