#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
int dp[310][310];
int cnt[310][310];
int main(){
//	freopen("1.txt","r",stdin);
//	freopen("myout.txt","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			long long n;
			long long d;
			cin>>n>>d;
			if(n<=2){
				long long aaa,bbb;
				cin>>aaa>>bbb;
				cout<<0;
				continue;
			}
			long long aa,bb;
			cin>>aa>>bb;
			for(int i=3;i<=n;i++){
				long long aaaa;cin>>aaaa; 
			}
			long long u=d/(bb-aa);
			if(u<=1){
				cout<<0<<endl;
			}else{
				if(n-2*u+1>0) cout<<n-2*u+1<<endl;
				else cout<<0<<endl;
			}
		}
		return 0;
	}
//	if(c==13||c==14){
//		while(t--){
//			int n,d;
//			cin>>n>>d;
//			if(n<=2){
//				int aaa,bbb;
//				cin>>aaa>>bbb;
//				cout<<0;
//				continue;
//			}
//			int pos=-1;
//			for(int i=1;i<=n;i++){
//				scanf("%lld",&a[i]);
//			}
//			for(int i=1;i<=n;i++){
//				if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
//					pos=i;
//					break;
//				}
//			}
//			if(pos==1||pos==n){
//				cout<<0<<endl;
//				continue; 
//			}
//			
//		}
//		return 0;
//	}	
	if(c<=10){
		while(t--){
			int n;
			long long d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d) dp[i][j]=1;
					else dp[i][j]=1e9;
					cnt[i][j]=1;
				}
			}
//			for(int i=1;i<=n;i++){
//				for(int j=i+1;j<=n;j++) cout<<dp[i][j]<<" ";
//				cout<<endl; 
//			}
			for(int i=2;i<n;i++){
				for(int j=1;j<i;j++){
					if(i==j) continue;
					for(int l=i+1;l<=n;l++){
						if(dp[j][l]>dp[j][i]+dp[i][l]){
							dp[j][l]=dp[j][i]+dp[i][l];
							cnt[j][l]=1; 
						}else if(dp[j][l]==dp[j][i]+dp[i][l]){
							cnt[j][l]++;
						}
					}
				}
			}
//			for(int i=1;i<=n;i++){
//				for(int j=i+1;j<=n;j++) cout<<dp[i][j]<<" ";
//				cout<<endl; 
//			}			
//			for(int i=1;i<=n;i++){
//				for(int j=i+1;j<=n;j++) cout<<cnt[i][j]<<" ";
//				cout<<endl; 
//			}			
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(cnt[i][j]==2) ans++;
				}
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/
