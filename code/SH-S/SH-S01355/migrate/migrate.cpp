#include<bits/stdc++.h>
using namespace std;

long long c, t, n, d, a[2000005], dp[2000005], tr[2000005];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin>>c>>t;
	
	while(t--){
		cin>>n>>d;
		long long ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			if(a[i+1]-a[i]>d) continue;
			dp[i]=1; tr[i]=0;
			dp[i+1]=1; tr[i+1]=1;
			for(int j=i+2;j<=n;j++){
				if(a[j]-a[j-1]>d) break;
				long long mindp=2147483647, mintr=2147483647;
				int k=j-1;
				while(a[j]-a[k]<=d&&k>=i){
					if(dp[k]<mindp){
						mindp=dp[k];
					}
					--k;
				}
				k=j-1;
				while(a[j]-a[k]<=d&&k>=i){
					if(dp[k]==mindp) if(tr[k]<mintr) mintr=tr[k];
					--k;
				}
				
				tr[j]=mintr+1; k=j-1; dp[j]=0;
				while(a[j]-a[k]<=d&&k>=i){
					if(tr[k]==mintr) dp[j]++;
					--k;
				}
				
				if(dp[j]==2) {
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
