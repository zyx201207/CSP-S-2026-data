#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n-1;i>=1;i--){
		sum[i]=sum[i+1]+a[n]-a[i];
	}
	long long ma=-1;
	for(int i=1;i<=n;i++){
	int l=1,r=i-1;
	while(l<r){
		int mid=(l+r)/2;
		long long tot=sum[mid]-sum[i+1]-(i-mid+1)*(a[n]-a[i]);
		if(tot<=m)r=mid;
		else l=mid+1;
	}
	if(ma<i-l+1)ma=i-l+1;
	}
	cout<<ma;
	return 0;
} 
