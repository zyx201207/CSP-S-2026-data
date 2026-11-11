#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,len;
long long a[200005],dp[5005][5005];
vector<int>g[5005];
void dfs(int x,int y,int len1){
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
 	cin>>c>>t;
 	if(c>=15&&c<=18){
 		while(t--){break;
 			cin>>n>>d;
 			for(int i=1;i<=n;i++)cin>>a[i];
 			for(int i=2;i<n;i++){
 				if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
 					cout<<(i-1)*(n-i)<<endl;break;
				 }
			 }
		 }
	 }
 	while(t--){
 		scanf("%lld%lld",&n,&d);
 		for(int i=1;i<=n;i++){
 			scanf("%lld",&a[i]);
		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;a[j]-a[i]<=d&&j<=n;j++){
//				g[i].push_back(j);
//			}
//		}
		for(int i=1;i+1<=n;i++)if(a[i+1]-a[i]<=d)dp[i][i+1]=1;
		long long ans=0;
		for(int len=3;len<=n;len++){
			for(int i=1;i+len-1<=n;i++){
				int j=i+len-1;
				dp[i][j]=10000114517;
				long long minn=10000000000;
				
				for(int k=i;k<=j;k++){
					if(a[k]-a[i]<=d){
						if(minn>dp[i][k]+dp[k][j]){
							dp[i][j]=0;
							minn=dp[i][k]+dp[k][j];
						}
						if(minn=dp[i][k]+dp[k][j]){
							dp[i][j]++;
						}
					}
				}
				if(dp[i][j]==2&&minn<=9090000000){
				ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 



