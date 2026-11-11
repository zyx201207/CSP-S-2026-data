#include<bits/stdc++.h>
using namespace std;
struct abc{
	long long x,y;
}dp[200010][2];
long long n,m,a[200010],v[10000010];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][1].x=dp[i][0].x=1;
		dp[i][1].y=dp[i][0].y=0;
		maxx=max(maxx,a[i]);
	}
	for(int i=1;i<=maxx;i++){
		v[i]=0;
	}
	sort(a+1,a+n+1,cmp);
	long long ans=a[1];
	for(int i=1;i<=m;i++){
		if(v[i]!=0){
			m++;
		}
		else{
			ans&=a[i];
			v[i]=1;
		}
	}
	cout<<ans<<endl;
//	dp[1][1].x=a[1];
//	dp[1][1].y=1;
//	dp[1][0].x=1;
//	dp[1][0].y=0;
//	for(int i=2;i<=n;i++){
//		int st=0;
//		if(dp[i-1][1].x&a[i]>dp[i-1][0].x&a[i]){
//			st=dp[i-1][1].y;
//			if(st+1>m){
//				if(dp[i-1][0].y+1<=m)dp[i][1].x=max(a[i],dp[i-1][0].x&a[i]),dp[i][1].y=dp[i-1][0].y+1;
//				else  dp[i][0].x=1,dp[i][1].x=a[i],dp[i][0].y=0,dp[i][1].y=1;
//			} 
//			else{
//				dp[i][1].x=max(a[i],dp[i-1][1].x&a[i]),dp[i][1].y=dp[i-1][1].y+1;
//			}
//		}
//		else if(dp[i-1][1].x&a[i]<dp[i-1][0].x&a[i]){
//			st=dp[i-1][0].y;
//			if(st+1>m){
//				if(dp[i-1][1].y+1<=m)dp[i][1].x=max(a[i],dp[i-1][1].x&a[i]),dp[i][1].y=dp[i-1][1].y+1;
//				else  dp[i][0].x=1,dp[i][1].x=a[i],dp[i][0].y=0,dp[i][1].y=1;
//			} 
//			else{
//				dp[i][1].x=max(a[i],dp[i-1][0].x&a[i]),dp[i][1].y=dp[i-1][0].y+1;
//			}
//		}
//		else{
//			st=min(dp[i-1][0].y,dp[i-1][1].y);
//			if(st+1>m) dp[i][0].x=1,dp[i][1].x=a[i],dp[i][0].y=0,dp[i][1].y=1;
//			else{
//				if(dp[i-1][0].y==st){
//					dp[i][1].x=max(a[i],dp[i-1][0].x&a[i]),dp[i][1].y=st+1;
//				}
//				else{
//					dp[i][1].x=max(a[i],dp[i-1][1].x&a[i]),dp[i][1].y=st+1;
//				}
//			}
//		}
//		if(dp[i-1][0].x>=dp[i-1][1].x){
//			dp[i][0].x=max(dp[i-1][0].x,dp[i][0].x);
//			dp[i][0].y=dp[i-1][0].y;
//		}
//		else{
//			dp[i][0].x=max(dp[i-1][1].x,dp[i][0].x);
//			dp[i][0].y=dp[i-1][1].y;
//		}
//	}
//	cout<<max(dp[n][0].x,dp[n][1].x)<<endl;
	return 0;
}

