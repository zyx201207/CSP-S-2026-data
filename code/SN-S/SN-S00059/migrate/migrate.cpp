#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	ofstream cout("migrate.out");
	ifstream cin("migrate.in");
	cin>>c>>t;
	while(t--){
		int n,r;
		cin>>n>>r;
		long long a[5002];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		long long dp[502][502];
		for(int i=0;i<n+1;i++){
			for(int j=0;j<n+1;j++){
				dp[i][j]=0;
			}
		}
		
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int l=lower_bound(a+i,a+n,a[j]-r)-a;
				for(int k=l;k<j;k++){
					dp[i][j]+=(dp[i][k]==0?1:dp[i][k]);
					if(dp[i][k]<dp[i][k+1]){
						break;
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dp[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
