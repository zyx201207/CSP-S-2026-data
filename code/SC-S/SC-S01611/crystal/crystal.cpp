#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long ans=n;
	for(long long i=n-1;i>=0;i--){
		long long sum=a[i]*i;
		for(long long j=0;j<i;j++){
			sum-=a[j];
		}
		if(sum<=m){
			cout<<ans;
			return 0;
		}
		else{
			ans--;
		}
	}
	return 0;
} 