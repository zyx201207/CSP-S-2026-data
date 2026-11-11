#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[500005],sum[500005];//dp[i]:第i为结尾最大的序列个数 
int n,m,a[500005];
bool cmp(int a,int b){
	return a<b;
}
signed main(){
	freopen("crystal.in","r",stdin);//刚刚写的是“crystal4” 
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=-1e18;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+1;
		sum[i]=sum[i-1]+(dp[i-1]*(a[i]-a[i-1]));
		while(sum[i]>m){
			sum[i]-=a[i]-a[i-dp[i]];
			dp[i]--;
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;
}
//15:19过T1，并发现差点cos anyu（forgotten_freopen） 

/*
洛谷大佬你好，我要上迷惑行为大赏
洛谷关注meiweid_quanyiang谢谢哦 
*/ 
