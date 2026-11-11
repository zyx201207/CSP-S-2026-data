#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],dp[500005],maxn=0; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int zrf=0; 
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long cz=a[2]-a[1];
	for(long long i=2;i<=n;i++){
		if(a[i]-a[i-1]!=cz)zrf=1;
	}
	if(zrf==0){
		for(long long i=1;i<=n;i++){
			if((cz+a[i]-a[1])*(i-1)>2*m){
				cout<<i-1;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		dp[i]=dp[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(long long i=1;i<=n;i++){
		long long j,sum=0;
		int f=0;
		for(j=i-1;j>=1;j--){
			if(dp[i]-dp[j]-(j-1)*(a[i]-a[j])>m){
				break;
			}
			else if(dp[i]-dp[j]-(j-1)*(a[i]-a[j])==m){
				f=1;
				break;
			}
			
		}
		if(f==0)j++;
		maxn=max(maxn,i-j+1);
	}
	cout<<maxn;
	return 0;
}







