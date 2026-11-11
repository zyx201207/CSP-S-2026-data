#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,sum,a[2000006],dp[2000006];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		//int i=1,j=n;
		//while(i<j){
		//	int ans=0;
		//	int c=a[j]-a[i];
		//	if(c/d<=d){
		//		ans++;
		//	}
		//	if(ans==2){
		//		sum++;
		//	}
		//	i++;j--;
		//}
		//cout<<sum;
		dp[1]=0;dp[2]=1;
		for(int i=3;i<=n;i++){
			dp[i]=dp[i-d+1]+dp[i-d];
		} 
		if(dp[n]==2){
		sum++;
		}
		cout<<sum;
	}
	return 0;	
}
