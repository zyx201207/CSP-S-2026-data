#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;
int n;
long long m,t;
long long c[500005];
long long a[500005]; 
long long d[500005];
long long b[500005];
int ans,dp[500005];//以i为结尾的宝石最大数量 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		b[i]=c[i]+b[i-1];
	}
	for(int i=2;i<=n;i++){
		d[i]=d[i-1]+b[i];
	}
	dp[1]=1;
	for(int i=2;i<=n;i++){
		if(b[i]*dp[i-1]-d[i-1]+d[i-dp[i-1]-1]<=m){
			dp[i]=dp[i-1]+1;
		}
		else{
			for(int j=1;j<=dp[i-1];j++){
				if(b[i]*(dp[i-1]-j)-d[i-1]+d[i-dp[i-1]-j-1]<=m){
					dp[i]=dp[i-1]-j;
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
