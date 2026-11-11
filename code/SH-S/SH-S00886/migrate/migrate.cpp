#include <bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d,cnt=0;cin>>n>>d;
		int a[1010],dp[1010];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=1;j<=n;j++){
			int s=a[j];
			for(int k=1;k<=n;k++){
				if(a[k]>=s-d && a[k]<=s+d)dp[k]=1;
			}
			for(int k=s;k<=n;k++){
				if(!dp[k]){
					for(int l=j;l<=k;l++){
						if(a[l]>=k-d){
							dp[k]+=dp[l];
							//cout<<l<<" ";
						}
					}
					if(dp[k]==2)cnt++;
				}
			}
			for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
			cout<<cnt;
		}
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
