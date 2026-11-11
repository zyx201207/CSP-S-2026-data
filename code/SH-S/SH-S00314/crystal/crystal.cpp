#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(long long i=1;i<n;i++)
	for(long long j=i+1;j<=n;j++)
	if(sum[j]-sum[i]-(a[j]-a[i])*(i-1)<=m)
	ans=max(ans,j-i+1);
	cout<<ans;
	return 0;
} 
