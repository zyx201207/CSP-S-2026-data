#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n=0,m=0,a[200010]={};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		ll sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	} 
	if(m==1){
		sort(a+1,a+n+1,greater<ll>());
		cout<<a[1];
		return 0;
	}
	if(m==2){
		ll maxn=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}else{
		ll dp[n+10][m+10]={};
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=max(dp[i][j-1],a[j]&a[i]);
			}
		}
		cout<<dp[n][m];
	}
	return 0;
}
