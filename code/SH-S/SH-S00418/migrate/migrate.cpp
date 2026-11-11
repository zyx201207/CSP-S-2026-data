#include <bits/stdc++.h>
using namespace std;

int c,t;
long long n,d;
long long x[2000050];
int dp[2000050]; 
int dp2[2000050];

long long A(){
	long long num=d/(x[1]-x[0]);
	if(num>1) return max(n-2*num+1,0ll);
	return 0;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=0;i<n;i++) scanf("%lld",&x[i]);
		long long ans=0;
		long long num=x[1]-x[0];
		bool flag=1;
		for(int i=1;i<n-1;i++) if(x[i+1]-x[i]!=num){flag=0;break;}
		if(flag){
			cout<<A()<<"\n";
			continue;
		}
		for(int i=0;i<n;i++){
			fill(dp,dp+n,1e8);
			fill(dp2,dp2+n,1);	
			dp[i]=0,dp2[i]=1;
			for(int j=i+1;j<n;j++){
				for(int k=j-1;k>=i && x[j]-x[k]<=d;k--){
					if(dp[k]+1<dp[j]){
						dp[j]=dp[k]+1;
						dp2[j]=dp2[k];
					}else if(dp[k]+1==dp[j]) dp2[j]+=dp2[k];
				}
			}
			for(int j=i+1;j<n;j++){
//				cout<<j<<" "<<dp[j]<<" "<<dp2[j]<<endl;
				if(dp2[j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
