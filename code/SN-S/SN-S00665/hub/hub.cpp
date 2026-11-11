#include<bits/stdc++.h>
using namespace std;
#define lint long long
struct node{
	lint mi;
	lint z;
};
lint a[200005],c,t,n,m;
node dp[200005];
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		lint ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dp[j]=0;
			}
			dp[i].z=1;
			dp[i].mi=0;
			for(int j=i+1;j<=n;j++){
//				cout<<j<<endl; 
				if(j-i>=3 && a[j]-a[j-3]>=0){
					break;
				} 
				else{
					if(a[j]-a[j-1]>=0){
						dp[j]+=dp[j-1]; 
					}
					if(j-i>=2 && a[j]-a[j-2]>=0){
						dp[j]+=dp[j-2];
					}
				}
				if(dp[j]>=3 || dp[j]==0){
					break;
				}
			}
			for(int j=i;j<=n;j++){
				cout<<dp[j]<<endl;
				if(dp[j]==2){
					ans++;
				} 
				if(dp[j]>=3 || dp[j]==0){
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
