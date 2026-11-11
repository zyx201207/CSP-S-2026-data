#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],dp[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dp[0]=1;
	sort(a,a+n);
	if(m>100000000){
		if(m>=(a[1]-a[0])*(n-1))
			cout<<n;
		else{
			long long p=1;
			while(m>(a[1]-a[0])*p){
					p++;
			}
			cout<<p-1;
		}
		return 0;
	}
	long long sum=0;
	for(int i=1;i<n;i++){
		long long y=m,k=i-1;
		sum=1;
		while(y>=(a[i]-a[k]) and k>=0){
			sum++;
			y-=(a[i]-a[k]);
			k--;
		}
		dp[i]=max(dp[i-1],sum);
	}
	cout<<dp[n-1];
	return 0;
} 
