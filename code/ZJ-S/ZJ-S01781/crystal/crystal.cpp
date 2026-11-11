#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[500005];;
int dp[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=1;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	bool f=1;
	for(int i=3;i<=n;i++){
		if(d[i]!=d[i-1]){
			f=0;	
		}
	}
	if(f==1){
		for(int i=1;i<=n;i++){
			long long k=i;
			k*=(i+1);
			k*=d[2];
			k/=2;
			if(k>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
	}else{
		for(int i=n;i>=2;i--){
			long long mm=m;
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=mm){
					mm-=(a[i]-a[j]);
					dp[i]++;
				}
			}
		}
		int maxn=INT_MIN;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,dp[i]);
		}
		cout<<maxn;	
	}
	return 0;
}
